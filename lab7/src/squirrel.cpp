#include "orc.hpp"
#include "squirrel.hpp"
#include "bear.hpp"

Squirrel::Squirrel(const std::string &name, int x, int y) : NPC(SquirrelType, name, x, y) {}
Squirrel::Squirrel(const std::string &name, std::istream &is) : NPC(SquirrelType, name, is) {}

void Squirrel::print() {
    std::cout << *this;
}

bool Squirrel::is_squirrel() const {
    return true;
}

bool Squirrel::fight(std::shared_ptr<Orc> other) {
    fight_notify(other, false);
    return false;
}

bool Squirrel::fight(std::shared_ptr<Squirrel> other) {
    fight_notify(other, false);
    return false;
}

bool Squirrel::fight(std::shared_ptr<Bear> other) {
    fight_notify(other, false);
    return false;
}

void Squirrel::save(std::ostream &os) {
    os << SquirrelType << std::endl;
    NPC::save(os);
}

bool Squirrel::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<Squirrel>(this,[](Squirrel*){}));
}

std::ostream &operator<<(std::ostream &os, Squirrel &squirrel) {
    os << "squirrel: " << *static_cast<NPC *>(&squirrel) << std::endl;
    return os;
}