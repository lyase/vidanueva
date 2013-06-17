project (app)

add_library(app STATIC App.cpp MainPage.cpp)
target_link_libraries(app auth)
