#include "../BaseGameFiles/helperFunction.cpp"
#include "../WeaponsFiles/weapons.cpp"
#include "../WeaponsFiles/weaponBehavior.hpp"
#include "../WeaponsFiles/longSword.hpp"
#include "../WeaponsFiles/dagger.hpp"
#include "../WeaponsFiles/staff.hpp"
#include "../WeaponsFiles/broom.hpp"
#include "../CharacterFiles/attribute.cpp"
#include "../CharacterFiles/attributeBehavior.hpp"
#include "../CharacterFiles/wizard.hpp"
#include "../CharacterFiles/rogue.hpp"
#include "../CharacterFiles/bob.hpp"
#include "../CharacterFiles/knight.hpp"
#include "../CharacterFiles/attackCharacter.hpp"
#include "../CharacterFiles/character.hpp"
#include "../CharacterFiles/playableCharacter.hpp"
#include "../CharacterFiles/npAttackCharacter.hpp"
#include "weaponsTests.cpp"
#include "characterTest.cpp"
#include "attributeTest.cpp"
//#include "helperFunctionTests.cpp"
#include "gtest/gtest.h"

TEST(HelperFunctions, verifyIntInputTRUE){
    EXPECT_EQ(verifyIntInput("1"), 1);
}

TEST(HelperFunctions, verifyIntInputFALSE){
    EXPECT_EQ(verifyIntInput("hello"), -1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
} 
