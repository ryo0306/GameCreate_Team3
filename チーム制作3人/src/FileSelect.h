#pragma once
#include "ScreenMake.h"
//DEBUG
#include "Struct.h"

char* FileSelect(int file_)
{
  switch (file_)
  {
  case 1:
    return "stage1.h";
    break;
  case 2:
    return "stage2.h";
    break;
  case 3:
    return "stage3.h";
    break;
  case 4:
    return "stage4.h";
    break;
  case 5:
    return "stage5.h";
    break;
  default:
    assert(0);
    std::cout << "正常にファイルを読み込めませんでした。" << std::endl;
    break;
  }
}