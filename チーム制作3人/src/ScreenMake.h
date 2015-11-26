#pragma once
#include "lib/framework.hpp"
#include <iostream>
#define env App::get()
#define WINDOW_WIDTH (11*75)
#define WINDOW_HEIGHT (1200-3*75) 
#define WIN_WIDTH (11*75)
#define WIN_HEIGHT (1200+ 3*75) 

class App
{
public:
  static AppEnv& get()
  {
    static AppEnv s_env(WIN_WIDTH,WIN_HEIGHT);
    return s_env;
  }

private:
  App(){}

};