#include "app/App.hpp"
#include "postgres.hpp"

int main(int argc, char** argv) {
    Wt::Dbo::backend::Postgres pg(pg_string);
    Wt::WRun(argc, argv, [&pg](const Wt::WEnvironment& env) { return new vidanueva::App(env, pg); });
}
