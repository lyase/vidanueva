#include "app/App.hpp"

int main(int argc, char** argv) {
    Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) { return new vidanueva::App(env); });
}
