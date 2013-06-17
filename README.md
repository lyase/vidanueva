Wt Example website
==================

This is the source for the real life website: http://vidanueva.org.au

To build:
---------

    mkdir build
    cd build
    cmake ..
    make -j4
    ./run.sh
    # Navigate to http://localhost:8000


Code organisation
-----------------

 * vidanueva -- All source code (except main.cpp), put here, so we can go <vidanueva/xx> to #include things
   * app/   -- The main application bits
   * auth/  -- Anything to do with authentication
   * lib/   -- The content types, 'page', and 'sermon'
 * doc-root/ -- Static files that will be shared on the web. eg. css, js, jpg, etc
 * app-root/ -- Files that the app reads at runtime, configuration files etc.

