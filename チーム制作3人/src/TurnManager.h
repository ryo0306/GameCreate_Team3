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

  }

  void SetUp();

  void PlayerTurn();

  void EnemyTurn();
  
  void Total();

  void Draw();

  //DEBUG:
  void DebugDraw();

  void SetCollisonMap(Vec2i pos_, int pattern);

  void OverLOAD();

private:
  Player player = Player(Type(BALANCE));
  Boss boss;
  Map map;
  CollisionMap collision_map;
  Turn turn = PLAYER;
  Font font = Font("res/meiryo.ttc");
  //DEBUG:
  char* playermode;
  char* bossmode;
};

