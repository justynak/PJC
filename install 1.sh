#!/bin/bash
  cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr CMakeLists.txt
  make
  sudo make install

