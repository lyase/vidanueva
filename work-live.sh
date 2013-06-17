#!/bin/sh
./on-file-change.sh
iwatch -e modify,create,delete -c ./on-file-change.sh -r -x ../build ..
