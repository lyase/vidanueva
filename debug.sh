#!/bin/sh
gdb --args ./vida --docroot="doc-root;/resources" --approot app-root --http-port 8000 --http-address 0.0.0.0 -c app-root/config.xml
