#include "../WeaponsFiles/weapons.hpp"
#include "../WeaponsFiles/weaponBehavior.hpp"
#include "../WeaponsFiles/longSword.hpp"
#include "../WeaponsFiles/staff.hpp"
#include "../WeaponsFiles/dagger.hpp"
#include "../WeaponsFiles/broom.hpp"

#include "gtest/gtest.h"

/*
 * 	Long Sword  Unit Tests
 * 	*/
TEST(LongSword, NormalAttack){
	WeaponBehavior* sword = new LongSword();
	double dmg = sword->attack(1);
	EXPECT_TRUE((dmg <= 8) && (dmg >= 5));
	delete sword;
}

TEST(LongSword, SpecialAttack){
	WeaponBehavior* sword = new LongSword();
	double dmg = sword->specialAttack(1);
	EXPECT_TRUE((dmg <= 12) && (dmg >= 7.5));
	delete sword;
}

TEST(LongSword, SpecialMove){
	WeaponBehavior* sword = new LongSword();
	double dmg = sword->specialMove(1);
	EXPECT_TRUE((dmg <= 16) && (dmg >= 10));
	delete sword;
}

/*
 * 	Dagger Unit Tests
 * 	*/
TEST(Dagger, NormalAttack){
	WeaponBehavior* dagger = new Dagger();
	double dmg = dagger->attack(1);
	EXPECT_TRUE((dmg <= 5) && (dmg >= 2));
	delete dagger;
}

TEST(Dagger, SpecialAttack){
	WeaponBehavior* dagger = new Dagger();
	double dmg = dagger->specialAttack(1);
	EXPECT_TRUE((dmg <= 10) && (dmg >= 4));
	delete dagger;
}

TEST(Dagger, SpecialMove){
	WeaponBehavior* dagger = new Dagger();
	double dmg = dagger->specialMove(1);
	EXPECT_TRUE((dmg <= 15) && (dmg >= 2));
	delete dagger;
}

/*
 * 	Staff Unit Tests
 * 	*/
TEST(Staff, NormalAttack){
	WeaponBehavior* staff = new Staff();
	double dmg = staff->attack(1);
	EXPECT_TRUE((dmg <= 6) && (dmg >= 3));
	delete staff;
}

TEST(Staff, SpecialAttack){
	WeaponBehavior* staff = new Staff();
	double dmg = staff->specialAttack(1);
	EXPECT_TRUE((dmg <= 12) && (dmg >= 6));
	delete staff;
}

TEST(Staff, SpecialMove){
	WeaponBehavior* staff = new Staff();
	double dmg = staff->specialMove(1);
	EXPECT_EQ(dmg, 45);
	delete staff;
}

/*
 * 	Broom Unit Tests
 * 	*/
TEST(Broom, NormalAttack){
	WeaponBehavior* broom = new Broom();
	double dmg = broom->attack(1);
	EXPECT_TRUE((dmg <= 5) && (dmg >= 3));
	delete broom;
}

TEST(Broom, SpecialAttack){
	WeaponBehavior* broom = new Broom();
	double dmg = broom->specialAttack(1);
	EXPECT_TRUE((dmg <= 8.75) && (dmg >= 5.25));
	delete broom;
}

TEST(Broom, SpecialMove){
	WeaponBehavior* broom = new Broom();
	double dmg = broom->specialMove(1);
	EXPECT_TRUE((dmg <= 12.5) && (dmg >= 7.5));
	delete broom;
}

