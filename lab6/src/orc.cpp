#include "orc.hpp"
#include "squirrel.hpp"
#include "bear.hpp"

Orc::Orc(const std::string &name, int x, int y) : NPC(OrcType, name, x, y) {}
Orc::Orc(const std::string &name, std::istream &is) : NPC(OrcType, name, is) {}

void Orc::print() {
    std::cout << *this;
}

bool Orc::is_orc() const {
    return true;
}

std::string Orc::getType() const {
    return "Orc";
}

bool Orc::fight(std::shared_ptr<Orc> other) {
    fight_notify(other, true);
    return true;
}

bool Orc::fight(std::shared_ptr<Squirrel> other) {
    fight_notify(other, false);
    return false;
}

bool Orc::fight(std::shared_ptr<Bear> other) {
    fight_notify(other, true);
    return true;
}

void Orc::save(std::ostream &os) {
    os << OrcType << std::endl;
    NPC::save(os);
}

bool Orc::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

std::ostream &operator<<(std::ostream &os, Orc &orc) {
    os << "orc: " << *static_cast<NPC *>(&orc) << std::endl;
    return os;
}