#include <Wt/Dbo/Session>

#include "lib/page/view.hpp"
#include "auth/User.hpp"

namespace vidanueva {

namespace dbo = Wt::Dbo;

void mapTables(dbo::Session& session) {
    session.mapClass<page::Model>("page");
    session.mapClass<Auth::User>("user");
    session.mapClass<Auth::AuthInfo>("auth_info");
    session.mapClass<Auth::AuthInfo::AuthIdentityType>("auth_identity");
    session.mapClass<Auth::AuthInfo::AuthTokenType>("auth_token");
}

}
