#include "CollisionMap.h"

void CollisionMap::SetMapData(int pattern_, Vec2i player_pos_)
{
  switch (pattern_)
  {
  case 0:
    collison_map_data = new AttackPatternBase();
   
    break;
  case 1:
    collison_map_data = new AttackPattern1();
    //  ‰ŠúˆÊ’u‚ÌC³
    pos_ = collison_map_data->GetPos(player_pos_);
    break;
  case 2:
    collison_map_data = new AttackPattern2();
    //  ‰ŠúˆÊ’u‚ÌC³
    pos_ = collison_map_data->GetPos(player_pos_);
    break;
  case 3:
    collison_map_data = new AttackPattern3();
    //  ‰ŠúˆÊ’u‚ÌC³
    pos_ = collison_map_data->GetPos(player_pos_);
    break;
  default:
    break;
  }

  pos_ = collison_map_data->GetPos(player_pos_);

  ChangeMapDirection();

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


void CollisionMap::ChangeMapDirection()
{
  switch (attack_direction)
  {
  case Direction::UP:
    UpIterator();
    break;
  case Direction::RIGHT:
    RightIterator();
    break;
  case Direction::DOWN:
    DownIterator();
    break;
  case Direction::LEFT:
    LeftIterator();
    break;
  default:
    break;
  }
}

void CollisionMap::Reset()
{
  for (int x = 0; x < MapSize::WIDTH; x++)
  {
    for (int y = 0; y < MapSize::HEIGHT; y++)
    {
      collison_map[x][y] = 0;
    }
  }
}


void CollisionMap::UpIterator()
{
  //‚ ‚½‚è”»’è‚Ìî•ñ‚ðcollisionmap‘ã“ü
  x_ = 0;
  for (int x = pos_.x(); x < pos_.x() + collison_map_data->GetSize().x(); x++)
  {
    if (x >= MapSize::WIDTH || x < 0)
    {
      x_++;
      continue;
    }
    y_ = 0;
    for (int y = pos_.y() + collison_map_data->GetSize().y() - 1; y >= pos_.y(); y--)
    {

      if (y >= MapSize::HEIGHT || y < 0)
      {
        y_++;
        continue;
      }
      collison_map[x][y] = collison_map_data->GetMapData(x_, y_);
      y_++;

    }

    x_++;
  }
}


bool CollisionMap::Check(Vec2i boss_pos_)
{ 
  if (collison_map[boss_pos_.x()][boss_pos_.y()] == 1)
  {
    return true;
  }
  return false;
}