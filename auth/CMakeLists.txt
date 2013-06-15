project (Auth)

add_library(auth STATIC Services.cpp)
target_link_libraries(auth ${BOOST_LIBS} ${WT_ALL})
