#include "AppExtension.hpp"

namespace Auth {

bool AppExtension::isAdmin() {
    auto wtUser = login().user();
    if (wtUser.isValid()) {
        pUser user = users().find(wtUser)->user();
        if (user)
            return user->isAdmin;
    }
    return false;
}

}
