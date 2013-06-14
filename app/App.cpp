#include "App.hpp"

#include "../lib/page/view.hpp"
#include "../mapTables.hpp"

#include <Wt/WText>
#include <Wt/Dbo/Exception>

#include <stdexcept>

namespace vidanueva {

namespace dbo = Wt::Dbo;

App::App(const Wt::WEnvironment& env, dbo::SqlConnection& db) : Wt::WApplication(env) {
    // Configure our messages
    messageResourceBundle().use(appRoot() + "/page/view");
    messageResourceBundle().use(appRoot() + "/page/edit");
    // Set up the DB session
    _session.setConnection(db);
    mapTables(_session);
    try {
        log("info") << "Creating tables";
        _session.createTables();
    } catch ( std::exception e ) {
        log("info") << "Table creation failed: " << e.what();
    } catch (...) {
        log("info") << "Table creation failed. Exception not caught.";
    }
    dbo::Transaction t(_session);
    page::pModel welcome = _session.add(new page::Model{"index", "Welcome", "To Vidanueva"});
    t.commit();
    // Show the main page
    new page::WebView(root(), welcome);
}

}
