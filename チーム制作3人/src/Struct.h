#pragma once
#define MAPCHIP_SIZE 75
#include <iostream>
//MAYBE:�_���[�W�p�̃X�e�[�^�X�����ׂ��H


enum Type
{
  BALANCE,
  KNIGHT,
  WITCH,
  TANK,
};

enum Skill
{
	DEFENCE,
	ATTACK,
	HEAL,
};

struct Damege
{

  int physical;
  int magic;
};

struct Status
{
  int hp;
  int physical;
  int magic;
  int defense;
};

enum Mode
{
  TYPESELECT,      //  �^�C�v��I��
  MOVE,            //  �����ꏊ��I��
  SKILLSELECT,     //  �g���X�L����I��
  CALCULATION,     //  �_���[�W���Z
  FINiISH,         //  �I��
};

