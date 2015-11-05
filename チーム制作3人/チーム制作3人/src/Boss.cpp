# include "Boss.h"


Boss::Boss()
{
	SetUp();
}

void Boss::SetUp()
{
	boss_status.hp = 100;
	boss_status.physical = 100;
	boss_status.magic = 100;
	boss_status.defense = 100;
	boss_pos = Vec2i(4, 8);
}

void Boss::SetPlayerPos(Vec2i player1_pos_, Vec2i player2_pos_, Vec2i player3_pos_)
{
		player_pos[0] = player1_pos_;
		player_pos[1] = player2_pos_;
		player_pos[2] = player3_pos_;
}

void Boss::AI()
{

}

void Boss::DamageCalculation()
{

}

void Boss::GivenDamege()
{

}