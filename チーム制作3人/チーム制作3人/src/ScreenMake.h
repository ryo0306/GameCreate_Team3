#pragma once
#include "lib/framework.hpp"
#define env App::get()
#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 1000


class App
{
public:
  static AppEnv& get()
  {
    static AppEnv s_env(WINDOW_WIDTH,WINDOW_HEIGHT);
    return s_env;
  }

private:
  App(){}

};