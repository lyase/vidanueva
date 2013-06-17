#pragma once

#include "User.hpp"
#include "Services.hpp"

#include <Wt/Auth/Login>
#include <Wt/Auth/Dbo/UserDatabase>

namespace Auth {

using UserDatabase = Wt::Auth::Dbo::UserDatabase<AuthInfo>;

class AppExtension {
private:
    Wt::Dbo::Session& _session;
    Wt::Auth::Login _login;
    UserDatabase _users;
public:
    AppExtension(Wt::Dbo::Session& session, const Services& services) : _session(session), _users(_session), services(services) {}
    const Services& services;
    UserDatabase& users() { return _users; }
    Wt::Auth::Login& login() { return _login; }
    // Returns true if the currently logged in user is an admin
    bool isAdmin();
};

}
