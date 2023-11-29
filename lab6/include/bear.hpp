#pragma once

#include "npc.hpp"
#include "visitor.hpp"

class Bear : public NPC {
public:
    Bear(const std::string &name, int x, int y);
    Bear(const std::string &name, std::istream &is);

    void print() override;
    
    bool is_bear() const;

    std::string getType() const override;

    bool fight(std::shared_ptr<Orc> other) override;
    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<Bear> other) override;

    void save(std::ostream &os) override;

    bool accept(Visitor &visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Bear &bear);
};