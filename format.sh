#!/bin/sh
find . -name "*.h" -o -name "*.cpp" | xargs clang-format -i
