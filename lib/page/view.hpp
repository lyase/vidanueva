#pragma once
#include <Wt/WText>
#include <Wt/WTemplate>
#include <Wt/WInPlaceEdit>

#include "model.hpp"

namespace vidanueva {
namespace page {

namespace dbo = Wt::Dbo;

struct WebEdit : public Wt::WTemplateFormView {
};

struct WebView : public Wt::WTemplate {
    WebView(pModel model, Wt::WContainerWidget* parent=nullptr) : Wt::WTemplate(parent) {
        setTemplateText(tr("page-view"));
        if (model) {
            bindString("title", model->title);
            bindString("body", model->body);
        }
    }
};


}
}
