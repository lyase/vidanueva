project (app)

add_library(app STATIC App.cpp)
target_link_libraries(app auth)
