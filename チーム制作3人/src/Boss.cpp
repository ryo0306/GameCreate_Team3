# include "Boss.h"

Boss::Boss()
{
	SetUp(Vec2i(4,10));
  rand.setSeed(u_int(time(nullptr)));
}

void Boss::SetUp(Vec2i def_pos_)
{
	basic_status.hp = 200;
	basic_status.physical = 100;
	basic_status.magic = 100;
	basic_status.defense = 100;
	pos[0][0] = def_pos_;
  for (int x = 0; x < 3; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      pos[x][y] = Vec2i(def_pos_.x() + x, def_pos_.y() + y);
    }
  }
	boss_color = Color::black;
}

void Boss::SetPlayerPos(Vec2i player1_pos_, Vec2i player2_pos_, Vec2i player3_pos_)
{
		player_pos[0] = player1_pos_;
		player_pos[1] = player2_pos_;
		player_pos[2] = player3_pos_;
}

void Boss::AI()
{
	boss_type = ALL;
	boss_color = Color::black;
  player_num = rand(0, 2);
    // ëO
    if (player_pos[player_num].x() >= pos[0][0].x() &&
        player_pos[player_num].x() < pos[2][0].x() &&
        player_pos[player_num].y() < pos[0][0].y())
    {
      boss_color = Color::purple;
      boss_type = Boss_type::STRAIGHT;
    }
    // å„ÇÎ
    else if (player_pos[player_num].x() >= pos[0][0].x() &&
             player_pos[player_num].x() < pos[2][0].x() &&
             player_pos[player_num].y() >= pos[0][2].y())
    {
      boss_color = Color::gray;
      boss_type = Boss_type::BACK;
    }
    // ç∂
    else if (player_pos[player_num].x() < pos[0][0].x())
    {
      boss_color = Color::yellow;
      boss_type = Boss_type::LEFT;
    }
    // âE
    else if (player_pos[player_num].x() >= pos[2][2].x())
    {
      boss_color = Color::blue;
      boss_type = Boss_type::RIGHT;
    }

  
	//if ((player_pos[0].x() < 5 && player_pos[1].x() < 5) || 
	//	(player_pos[0].x() < 5 && player_pos[2].x() < 5) || 
	//	(player_pos[1].x() < 5 && player_pos[2].x() < 5))
	//{
	//	boss_color = Color::yellow;
	//	boss_type = LEFT;
	//}
	//if (player_pos[0].x() >= 5 && player_pos[1].x() >= 5 ||
	//	player_pos[0].x() >= 5 && player_pos[2].x() >= 5 || 
	//	player_pos[1].x() >= 5 && player_pos[2].x() >= 5)
	//{
	//	boss_color = Color::blue;
	//	boss_type = RIGHT;
	//}
	//if ((player_pos[0].x() >= pos[0][0].x() && player_pos[0].x() < pos[0][0].x() + 3 && player_pos[1].x() >= pos[0][0].x() && player_pos[1].x() < pos[0][0].x() + 3) ||
	//	(player_pos[0].x() >= pos[0][0].x() && player_pos[0].x() < pos[0][0].x() + 3 && player_pos[2].x() >= pos[0][0].x() && player_pos[2].x() < pos[0][0].x() + 3) || 
	//	(player_pos[1].x() >= pos[0][0].x() && player_pos[1].x() < pos[0][0].x() + 3 && player_pos[2].x() >= pos[0][0].x() && player_pos[2].x() < pos[0][0].x() + 3))
	//{
	//	if (player_pos[0].y() < pos[0][0].y() || player_pos[1].y() < pos[0][0].y() || player_pos[2].y() < pos[0][0].y())
	//	{
	//		boss_color = Color::purple;
	//		boss_type = BACK;
	//	}
	//	if (player_pos[0].y() >= pos[0][0].y() || player_pos[1].y() >= pos[0][0].y() || player_pos[2].y() >= pos[0][0].y())
	//	{
	//		boss_color = Color::gray;
	//		boss_type = STRAIGHT;
	//	}
	//}
  
}

void Boss::DamageCalculation()
{
  int total_damage = given_damage.physical - basic_status.defense;
  if (total_damage <= 0)
    return;

  basic_status.hp -= total_damage;
}

Damege Boss::GiveDamage()
{
	give_damage.physical = basic_status.physical;
	return give_damage;
}



void Boss::ModeChange(Mode next_)
{

  switch (next_)
  {
  case TYPESELECT:
    mode = MOVE;
    break;
  case MOVE:
    mode = SKILLSELECT;
    break;
  case SKILLSELECT:
    mode = CALCULATION;
    break;
  case CALCULATION:
    mode = FINiISH;
    break;
  case FINiISH:
    mode = TYPESELECT;
    break;
  default:
    break;
  }
}

void Boss::Draw()
{
	drawFillBox((pos[0][0].x() * MAPCHIP_SIZE) - WINDOW_WIDTH / 2, (pos[0][0].y() * MAPCHIP_SIZE) - WINDOW_HEIGHT / 2, MAPCHIP_SIZE * 3, MAPCHIP_SIZE * 3, boss_color);
}