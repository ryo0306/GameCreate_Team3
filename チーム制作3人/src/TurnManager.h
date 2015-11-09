#pragma once
#include "ScreenMake.h"
#include "Map.h"
#include "Player.h"
#include "Boss.h"


enum Turn
{
  PLAYER,
  ENEMY,
};

class TurnManager
{
public:
  TurnManager(){}

  void SetUp();

  void PlayerTurn();

  void EnemyTurn();
  
  void Total();

  void Draw();

  
private:
  Player player = Player(Type(BALANCE));
  Boss boss;
  Map map;
  Turn turn = PLAYER;
};