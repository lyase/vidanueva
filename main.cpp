#include <vidanueva/app/App.hpp>
#include <vidanueva/auth/Services.hpp>
#include <vidanueva/postgres.hpp>
#include <Wt/Dbo/backend/Sqlite3>
int main(int argc, char** argv) {
//    Wt::Dbo::backend::Postgres pg(pg_string);
    Wt::Dbo::backend::Sqlite3 sql("appRoot()+myapp.db");
    const Auth::Services authServices;
    Wt::WRun(argc, argv, [&](const Wt::WEnvironment& env) { return new vidanueva::App(env, sql, authServices); });
}
