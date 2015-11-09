#include "TurnManager.h"

void TurnManager::SetUp()
{
  map.ReadFile("res/stage1.txt");
  player.SetUp(Type::BALANCE,Vec2i(2,2));
  boss.SetUp(Vec2i(6,10));
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
      //boss.GivenDamege(player.GiveDamage());
      boss.DamageCalculation();
      break;
    case Mode::FINiISH:
      turn = Turn::ENEMY;
      break;
    default:
      assert(0);
      break;
    }
    player.ModeChange();
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
      //player.GivenDamege(boss.GiveDammage());
      player.DamageCalculation();
      break;
    case Mode::FINiISH:
      turn = Turn::PLAYER;
      break;
    default:
      break;
    }

    boss.ModeChange();
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


void TurnManager::DebugDraw()
{
  std::string debug_p = std::to_string(player.GetMode());
  std::string debug_b = std::to_string(boss.GetMode());
  font.size(100);
  font.draw("PLAYER: " + debug_p, Vec2f(-WINDOW_WIDTH/2, WINDOW_HEIGHT/2-100),Color::red);
  font.draw("Boss: " + debug_b, Vec2f(-WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 250), Color::red);

}
