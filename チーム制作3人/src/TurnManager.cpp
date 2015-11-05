#include "TurnManager.h"

void TurnManager::SetUp()
{
  map.ReadFile("res/stage1.txt");
  player.SetUp(Type::BALANCE,Vec2i(2,2));
  boss.SetUp();
}

void TurnManager::PlayerTurn()
{
  if (turn == Turn::PLAYER)
  {
    //MAYBE:動くモードと戦闘モードを分けるべき？
    //if (player.MoveModa())
    player.Move();
    //if (player.Select())
    player.DamageCalculation();
    //boss.GivenDamege(player.GiveDamage());
  }
}

void TurnManager::EnemyTurn()
{
  if (turn == Turn::ENEMY)
  {
    boss.SetPlayerPos(Vec2i(1, 1), Vec2i(1, 1), Vec2i(1, 1));
    boss.AI();
    boss.DamageCalculation();
    //player.GivenDamege(boss.GiveDammage());
  }
}

void TurnManager::Draw()
{
  map.Draw();
  player.Draw();
  boss.Draw();
}

void TurnManager::TotalTurn()
{
  map.Edit("res/stage1.txt");
}