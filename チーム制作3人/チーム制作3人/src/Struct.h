#pragma once

//MAYBE:ダメージ用のステータスを作るべき？


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