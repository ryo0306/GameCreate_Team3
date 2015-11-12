#include "CollisionMap.h"

void CollisionMap::SetMapData(int pattern_, Vec2i player_pos_)
{
  switch (pattern_)
  {
  case 1:
    collison_map_data = new AttackPattern1();
    pos_ = collison_map_data->GetPos(player_pos_);
    break;
  case 2:
    collison_map_data = new AttackPattern2();
    pos_ = collison_map_data->GetPos(player_pos_);
    break;
  case 3:
    break;
  default:
    break;
  }


  x_ = 0;
  for (int x = pos_.x(); x < pos_.x() + collison_map_data->GetSize().x(); x++)
  {
    y_ = 0;
    for (int y = pos_.y() + collison_map_data->GetSize().y()-1; y >= pos_.y(); y--)
    {
      collison_map[x][y] = collison_map_data->GetMapData(x_,y_);
      y_++;
    }
    x_++;
  }

}


void CollisionMap::Draw()
{
  for (int x = 0; x < MapSize::WIDTH; x++)
  {
    for (int y = 0; y < MapSize::HEIGHT; y++)
    {
      switch (collison_map[x][y])
      {
      case 0:
        // do nothing
        break;
      case 1:
        drawFillBox(x*MAPCHIP_SIZE - WINDOW_WIDTH / 2,
                    y*MAPCHIP_SIZE - WINDOW_HEIGHT / 2,
                    MAPCHIP_SIZE, MAPCHIP_SIZE,
                    Color(1, 0, 0, 0.2f));
        break;
      default:
        break;
      }

    }
  }
}

void CollisionMap::Reset()
{
}