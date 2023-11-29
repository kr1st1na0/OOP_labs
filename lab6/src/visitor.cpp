#include "npc.hpp"
#include "visitor.hpp"
#include "orc.hpp"
#include "squirrel.hpp"
#include "bear.hpp"

NPCVisitor::NPCVisitor(std::shared_ptr<NPC> attacker) : attacker_(attacker) {}

bool NPCVisitor::visit(Orc& orc) {
    return attacker_->fight(std::make_shared<Orc>(orc));
}

bool NPCVisitor::visit(Squirrel& squirrel) {
    return attacker_->fight(std::make_shared<Squirrel>(squirrel));
}

bool NPCVisitor::visit(Bear& bear) {
    return attacker_->fight(std::make_shared<Bear>(bear));
}