#include "orc.hpp"
#include "squirrel.hpp"
#include "bear.hpp"

Bear::Bear(const std::string &name, int x, int y) : NPC(BearType, name, x, y) {}
Bear::Bear(const std::string &name, std::istream &is) : NPC(BearType, name, is) {}

void Bear::print() {
    std::cout << *this;
}

bool Bear::is_bear() const {
    return true;
}

bool Bear::fight(std::shared_ptr<Orc> other) {
    fight_notify(other, false);
    return false;
}

bool Bear::fight(std::shared_ptr<Squirrel> other) {
    fight_notify(other, true);
    return true;
}

bool Bear::fight(std::shared_ptr<Bear> other) {
    fight_notify(other, false);
    return false;
}

void Bear::save(std::ostream &os) {
    os << BearType << std::endl;
    NPC::save(os);
}

bool Bear::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<Bear>(this,[](Bear*){}));
}

std::ostream &operator<<(std::ostream &os, Bear &bear) {
    os << "bear: " << *static_cast<NPC *>(&bear) << std::endl;
    return os;
}