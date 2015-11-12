#include "TurnManager.h"

//あたり判定どうするべきか
//managerにあたり判定mapchipを持たせるべき？
//それともmap?
//
//
//


//TODO:一つの攻撃に一つのクラス？
const int pattern1[5][5] =
{
  { 1, 0, 0, 0, 0 },
  { 1, 1, 1, 0, 0 },
  { 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0 },
  { 1, 0, 0, 0, 0 },
};

const int pattern2[5][10]
{
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

const int pattern3[5][5] =
{
  { 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1 },
};

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
      //boss.GivenDamege(player.GiveDamage());
      boss.DamageCalculation();
      SetCollisonMap(player.GetPos(), 3);
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
      boss.SetPlayerPos(player.GetPos(), Vec2i(1, 1), Vec2i(1, 1));
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
  for (int x = 0; x < MapSize::WIDTH; x++)
  {
    for (int y = 0; y < MapSize::HEIGHT; y++)
    {
      switch (collison_map[x][y])
      {
      case 0:
         // do nothing
        break;
      case 1:
        drawFillBox(x*MAPCHIP_SIZE - WINDOW_WIDTH / 2,
                    y*MAPCHIP_SIZE - WINDOW_HEIGHT / 2,
                    MAPCHIP_SIZE, MAPCHIP_SIZE,
                    Color(1,0,0,0.2));
        break;
      default:
        break;
      }
      
    }
  }
}


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

