#include <gtest/gtest.h>

#include "npc.hpp"
#include "observer.hpp"
#include "orc.hpp"
#include "squirrel.hpp"
#include "bear.hpp"

TEST(FightTest1, OrcVsSquirrel) {
    auto orc = factory(OrcType, "Orc", 0, 0, "test_fight.txt");
    auto squirrel = factory(SquirrelType, "Squirrel", 1, 1, "test_fight.txt"); //! will be alive
    ASSERT_FALSE(orc->accept(squirrel));
    ASSERT_TRUE(squirrel->isAlive());
}

TEST(FightTest1, OrcVsBear) {
    testing::internal::CaptureStdout();

    auto orc = factory(OrcType, "Orc", 0, 0, "test_fight.txt");
    auto bear = factory(BearType, "Bear", 1, 1, "test_fight.txt"); //! will be killed
    ASSERT_TRUE(bear->accept(orc));
    bear->mustDie();

    ASSERT_TRUE(orc->isAlive());
    ASSERT_FALSE(bear->isAlive());

    testing::internal::GetCapturedStdout();
}

TEST(FightTest2, MainFighting) {
    testing::internal::CaptureStdout();
    
    set_t NPCs;
    NPCs.insert(factory(OrcType, "Orc1", 15, 15, "test_fight.txt")); //* alive
    NPCs.insert(factory(OrcType, "Orc2", 10, 10, "test_fight.txt")); //! killed
    NPCs.insert(factory(SquirrelType, "Squirrel1", 50, 50, "test_fight.txt")); //! killed
    NPCs.insert(factory(SquirrelType, "Squirrel2", 30, 30, "test_fight.txt")); //! killed
    NPCs.insert(factory(BearType, "Bear1", 40, 40, "test_fight.txt")); //* alive
    NPCs.insert(factory(BearType, "Bear2", 5, 5, "test_fight.txt"));  //! killed
    ASSERT_EQ(6, NPCs.size());

    set_t NPCsKilled;

    for (auto& attacker : NPCs) {
        for (auto& defender : NPCs) {
            if (attacker->isAlive())
                if (defender->isAlive())
                    if (defender->accept(attacker)) {
                        defender->mustDie();
                        NPCsKilled.insert(defender);
                    }
        }
    }
    for (const auto& npc : NPCsKilled) {
        NPCs.erase(npc);
    }

    testing::internal::GetCapturedStdout();
    ASSERT_EQ(2, NPCs.size());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}