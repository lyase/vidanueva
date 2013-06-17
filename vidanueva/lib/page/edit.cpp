#include "edit.hpp"

#include <Wt/Dbo/Transaction>
#include <Wt/WInPlaceEdit>
#include <Wt/WValidator>
#include <Wt/WLineEdit>
#include <Wt/WContainerWidget>

#include <memory>
#include <cassert>

namespace vidanueva {
namespace page {

AdminWebView::AdminWebView(pModel model, Wt::WContainerWidget* parent) : Wt::WTemplate(parent), model(model) {
    assert(model);
    setTemplateText(tr("page-view"));
    // Title
    title = new Wt::WInPlaceEdit(model->title);
    bindWidget("title", title);
    title->valueChanged().connect(this, &AdminWebView::titleChanged);
    title->lineEdit()->setValidator(new Wt::WValidator(true));
    // Body
    std::unique_ptr<Wt::WContainerWidget> b(new Wt::WContainerWidget());
    body = b.get();
    body->clicked().connect(this, &AdminWebView::startEditingBody);
    bindWidget("body", b.release());
}

void AdminWebView::titleChanged(const Wt::WString& newTitle) {
    if (title->lineEdit()->validate() == Wt::WValidator::Valid) {
        dbo::Transaction t(*model.session());
        model.modify()->title = newTitle.toUTF8();
        t.commit();
    } else {
        title->setText(model->title);
    }
}

void AdminWebView::startEditingBody(const Wt::WMouseEvent& ev) {

}

}
}
