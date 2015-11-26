#include "TurnManager.h"

///TODO:
// 方向変換
// スキル選択画面
// タイトル
// リザルト
// 三体作った時にどれを操作しているか選択できるようにする
// コンストラクタで初期位置を設定するようにする。
// あたり判定内に入っていればダメージをくらう
// 方向を変えれるようにする
// ボスをよけていくようにする。（ボスに重ならないように）

// できれば
// 画面を一つ戻れるようにする。



void TurnManager::SetUp()
{
  map.ReadFile("res/stage1.txt");
  for (int i = 0; i < 3; i++)
  {
    player[i] = new Player(Type::BALANCE);
  }
  
  player[0]->SetUp(Type::BALANCE,Vec2i(2,2));
  player[1]->SetUp(Type::BALANCE, Vec2i(2, 2));
  player[2]->SetUp(Type::BALANCE, Vec2i(2, 2));
  
  boss.SetUp(Vec2i(4,10));
  for (int i = 0; i < 3; i++)
  {
    player[i]->SetBossPos(Vec2i(4, 10));
  }
}

void TurnManager::PlayerTurn()
{
  if (turn == Turn::PLAYER)
  {
    PlayerIterator();
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
      
      boss.SetPlayerPos(player[0]->GetPos(), player[1]->GetPos(), player[2]->GetPos());
      boss.AI();
      boss.ModeChange(boss.GetMode());
      break;
    case Mode::CALCULATION:
      for (int i = 0; i < 3; i++)
      {
        player[i]->GivenDamege(boss.GiveDamage());
        player[i]->DamageCalculation();
      }
      boss.ModeChange(boss.GetMode());
      collision_map.Reset();
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
void TurnManager::Total()
{
  map.Edit("res/stage1.txt");
}

void TurnManager::Draw()
{
  map.Draw();
  boss.Draw();
 
  for (int i = 0; i < 3; i++)
  {
    player[i]->Draw();
  }
    PlayerDraw(now_player);
  
}


void TurnManager::PlayerIterator()
{
  //MAYBE:移動と移動選択を分けるべき？
  switch (player[now_player]->GetMode())
  {
  case Mode::TYPESELECT:
    player[now_player]->Select();
    break;
  case Mode::MOVE:
    player[now_player]->Move(map.GetMousePos());
    break;
  case Mode::SKILLSELECT:
    player[now_player]->SkillSelect();
    collision_map.Reset();
    collision_map.SetMapData(player[now_player]->GetAttackPattern(), player[now_player]->GetPos());
    break;
  case Mode::CALCULATION:
    //collision_map.SetMapData(player[now_player]->GetAttackPattern(), player[now_player]->GetPos());
    for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
      {
        if (collision_map.Check(boss.GetPos(x, y)))
        {
          boss.GivenDamage(player[now_player]->GiveDamege());
          break;
        }
      }
    }
    boss.DamageCalculation();
    player[now_player]->ModeChange(player[now_player]->GetMode());
    collision_map.Reset();
    break;
  case Mode::FINiISH:
    if (player[2]->GetMode() == Mode::FINiISH)
      turn = Turn::ENEMY;
    player[now_player]->ModeChange(TYPESELECT);
    TurnEnd();
    break;
  default:
    assert(0);
    break;
  }


  if (env.isPushKey(GLFW_KEY_ENTER) && player[now_player]->IsEnd() == false)
  {
    player[now_player]->ModeChange(player[now_player]->GetMode());
    env.flushInput();
  }

}



void TurnManager::PlayerDraw(int i)
{
    switch (player[i]->GetMode())
  {
  case TYPESELECT:
      break;
  case MOVE:
    break;
  case SKILLSELECT:
    player[i]->DrawSkill();
    break;
  case CALCULATION:
    break;
  case FINiISH:
    break;
  default:
    break;
  }
}

void TurnManager::EnemyDraw()
{
}

void TurnManager::DebugDraw()
{
  std::string debug_p1 = std::to_string(player[0]->GetMode());
  std::string debug_p2 = std::to_string(player[1]->GetMode());
  std::string debug_p3 = std::to_string(player[2]->GetMode());
  std::string debug_b = std::to_string(boss.GetMode());
  font.size(100);
  font.draw("PLAYER1: " + debug_p1, Vec2f(-WINDOW_WIDTH/2, WINDOW_HEIGHT/2+100),Color::red);
  font.draw("PLAYER2: " + debug_p2, Vec2f(-WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 -0), Color::red);
  font.draw("PLAYER3: " + debug_p3, Vec2f(-WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 100), Color::red);
  font.draw("Boss: " + debug_b, Vec2f(-WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 200), Color::red);
  collision_map.Draw();
  
}


bool TurnManager::TurnEnd()
{
  switch (now_player)
  {
  case 0:
  case 1:
    now_player++;
    return false;
  case 2:
    now_player = 0;
    return true;
    break;
  default:
    break;
  }
}