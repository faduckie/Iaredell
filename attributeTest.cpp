//#include "../BaseGameFiles/helperFunction.cpp"
#include "../CharacterFiles/attribute.hpp"
#include "../CharacterFiles/attributeBehavior.hpp"
#include "../CharacterFiles/wizard.hpp"
#include "../CharacterFiles/rogue.hpp"
#include "../CharacterFiles/bob.hpp"
#include "../CharacterFiles/knight.hpp"
#include "gtest/gtest.h"

TEST(Attribute, VerifyRogueAttack)
{
    Attribute *model = new Attribute();
    model->setBehavior(new Rogue());
    model->setStats();

    EXPECT_EQ(model->getAttackStat(), 16.50);
    delete model;
}

TEST(Attribute, VerifyRogueHP)
{
    Attribute *model = new Attribute();
    model->setBehavior(new Rogue());
    model->setStats();

    EXPECT_EQ(model->getHpStat(), 16.00);
    delete model;
}

TEST(Attribute, VerifyRogueDef)
{
    Attribute *model = new Attribute();
    model->setBehavior(new Rogue());
    model->setStats();

    EXPECT_EQ(model->getDefenseStat(), 12.50);
    delete model;
}

////

TEST(Attribute, VerifyBobAttack)
{
    Attribute *model = new Attribute();
    model->setBehavior(new Bob());
    model->setStats();

    EXPECT_EQ(model->getAttackStat(), 13);
    delete model;
}

TEST(Attribute, VerifyBobHP)
{
    Attribute *model = new Attribute();
    model->setBehavior(new Bob());
    model->setStats();

    EXPECT_EQ(model->getHpStat(), 13);
    delete model;
}

TEST(Attribute, VerifyBobDef)
{
    Attribute *model = new Attribute();
    model->setBehavior(new Bob());
    model->setStats();
    EXPECT_EQ(model->getDefenseStat(), 8);
    delete model;
}


