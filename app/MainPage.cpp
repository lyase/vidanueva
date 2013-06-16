#include "MainPage.hpp"

#include <Wt/WContainerWidget>

namespace vidanueva {

MainPage::MainPage(Wt::WContainerWidget* parent) : Wt::WTemplate(parent) {
    setTemplateText(tr("main-template"));
}

void MainPage::setBody(Wt::WWidget* newBody) {
    bindWidget("body", newBody);
}

}
