#pragma once
#include <Wt/WText>
#include <Wt/WTemplate>
#include <Wt/WTemplateFormView>

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

}
}
