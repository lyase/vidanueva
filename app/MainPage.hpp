#pragma once

#include <Wt/WTemplate>

namespace Wt {
    class WContainerWidget;
}

namespace vidanueva {

class MainPage : public Wt::WTemplate {
private:
public:
    MainPage(Wt::WContainerWidget* parent=nullptr);
    void setBody(Wt::WWidget* newBody);
};

}
