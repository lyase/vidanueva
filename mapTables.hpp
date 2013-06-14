#include <Wt/Dbo/Session>

#include "lib/page/view.hpp"

namespace vidanueva {

namespace dbo = Wt::Dbo;

void mapTables(dbo::Session& session) {
    session.mapClass<page::Model>("page");
}

}
