project (vidanueva)

cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11 -Wall -Wextra)


# Boost libraries
find_package( Boost COMPONENTS system signals program_options filesystem unit_test_framework )
include_directories(${Boost_INCLUDE_DIRS})
SET( BOOST_LIBS ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SIGNALS_LIBRARY} ${Boost_SYSTEM_LIBRARY} )

if(Boost_FOUND)
      include_directories(${Boost_INCLUDE_DIRS})
endif()

find_library( WT NAMES wtd wt )
find_library( WT_HTTP NAMES wthttpd wthttp )
find_library( WT_TEST NAMES wttestd wttest )
find_library( WT_DBO NAMES wtdbod wtdbo )
find_library( WT_DBO_POSTGRES NAMES wtdbopostgresd wtdbopostgres )
find_library( WT_DBO_SQLITE NAMES wtdbosqlite3d wtdbosqlite3 )
set(WT_BASE ${WT} ${WT_HTTP} ${WT_TEST})
set(WT_ALL ${WT_BASE} ${WT_DBO} ${WT_DBO_POSTGRES})

#add_subdirectory(lib)
add_subdirectory(app)
file(COPY app-root DESTINATION .)
file(COPY doc-root DESTINATION .)

add_executable(vidanueva main.cpp)
target_link_libraries(vidanueva app ${WT_ALL})

