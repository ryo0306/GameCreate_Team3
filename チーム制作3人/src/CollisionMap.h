#pragma once
#include "AttackPattern1.h"
#include "AttackPattern2.h"
#include "Map.h"

class CollisionMap
{
public:
  void SetMapData(int pattern_, Vec2i player_pos_);
  void Draw();
  void Reset();
private:
  int collison_map[MapSize::WIDTH][MapSize::HEIGHT];
  AttackPatternBase* collison_map_data;
  //for文用イテレータ
  int x_ = 0;
  int y_ = 0;
  Vec2i pos_;   // playerの位置
};