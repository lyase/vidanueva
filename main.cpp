#include "app/App.hpp"
#include "app/AuthServices.hpp"
#include "postgres.hpp"

int main(int argc, char** argv) {
    Wt::Dbo::backend::Postgres pg(pg_string);
    const vidanueva::AuthServices authServices;
    Wt::WRun(argc, argv, [&](const Wt::WEnvironment& env) { return new vidanueva::App(env, pg, authServices); });
}
