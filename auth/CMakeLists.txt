project (Auth)

add_library(auth STATIC AppExtension.cpp Services.cpp)
target_link_libraries(auth ${BOOST_LIBS} ${WT_ALL})
