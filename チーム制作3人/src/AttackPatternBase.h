#pragma once
#include "ScreenMake.h"

class AttackPatternBase
{
public:
  virtual int GetMapData(int x, int y){ return 0; };

  virtual Vec2i GetSize(){ return Vec2i(0, 0); }

  virtual Vec2i GetPos(Vec2i pos_){ return pos_; }

private:


};