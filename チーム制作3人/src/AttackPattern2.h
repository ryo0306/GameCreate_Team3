#pragma once
#include "ScreenMake.h"
#include "AttackPatternBase.h"
#define PATTERN2_SIZE_WIDTH 5
#define PATTERN2_SIZE_HEIGHT 10 

//TODO:àÍÇ¬ÇÃçUåÇÇ…àÍÇ¬ÇÃÉNÉâÉXÅH
const int pattern2[5][10]
{
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

class AttackPattern2 :public AttackPatternBase
{
public:

  int GetMapData(int x, int y){ return pattern2[x][y]; };

  Vec2i GetSize(){ return Vec2i(PATTERN2_SIZE_WIDTH, PATTERN2_SIZE_HEIGHT); }

  Vec2i GetPos(Vec2i pos_){ return Vec2i(pos_.x() - int(PATTERN2_SIZE_WIDTH / 2), pos_.y()); }

private:



};