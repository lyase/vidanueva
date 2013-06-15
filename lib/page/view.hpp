#pragma once
#include <Wt/Dbo/Transaction>
#include <Wt/WText>
#include <Wt/WTemplate>
#include <Wt/WTemplateFormView>
#include <Wt/WInPlaceEdit>
#include <Wt/WLineEdit>
#include <Wt/WValidator>

#include "model.hpp"

namespace vidanueva {
namespace page {

namespace dbo = Wt::Dbo;

struct WebEdit : public Wt::WTemplateFormView {
};

struct WebView : public Wt::WTemplate {
    WebView(Wt::WContainerWidget* parent, pModel model) : Wt::WTemplate(parent) {
        setTemplateText(tr("page-view"));
        if (model) {
            bindString("title", model->title);
            bindString("body", model->body);
        }
    }
};

struct AdminWebView : public Wt::WTemplate {
    pModel model;
    Wt::WInPlaceEdit* title;

    AdminWebView(Wt::WContainerWidget* parent, pModel model) : Wt::WTemplate(parent), model(model) {
        setTemplateText(tr("page-view"));
        title = new Wt::WInPlaceEdit(model->title);
        title->valueChanged().connect(this, &AdminWebView::titleChanged);
        title->lineEdit()->setValidator(new Wt::WValidator(true));
        if (model) {
            bindWidget("title", title);
            bindString("body", model->body);
        }
    }
    void titleChanged(const Wt::WString newTitle) {
        if (title->lineEdit()->validate() == Wt::WValidator::Valid) {
            dbo::Transaction t(*model.session());
            model.modify()->title = newTitle.toUTF8();
            t.commit();
        } else {
            title->setText(model->title);
        }
    }
};

}
}
