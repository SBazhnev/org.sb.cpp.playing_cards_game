// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#include <iostream>
#include <locale>

#include "game.h"

int main() {
  std::locale::global(std::locale(""));

  try {
    playingcards::Game game{};

    game.Run();
  }
  catch (...) {
    std::cout << "Unknown error! Exit." << "\n";
  }

  return 0;
}
