// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include <iostream>

#include "game.h"

int main(int argc, char **argv) {
  std::cout << "The playing cards game" << std::endl;

  playingcards::Game game{};
  game.Run();

  return 0;
}
