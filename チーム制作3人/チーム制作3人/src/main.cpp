#include "ScreenMake.h"
#include "Map.h"
#include "Boss.h"

int main() {
  env;
  Map map;
  Boss boss;
  Vec2i player1_pos(1, 1);
  Vec2i player2_pos(1, 1);
  Vec2i player3_pos(1, 1);
  map.ReadFile("res/stage1.txt");

  while (env.isOpen()) {
    env.begin();
	boss.SetPlayerPos(player1_pos,player2_pos,player3_pos);
    map.Draw();
    map.Edit();

    env.end();
  }
}
