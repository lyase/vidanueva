#!/bin/sh
killall vidanueva
cmake .. && make -j4 && ./run.sh
