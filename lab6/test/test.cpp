#include <gtest/gtest.h>

#include "npc.hpp"
#include "visitor.hpp"
#include "factory.hpp"
#include "orc.hpp"
#include "squirrel.hpp"
#include "bear.hpp"

TEST(FightTest1, Fighting) {
    Orc orc("Orc", 10, 40);
    Squirrel squirrel("Squirrel", 5, 5);
    Bear bear("Bear", 0, 50);

    EXPECT_FALSE(squirrel.fight(std::make_shared<Orc>(orc)));
    EXPECT_FALSE(squirrel.fight(std::make_shared<Bear>(bear)));
    EXPECT_FALSE(orc.fight(std::make_shared<Squirrel>(squirrel)));
    EXPECT_TRUE(orc.fight(std::make_shared<Bear>(bear)));
    EXPECT_FALSE(bear.fight(std::make_shared<Orc>(orc)));
    EXPECT_TRUE(bear.fight(std::make_shared<Squirrel>(squirrel)));
}

TEST(FightTest2, MainFighting) {
    testing::internal::CaptureStdout();
    
    set_t array;

    array.insert(factory(OrcType, "Orc1", 0, 50, "test_fight.txt")); // alive
    array.insert(factory(SquirrelType, "Squirrel1", 5, 5, "test_fight.txt")); //! killed
    array.insert(factory(BearType, "Bear1", 10, 40, "test_fight.txt"));  // alive

    array.insert(factory(OrcType, "Orc2", 60, 90, "test_fight.txt")); // alive
    array.insert(factory(SquirrelType, "Squirrel2", 25, 35, "test_fight.txt")); //! killed
    array.insert(factory(BearType, "Bear2", 0, 2, "test_fight.txt")); // alive

    array.insert(factory(OrcType, "Orc3", 20, 100, "test_fight.txt")); // alive
    array.insert(factory(SquirrelType, "Squirrel3", 40, 50, "test_fight.txt")); //! killed
    array.insert(factory(BearType, "Bear3", 80, 90, "test_fight.txt")); //! killed

    auto dead_list = fight(array, 20);
    for (auto &d : dead_list)
        array.erase(d);

    testing::internal::GetCapturedStdout();

    EXPECT_EQ(array.size(), 5);
}

TEST(VisitorTest, Visitor) {
    auto orc = std::make_shared<Orc>("Orc", 0, 5);
    auto squirrel = std::make_shared<Squirrel>("Squirrel", 10, 20);
    auto bear = std::make_shared<Bear>("Bear", 5, 10);

    auto npcVisitor = std::make_shared<NPCVisitor>(orc);

    EXPECT_TRUE(orc->accept(*npcVisitor));
    EXPECT_FALSE(squirrel->accept(*npcVisitor));
    EXPECT_TRUE(bear->accept(*npcVisitor));

    npcVisitor = std::make_shared<NPCVisitor>(squirrel);

    EXPECT_FALSE(orc->accept(*npcVisitor));
    EXPECT_FALSE(squirrel->accept(*npcVisitor));
    EXPECT_FALSE(bear->accept(*npcVisitor));

    npcVisitor = std::make_shared<NPCVisitor>(bear);

    EXPECT_FALSE(orc->accept(*npcVisitor));
    EXPECT_TRUE(squirrel->accept(*npcVisitor));
    EXPECT_FALSE(bear->accept(*npcVisitor));
}

TEST(ObserverTest, Observer) {
    auto bear = std::make_shared<Bear>("Bear", 0, 5);
    auto squirrel = std::make_shared<Squirrel>("Squirrel", 5, 10);
    
    testing::internal::CaptureStdout();

    auto textObserver = std::make_shared<TextObserver>();
    bear->subscribe(textObserver);
    bear->fight(squirrel);

    std::string textOutput = testing::internal::GetCapturedStdout();
    std::string expectedOutput = "\nMurder: --------\nbear: Bear {0, 5} \nsquirrel: Squirrel {5, 10} \nBear killed Squirrel\n";

    EXPECT_EQ(textOutput, expectedOutput);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}