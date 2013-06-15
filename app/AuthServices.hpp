#pragma once
#include <Wt/Auth/AuthService>
#include <Wt/Auth/PasswordService>

namespace vidanueva {

struct AuthServices {
     Wt::Auth::AuthService auth;
     Wt::Auth::PasswordService pword;
     AuthServices();
};

}
