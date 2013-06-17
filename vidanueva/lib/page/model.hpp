#pragma once
#include <string>

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/ptr>
#include <Wt/WValidator>

namespace vidanueva {
namespace page {

namespace dbo = Wt::Dbo;

struct Model : public dbo::Dbo<Model> {
    std::string name;
    std::string title;
    std::string body;
    Model(const std::string& name="",
          const std::string& title="",
          const std::string& body="") : name(name), title(title), body(body) {}
    template<class Action>
    void persist(Action& a) {
        dbo::field(a, name, "name");
        dbo::field(a, title, "title");
        dbo::field(a, body, "body");
    }
};
using pModel = dbo::ptr<Model>;

}
}
