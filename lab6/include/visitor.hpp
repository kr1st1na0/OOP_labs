#pragma once

#include <memory>

class NPC;
class Orc;
class Squirrel;
class Bear;

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual bool visit(Orc& orc) = 0;
    virtual bool visit(Squirrel& squirrel) = 0;
    virtual bool visit(Bear& bear) = 0;
};

class NPCVisitor : public Visitor {
public:
    NPCVisitor(std::shared_ptr<NPC> attacker);
    
    bool visit(Orc& orc) override;
    bool visit(Squirrel& squirrel) override;
    bool visit(Bear& bear) override;

private:
    std::shared_ptr<NPC> attacker_;
};