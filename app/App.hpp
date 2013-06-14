#pragma once
#include <Wt/WApplication>
#include <Wt/Dbo/Session>

namespace vidanueva {

class App : public Wt::WApplication {
private:
    Wt::Dbo::Session _session;
public:
    App(const Wt::WEnvironment& env, Wt::Dbo::SqlConnection& db);
    Wt::Dbo::Session& session() { return _session; }
};

}
