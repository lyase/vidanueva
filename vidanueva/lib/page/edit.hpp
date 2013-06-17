#pragma once

#include "model.hpp"

#include <Wt/WTemplate>
#include <Wt/WEvent>

namespace Wt {
  class WInPlaceEdit;
  class WContainerWidget;
}

namespace vidanueva {
namespace page {

class AdminWebView : public Wt::WTemplate {
private:
    pModel model;
    Wt::WInPlaceEdit* title;
    Wt::WContainerWidget* body;
    void titleChanged(const Wt::WString& newTitle);
    void startEditingBody(const Wt::WMouseEvent& ev);
public:
    AdminWebView(pModel model, Wt::WContainerWidget* parent=nullptr);
};

}
}
