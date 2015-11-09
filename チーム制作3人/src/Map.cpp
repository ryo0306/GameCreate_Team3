#include "Map.h"


void Map::ReadFile(const std::string& file_)
{


  std::fstream ifs(file_);

  //ÉtÉ@ÉCÉãì«Ç›çûÇ›é∏îsÇµÇΩÇÁ
  assert(ifs);

  std::string row;
  
  int y = MapSize::HEIGHT-1;
  while (std::getline(ifs, row)){
    int x = 0;
    for (auto map : row){
     
      if (map == '0')
        stage[x][y] = MapObject::NONE;
      else if (map == '1')
        stage[x][y] = MapObject::WALL;
      else
        stage[x][y] = MapObject::NONE;
      x += 1;
    }
    y -= 1;
  }
}

void Map::Draw()
{
  for (int x = 0; x < MapSize::WIDTH; x++)
  {
    for (int y = 0; y < MapSize::HEIGHT; y++)
    {
      switch (stage[x][y])
      {
      case MapObject::NONE:
        drawFillBox(x*MAPCHIP_SIZE - WINDOW_WIDTH / 2,
                    y*MAPCHIP_SIZE - WINDOW_HEIGHT / 2,
                    MAPCHIP_SIZE, MAPCHIP_SIZE,
                    Color::white);
          break;
        case MapObject::WALL:
          drawFillBox(x*MAPCHIP_SIZE - WINDOW_WIDTH / 2,
                      y*MAPCHIP_SIZE - WINDOW_HEIGHT / 2,
                      MAPCHIP_SIZE, MAPCHIP_SIZE,
                      Color::lime);
          break;
        case MapObject::DAMEGE:
          drawFillBox(x*MAPCHIP_SIZE - WINDOW_WIDTH / 2,
                      y*MAPCHIP_SIZE - WINDOW_HEIGHT / 2,
                      MAPCHIP_SIZE, MAPCHIP_SIZE,
                      Color::purple);
          break;
      default:
        break;
      }
      drawBox(x*MAPCHIP_SIZE - WINDOW_WIDTH / 2,
                  y*MAPCHIP_SIZE - WINDOW_HEIGHT / 2,
                  MAPCHIP_SIZE, MAPCHIP_SIZE,
                  5,frame_color[x][y]);
    }
  }
}

void Map::Edit(const std::string& file_)
{
  Vec2f mouse_pos = env.mousePosition();


  for (int x = 0; x < MapSize::WIDTH; x++)
  {
    for (int y = 0; y < MapSize::HEIGHT; y++)
    {
      if (Collision(Vec2f(mouse_pos.x() + WINDOW_WIDTH / 2, mouse_pos.y() + WINDOW_HEIGHT / 2), Vec2f(x*MAPCHIP_SIZE, y*MAPCHIP_SIZE),
        Vec2f(1, 1), Vec2f(MAPCHIP_SIZE, MAPCHIP_SIZE)))
      {
        ChangeMap(x, y);
        frame_color[x][y] = Color::red;
      }
      else
      {
        frame_color[x][y] = Color::black;
      }
    }
  }

  if (env.isPressKey(GLFW_KEY_LEFT_CONTROL) && env.isPushKey(GLFW_KEY_S))
  {
    std::fstream ofs(file_, std::ios::out);
    if (ofs.fail())
      assert(1);

    for (int y = MapSize::HEIGHT-1; y >= 0; y--)
    {
      for (int x = 0; x < MapSize::WIDTH; x++)
      {
        if (stage[x][y] == 0)
        ofs << "0";
        if (stage[x][y] == 1)
          ofs << "1";
        if (stage[x][y] == 2)
          ofs << "2";
      }
      ofs << std::endl;
    }
  }
}

void Map::ChangeMap(int x_, int y_)
{
  if (env.isPushButton(Mouse::LEFT))
  {
    stage[x_][y_] += 1;
  }

  if (stage[x_][y_] > OBJECT_NUM-1)
  {
    stage[x_][y_] = 0;
  }
}