#include <Wt/Dbo/Session>

#include "lib/page/view.hpp"
#include "app/User.hpp"

namespace vidanueva {

namespace dbo = Wt::Dbo;

void mapTables(dbo::Session& session) {
    session.mapClass<page::Model>("page");
    session.mapClass<User>("user");
    session.mapClass<AuthInfo>("auth_info");
    session.mapClass<AuthInfo::AuthIdentityType>("auth_identity");
    session.mapClass<AuthInfo::AuthTokenType>("auth_token");
}

}
