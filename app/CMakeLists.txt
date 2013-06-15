project (app)

add_library(app STATIC App.cpp AuthServices.cpp)
target_link_libraries(app ${BOOST_LIBS} ${WT_ALL})
