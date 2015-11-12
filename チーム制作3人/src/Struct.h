#pragma once
#define MAPCHIP_SIZE 75
#include <iostream>
//MAYBE:ダメージ用のステータスを作るべき？


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
  TYPESELECT,      //  タイプを選択
  MOVE,            //  動く場所を選択
  SKILLSELECT,     //  使うスキルを選択
  CALCULATION,     //  ダメージ演算
  FINiISH,         //  終了
};

