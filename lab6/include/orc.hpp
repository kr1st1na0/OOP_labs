#pragma once

#include "npc.hpp"
#include "visitor.hpp"

class Orc : public NPC {
public:
    Orc(const std::string &name, int x, int y);
    Orc(const std::string &name, std::istream &is);

    void print() override;
    
    bool is_orc() const;

    std::string getType() const override;

    bool fight(std::shared_ptr<Orc> other) override;
    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<Bear> other) override;

    void save(std::ostream &os) override;

    bool accept(Visitor &visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Orc &orc);
};