#pragma once
#include "User.hpp"
#include "AuthServices.hpp"

#include <Wt/WApplication>
#include <Wt/Dbo/Session>
#include <Wt/Auth/Dbo/UserDatabase>
#include <Wt/Auth/Login>

namespace vidanueva {

using UserDatabase = Wt::Auth::Dbo::UserDatabase<AuthInfo>;

class App : public Wt::WApplication {
private:
    Wt::Dbo::Session _session;
    UserDatabase _users;
    Wt::Auth::Login _login;
    void showLogin();
    void pathChanged(std::string path);
public:
    App(const Wt::WEnvironment& env, Wt::Dbo::SqlConnection& db, const AuthServices& authServices);
    Wt::Dbo::Session& session() { return _session; }
    const AuthServices& authServices;
    Wt::Auth::Login& login() { return _login; }
    UserDatabase& users() { return _users; }
};

}
