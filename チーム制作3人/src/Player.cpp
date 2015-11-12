#include "Player.h"
#include "Map.h"



void Player::SetUp(Type type_,Vec2i pos_)
{
	
	type = type_;
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
	drawFillBox(pos.x()*MAPCHIP_SIZE - WINDOW_WIDTH / 2, pos.y()*MAPCHIP_SIZE - WINDOW_HEIGHT / 2, size, size,color);
	std::cout << type << std::endl;
}


void Player::Select()
{
	if (env.isPullKey(GLFW_KEY_RIGHT))
	{
		switch (type)
		{
		case BALANCE:
			type = KNIGHT;

			break;
		case KNIGHT:
			type = WITCH;

			break;
		case WITCH:
			type = TANK;

			break;
		case TANK:
			type = BALANCE;
			break;
		default:
			assert(0);
			
			break;
		}
	}

	if (env.isPullKey(GLFW_KEY_LEFT))
	{
		switch (type)
		{
		case BALANCE:
			type = TANK;

			break;
		case KNIGHT:
			type = BALANCE;

			break;
		case WITCH:
			type = KNIGHT;

			break;
		case TANK:
			type = WITCH;
			break;
		default:
			assert(0);

			break;
		}
	}

	ChangeColor(type);
  SetUp(type, pos);

}

void Player::Move(Vec2i mouse_pos_)
{
	if (env.isPushButton(Mouse::LEFT))
	{
		next_move_position = mouse_pos_;
		//std::cout << next_move_position << std::endl;

	}
	if (pos.x() != next_move_position.x())
	{

		if (next_move_position.x() > pos.x())
		{
			pos.x()++;
		}

		if (next_move_position.x() < pos.x())
		{
			pos.x()--;

		}

	}
	else
	{
		if (next_move_position.y() > pos.y())
		{
			pos.y()++;

		}

		if (next_move_position.y() < pos.y())
		{
			pos.y()--;

		}
	}
	

	
	

		CheckMapRange();

}


void Player::DamageCalculation()
{

  int total_damage = given_damage.physical - basic_status.defense;
  if (total_damage <= 0)
    return;
  basic_status.hp -= total_damage;
}
void Player::DrawSkill()
{
	
	

	font.size(100);
	font.draw("UŒ‚", Vec2f(-100, 0), Color::red);
	font.draw("–hŒä", Vec2f(-400, 0), Color::blue);
	font.draw("‰ñ•œ", Vec2f(200, 0), Color::green);

	drawFillBox(skill_select_point.x(), skill_select_point.y(), 50, 50, Color::cyan);

	SkillSelect();



}


void Player::SkillSelect()
{
	switch (skill)
	{
	case DEFENCE:
		skill_select_point = Vec2f(-300, 100);
		if (env.isPushKey(GLFW_KEY_RIGHT))
		{
			skill = ATTACK;
		}
		break;
	case ATTACK:
		skill_select_point = Vec2f(0, 100);
		if (env.isPushKey(GLFW_KEY_RIGHT))
		{
			skill = HEAL;

		}

		break;
	case HEAL:
		skill_select_point = Vec2f(280, 100);
		if (env.isPushKey(GLFW_KEY_RIGHT))
		{
			skill = DEFENCE;

		}

		break;
	default:
		assert(0);
		break;
	}

	
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

void Player::ChangeColor(Type type_)
{
	type = type_;
	switch (type_)
	{
	case BALANCE:

		color = Color::blue;
		break;

	case KNIGHT:

		color = Color::red;
		break;

	case WITCH:

		color = Color::purple;

		break;

	case TANK:

		color = Color::green;

		break;

	default:
		assert(0);
		break;
	}


}

Damege Player::GiveDamege()
{
	switch (skill)
	{
	case DEFENCE:
		give_damage.physical = 0;
		return give_damage;
		break;
	case ATTACK:
		give_damage.physical = skill_attack + basic_status.physical;
		return give_damage;
		break;
	case HEAL:
		give_damage.physical = 0;
		return give_damage;
		break;
	default:
		break;
	}

	


}


void Player::ModeChange(Mode next_)
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