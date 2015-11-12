#pragma once
#include "ScreenMake.h"
#include "Map.h"
#include "Player.h"
#include "Boss.h"
#define PATTERN1_WHIGHT
#define PATTERN1_HEIGHT
#define PATTERN2_WHIGHT
#define PATTERN2_HEIGHT
#define PATTERN3_WHIGHT
#define PATTERN3_HEIGHT



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
    for (int x = 0; x < MapSize::WIDTH; x++)
    {
      for (int y = 0; y < MapSize::HEIGHT; y++)
      {
        collison_map[x][y] = 0;
      }
    }
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
  Turn turn = PLAYER;
  Font font = Font("res/meiryo.ttc");
  //DEBUG:
  char* playermode;
  char* bossmode;
  int collison_map[MapSize::WIDTH][MapSize::HEIGHT];
  int x_ = 0;
  int y_ = 0;
};

