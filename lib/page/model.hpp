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

struct Form : public Wt::WFormModel {
    void reqField(const char* name, const char* hint) { 
        addField(name, Wt::WString::tr(hint));
        setValidator(name, new Wt::WValidator(true, this));
    };
    Form(Wt::WObject* parent=0) : Wt::WFormModel(parent) {
        reqField("name", "This decides the url");
        // Title
        reqField("title", "The title of this page");
        // Body
        reqField("body", "The content of this page");
    }
    Form(pModel model, Wt::WObject* parent=0) : Form(parent) {
        if (model) {
            setValue("name", model->name);
            setValue("title", model->title);
            setValue("body", model->body);
        }
    }
};

}
}
