# include "Boss.h"

Boss::Boss()
{
	SetUp(Vec2i(4,11));
}

void Boss::SetUp(Vec2i def_pos_)
{
	boss_status.hp = 100;
	boss_status.physical = 100;
	boss_status.magic = 100;
	boss_status.defense = 100;
	pos[0][0] = def_pos_;
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
	if (player_pos[0].y() < 8)
	{
		boss_color = Color::yellow;
	}
	if (player_pos[0].y() >= 8)
	{
		boss_color = Color::blue;
	}
	if (player_pos[0].x() >= 4 && player_pos[0].x() < 7)
	{
		boss_color = Color::purple;
	}
}

void Boss::DamageCalculation()
{

}

void Boss::GivenDamage()
{

}


void Boss::ModeChange()
{

  if (env.isPushKey(GLFW_KEY_ENTER))
  {
    switch (mode)
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
}

void Boss::Draw()
{
	drawFillBox((pos[0][0].x() * MAPCHIP_SIZE) - WINDOW_WIDTH / 2, (pos[0][0].y() * MAPCHIP_SIZE) - WINDOW_HEIGHT / 2, MAPCHIP_SIZE * 3, MAPCHIP_SIZE * 3, boss_color);
}