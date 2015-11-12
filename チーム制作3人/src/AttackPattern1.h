#pragma once
#include "ScreenMake.h"
#include "AttackPatternBase.h"
#define PATTERN1_SIZE_WIDTH 5
#define PATTERN1_SIZE_HEIGHT 5 

//TODO:ˆê‚Â‚ÌUŒ‚‚Éˆê‚Â‚ÌƒNƒ‰ƒXH
const int pattern1[5][5] =
{
  { 1, 0, 0, 0, 0 },
  { 1, 1, 1, 0, 0 },
  { 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0 },
  { 1, 0, 0, 0, 0 },
};

class AttackPattern1 :public AttackPatternBase
{
public:

  int GetMapData(int x, int y){ return pattern1[x][y]; };

  Vec2i GetSize(){ return Vec2i(PATTERN1_SIZE_WIDTH, PATTERN1_SIZE_HEIGHT); }
  
  Vec2i GetPos(Vec2i pos_){ return Vec2i(pos_.x() - int(PATTERN1_SIZE_WIDTH / 2), pos_.y()); }

private:



};