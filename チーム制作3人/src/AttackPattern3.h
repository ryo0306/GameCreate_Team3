#pragma once
#include "ScreenMake.h"
#include "AttackPatternBase.h"
#define PATTERN3_SIZE_WIDTH 7
#define PATTERN3_SIZE_HEIGHT 7

//TODO:àÍÇ¬ÇÃçUåÇÇ…àÍÇ¬ÇÃÉNÉâÉXÅH
const int pattern3[7][7]
{
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1 },
};

class AttackPattern3 :public AttackPatternBase
{
public:

  int GetMapData(int x, int y){ return pattern3[x][y]; };

  Vec2i GetSize(){ return Vec2i(PATTERN3_SIZE_WIDTH, PATTERN3_SIZE_HEIGHT); }

  Vec2i GetPos(Vec2i pos_){ return Vec2i(pos_.x() - int(PATTERN3_SIZE_WIDTH / 2), pos_.y() - int(PATTERN3_SIZE_HEIGHT/ 2)); }

private:



};