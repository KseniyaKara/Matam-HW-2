#!/bin/bash

#g++ -DNDEBUG -std=c++17 -Wall -pedantic-errors -Werror -g -o mtm_blockchain *.cpp
g++ -DNDEBUG -std=c++17 -Wall -pedantic-errors -Werror -g -o MvidiaTest MataMvidia.cpp Matrix.cpp Utilities.cpp -I . ./tests/tests.cpp
python3 ./run_tests.py ./tests/custom_tests.json ./MvidiaTest
