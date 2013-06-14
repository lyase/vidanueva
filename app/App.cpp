#include "App.hpp"
#include <Wt/WText>

namespace vidanueva {

App::App(const Wt::WEnvironment& env) : Wt::WApplication(env) {
    new Wt::WText("Hello", root());
}

}
