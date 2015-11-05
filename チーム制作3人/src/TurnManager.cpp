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
    //MAYBE:à⁄ìÆÇ∆à⁄ìÆëIëÇï™ÇØÇÈÇ◊Ç´ÅH
    switch (player.GetMode())
    {
    case Mode::TYPESELECT:
      break;
    case Mode::MOVE:
      player.Move();
      break;
    case Mode::SKILLSELECT:
      
      break;
    case Mode::CALCULATION:
      player.DamageCalculation();
      //boss.GivenDamege(player.GiveDamage());
      break;
    case Mode::FINiISH:
      turn == Turn::ENEMY;
      break;
    default:
      assert(0);
      break;
    }

  }
}

void TurnManager::EnemyTurn()
{
  if (turn == Turn::ENEMY)
  {
    switch (boss.GetMode())
    {
    case Mode::TYPESELECT:
      break;
    case Mode::MOVE:
      break;
    case Mode::SKILLSELECT:
      boss.SetPlayerPos(Vec2i(1, 1), Vec2i(1, 1), Vec2i(1, 1));
      boss.AI();
      break;
    case Mode::CALCULATION:
      boss.DamageCalculation();
      //player.GivenDamege(boss.GiveDammage());
      break;
    case Mode::FINiISH:
      turn == Turn::PLAYER;
      break;
    default:
      break;
    }
  }
}

void TurnManager::Draw()
{
  map.Draw();
  player.Draw();
  boss.Draw();
}

void TurnManager::Total()
{
  map.Edit("res/stage1.txt");
}