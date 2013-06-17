#pragma once
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/ptr>
#include <Wt/Auth/Dbo/AuthInfo>

#include <string>

namespace Auth {

namespace dbo = Wt::Dbo;

class User;
typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;

class User : public dbo::Dbo<User> {
public:
    std::string name;
    bool isAdmin;
    User(const std::string& name="", bool isAdmin=false) : name(name), isAdmin(isAdmin) {}
    template<class Action>
    void persist(Action& a) {
        dbo::field(a, name, "name");
        dbo::field(a, isAdmin, "isAdmin");
    }
};
using pUser = dbo::ptr<User>;

}
