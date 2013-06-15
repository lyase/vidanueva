#pragma once
#include "../auth/User.hpp"
#include "../auth/AppExtension.hpp"

#include <Wt/WApplication>
#include <Wt/Dbo/Session>

namespace vidanueva {

class App : public Wt::WApplication {
private:
    Wt::Dbo::Session _session;
    void showLogin();
    void pathChanged(std::string path);
    Auth::AppExtension auth;
public:
    App(const Wt::WEnvironment& env, Wt::Dbo::SqlConnection& db, const Auth::Services& services);
    Wt::Dbo::Session& session() { return _session; }
};

}
