#pragma once

//MAYBE:�_���[�W�p�̃X�e�[�^�X�����ׂ��H


enum Type
{
  BALANCE,
  KNIGHT,
  WITCH,
  TANK,
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