#!/bin/sh
killall vida
cmake .. && make -j4 && ./run.sh
