#include <string>

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/ptr>

namespace vidanueva {
namespace page {

namespace dbo = Wt::Dbo;

struct Model : public dbo::Dbo<Page> {
    std::string name;
    std::string title;
    std::string body;
    template<class Action>
    void persist(Action& a) {
        dbo::field(a, name, "name");
        dbo::field(a, title, "title");
        dbo::field(a, body, "body");
    }
};

}
}
