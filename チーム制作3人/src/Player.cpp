#include "Player.h"
#include "Map.h"



void Player::SetUp(Type type_,Vec2i pos_)
{
	
	switch (type_)
	{
	case BALANCE:
		basic_status.hp = 110;
		basic_status.defense = 110;
		basic_status.magic = 50;
		basic_status.physical = 110;
		
		pos = Vec2i(1, 0);
		
		break;

	case KNIGHT:
		basic_status.hp = 120;
		basic_status.defense = 100;
		basic_status.magic = 30;
		basic_status.physical = 130;
		
		pos = Vec2i(2, 0);
		break;

	case WITCH:
		basic_status.hp = 80;
		basic_status.defense = 90;
		basic_status.magic = 100;
		basic_status.physical = 70;

		pos = Vec2i(3, 0);

		break;

	case TANK:
		basic_status.hp = 200;
		basic_status.defense = 150;
		basic_status.magic = 20;
		basic_status.physical = 110;

		pos = Vec2i(4, 0);

		break;

	default:
		assert(0);
		break;
	}

}


void Player::Draw()
{
	drawFillBox(pos.x()*MAPCHIP_SIZE - WINDOW_WIDTH / 2, pos.y()*MAPCHIP_SIZE - WINDOW_HEIGHT / 2, size, size, Color::red);

}

void Player::Move()
{
	
		if (env.isPushKey(GLFW_KEY_RIGHT))
		{
			pos.x() += 1;
		}
	

		if (env.isPushKey(GLFW_KEY_LEFT))
		{
			pos.x() -= 1;
		}
	

		if (env.isPushKey(GLFW_KEY_UP))
		{
			pos.y() += 1;
		}

		if (env.isPushKey(GLFW_KEY_DOWN))
		{
			pos.y() -= 1;
		}

		CheckMapRange();

}


void Player::DamageCalculation()
{
}


void Player::CheckMapRange()
{
	if (pos.x() <= 0)
	{
		pos.x() = 0;
	}
	else if (pos.x() >= MapSize::WIDTH-1)
	{
		pos.x() = MapSize::WIDTH-1;
	}

	if (pos.y() <= 0)
	{
		pos.y() = 0;
	}
	else if (pos.y() >= MapSize::HEIGHT-1)
	{
		pos.y() = MapSize::HEIGHT-1;
	}

}