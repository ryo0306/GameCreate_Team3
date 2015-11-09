#pragma once
#include <string>
#include <fstream>
#include<sstream>
#include "ScreenMake.h"
#include "Collision.h"
#define MAPCHIP_SIZE 75
#define OBJECT_NUM 3
//TODO?:EDITMODE�ƕ�����ׂ�

//TODO:�I�u�W�F�N�g�𑝂₵����OBJECT_NUM�����₷
enum MapObject
{
   NONE,
   WALL,
   DAMEGE,
};

enum MapSize
{
  WIDTH = 11,
  HEIGHT = 16,
};

class Map
{
public:
  Map()
  {
    for (int i = 0; i < MapSize::WIDTH; i++){
      for (int j = 0; j < MapSize::HEIGHT; j++){
        frame_color[i][j] = Color::black;
      }
    }
  }

  void SetUp();
  void ReadFile(const std::string& file_);
  void Draw();
  void Edit(const std::string& file_);
  void ChangeMap(int x_, int y_);
private:
  
  int stage[MapSize::WIDTH][MapSize::HEIGHT];
  Color frame_color[MapSize::WIDTH][MapSize::HEIGHT];
};