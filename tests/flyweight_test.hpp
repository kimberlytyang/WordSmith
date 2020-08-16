#ifndef FLYWEIGHT_TEST_HPP
#define FLYWEIGHT_TEST_HPP

#include "../header/flyweight.hpp"
#include "../header/character.hpp"

TEST(FlyweightTest, HashingA){
	char test = 'A';
	Flyweight* f = new Flyweight();
	Character* Ctest = f->hash(test);
	EXPECT_EQ(Ctest->getC(),'A');
}

TEST(FlyweightTest, HashingMany){
	char test[22] = {'a','l','b','e','r','t','t','a','m','b','a','l','o','w','o','r','d','s','m','i','t','h'};
	Flyweight* f = new Flyweight();
	char res[22];
	for(int i = 0; i < 22; ++i){
		Character* temp = f->hash(test[i]);
		res[i] =  temp->getC();
	}
	EXPECT_EQ(res[0], 'a');
	EXPECT_EQ(res[1], 'l');
	EXPECT_EQ(res[2], 'b');
	EXPECT_EQ(res[3], 'e');
	EXPECT_EQ(res[4], 'r');
	EXPECT_EQ(res[5], 't');
	EXPECT_EQ(res[6], 't');
	EXPECT_EQ(res[7], 'a');
	EXPECT_EQ(res[8], 'm');
	EXPECT_EQ(res[9], 'b');
	EXPECT_EQ(res[10], 'a');
	EXPECT_EQ(res[11], 'l');
	EXPECT_EQ(res[12], 'o');
	EXPECT_EQ(res[13], 'w');
	EXPECT_EQ(res[14], 'o');
	EXPECT_EQ(res[15], 'r');
	EXPECT_EQ(res[16], 'd');
	EXPECT_EQ(res[17], 's');
	EXPECT_EQ(res[18], 'm');
	EXPECT_EQ(res[19], 'i');
	EXPECT_EQ(res[20], 't');
	EXPECT_EQ(res[21], 'h');

}

TEST(FlyweightTest, DuplicateHashTest){
	char test[3] = {'a','A','a'};
	Flyweight* f = new Flyweight();
	Character* test1 = f->hash(test[0]);
	Character* test2 = f->hash(test[1]);
	Character* test3 = f->hash(test[2]);

	EXPECT_EQ(test1, test3);
	EXPECT_NE(test1, test2);
	
}

#endif
