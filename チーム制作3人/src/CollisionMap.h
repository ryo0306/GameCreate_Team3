#pragma once
#include "AttackPattern1.h"
#include "AttackPattern2.h"
#include "AttackPattern3.h"
#include "Map.h"
#include "Struct.h"

class CollisionMap
{
public:
  void SetMapData(int pattern_, Vec2i player_pos_);
  void Draw();
  void Reset();
  bool Check(Vec2i boss_pos_);

  // �����ɂ����for���̉�d����ς���
  void ChangeMapDirection();

  void UpIterator();
  void RightIterator(){};
  void DownIterator(){};
  void LeftIterator(){};

private:
  int collison_map[MapSize::WIDTH][MapSize::HEIGHT];
  AttackPatternBase* collison_map_data;
  //for���p�C�e���[�^
  int x_ = 0;
  int y_ = 0;
  Vec2i pos_;   // player�̈ʒu
  Direction attack_direction = Direction::UP;
};