#include "TurnManager.h"

//あたり判定どうするべきか
//managerにあたり判定mapchipを持たせるべき？
//それともmap?
//
//
//


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
    //MAYBE:移動と移動選択を分けるべき？
    switch (player.GetMode())
    {
    case Mode::TYPESELECT:
      player.Select();
      break;
    case Mode::MOVE:
      player.Move(map.GetMousePos());
      break;
    case Mode::SKILLSELECT:
      
      break;
    case Mode::CALCULATION:
      collision_map.SetMapData(1, player.GetPos());
      boss.GivenDamage(player.GiveDamege());
      boss.DamageCalculation();
      player.ModeChange(player.GetMode());
      break;
    case Mode::FINiISH:
      turn = Turn::ENEMY;
      player.ModeChange(player.GetMode());
      break;
    default:
      assert(0);
      break;
    }
    if (env.isPushKey(GLFW_KEY_ENTER))
    player.ModeChange(player.GetMode());
  }
}

void TurnManager::EnemyTurn()
{
  if (turn == Turn::ENEMY)
  {
    switch (boss.GetMode())
    {
    case Mode::TYPESELECT:
      boss.ModeChange(boss.GetMode());
      break;
    case Mode::MOVE:
      boss.ModeChange(boss.GetMode());
      break;
    case Mode::SKILLSELECT:
      boss.SetPlayerPos(player.GetPos(), Vec2i(1, 1), Vec2i(1, 1));
      boss.AI();
      boss.ModeChange(boss.GetMode());
      break;
    case Mode::CALCULATION:
      player.GivenDamege(boss.GiveDamage());
      player.DamageCalculation();
      boss.ModeChange(boss.GetMode());
      break;
    case Mode::FINiISH:
      turn = Turn::PLAYER;

      boss.ModeChange(boss.GetMode());
      break;
    default:
      break;
    }
    if (env.isPushKey(GLFW_KEY_ENTER))
    boss.ModeChange(boss.GetMode());
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
  collision_map.Draw();
  
}

/*
//TODO:マジックナンバーを消す
//TODO:本来であればパターンごとクラスにわけ
void TurnManager::SetCollisonMap(Vec2i pos_,int pattern)
{
  switch (pattern)
  {
  case 1:
    //プレイヤーの前に持っていく


    pos_.x() -= 2;

    x_ = 0;
    for (int x = pos_.x(); x < pos_.x() + 5; x++)
    {
    y_ = 0;
      for (int y = pos_.y()+4; y >= pos_.y(); y--)
      {
        collison_map[x][y] = pattern1[x_][y_];
        y_++;
      }
      x_++;
    }
    break;
  case 2:
    pos_.x() -= 2;

    x_ = 0;
    for (int x = pos_.x(); x < pos_.x() + 5; x++)
    {
      y_ = 0;

      for (int y = pos_.y() + 9; y >= pos_.y(); y--)
      {
        collison_map[x][y] = pattern2[x_][y_];
        y_++;
      }
      x_++;
    }
    break;
  case 3:
    pos_.x() -= 2;
    pos_.y() -= 2;
    x_ = 0;
    for (int x = pos_.x(); x < pos_.x() + 5; x++)
    {
      y_ = 0;

      for (int y = pos_.y() + 4; y >= pos_.y(); y--)
      {
        collison_map[x][y] = pattern3[x_][y_];
        y_++;
      }
      x_++;
    }
    break;
  default:
    break;
  }
}

*/