#pragma once
#include <Wt/WText>
#include <Wt/WTemplate>
#include <Wt/WTemplateFormView>
#include <Wt/WInPlaceEdit>

#include "model.hpp"

namespace vidanueva {
namespace page {

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
    AdminWebView(Wt::WContainerWidget* parent, pModel model) : Wt::WTemplate(parent) {
        setTemplateText(tr("page-view"));
        title = new Wt::WInPlaceEdit(model->title);
        if (model) {
            bindWidget("title", title);
            bindString("body", model->body);
        }
    }
    Wt::WInPlaceEdit* title;
};

}
}
