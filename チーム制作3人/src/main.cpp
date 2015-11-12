#include "TurnManager.h"

int main() {

  env;
  TurnManager turnmanager;
  turnmanager.SetUp();

  
  while (env.isOpen()) {
    env.begin();

 
    turnmanager.PlayerTurn();
    turnmanager.EnemyTurn();
    turnmanager.Total();
    turnmanager.Draw();
    turnmanager.DebugDraw();

    env.end();
  }
}
