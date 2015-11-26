#pragma once
#include "ScreenMake.h"
#include "Map.h"
#include "Player.h"
#include "Boss.h"
#include "CollisionMap.h"





enum Turn
{
  PLAYER,
  ENEMY,
};

class TurnManager
{
public:
  TurnManager()
  {
    SetUp();
  }

  void SetUp();

  void PlayerTurn();

  void PlayerDraw(int i);

  void EnemyDraw();

  void EnemyTurn();
  
  void Total();

  void Draw();

  //DEBUG:
  void DebugDraw();

  void SetCollisonMap(Vec2i pos_, int pattern);

  void OverLOAD();

  void PlayerIterator(int i);
  //DEBUG:
  void PlayerIterator();

  bool TurnEnd();


private:
  Player* player[3];
  int now_player = 0;
  Boss boss;
  Map map;
  CollisionMap collision_map;
  Turn turn = PLAYER;
  Font font = Font("res/meiryo.ttc");
  //DEBUG:
  char* playermode;
  char* bossmode;
};

