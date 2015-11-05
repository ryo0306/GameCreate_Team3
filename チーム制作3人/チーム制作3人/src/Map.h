#pragma once
#include <string>
#include <fstream>
#include<sstream>
#include "ScreenMake.h"
#include "Collision.h"
#define MAPCHIP_SIZE 100
#define OBJECT_NUM 3
//TODO?:EDITMODEと分けるべき

//TODO:オブジェクトを増やしたらOBJECT_NUMも増やす
enum MapObject
{
   NONE,
   WALL,
   DAMEGE,
};

enum MapSize
{
  WIDTH = 7,
  HEIGHT = 10,
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
  void Edit();
  void ChangeMap(int x_, int y_);
private:
  int stage[MapSize::WIDTH][MapSize::HEIGHT];
  Color frame_color[MapSize::WIDTH][MapSize::HEIGHT];
};