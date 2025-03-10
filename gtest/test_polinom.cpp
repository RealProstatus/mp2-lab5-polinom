#include"gtest.h"
#include"../mp2-lab5-polinom/Polinom.h"
#include"../mp2-lab5-polinom/Polinom.cpp"

TEST(Polinom, add_mon_to_empty_pol) {
	Polinom p;
	Monom m{ 1,1,2,3 };

	p += m;
	EXPECT_EQ(p.getSize(), 1);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 1);
}

TEST(Polinom, add_greater_mon_than_first_mon_of_pol) {
	Polinom p;

	p += Monom{ 28,1,2,3 };
	p += Monom{ -5,3,4,5 };
	p += Monom{ 1,5,6,7 };
	EXPECT_EQ(p.getSize(), 3);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 1);

	p += Monom{ 12,9,9,9 };
	EXPECT_EQ(p.getSize(), 4);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 12);
}

TEST(Polinom, add_equal_mon_to_first_mon_of_pol) {
	Polinom p;

	p += Monom{ 28,1,2,3 };
	p += Monom{ -5,3,4,5 };
	p += Monom{ 1,5,6,7 };
	EXPECT_EQ(p.getSize(), 3);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 1);

	p += Monom{ 12,5,6,7 };
	EXPECT_EQ(p.getSize(), 3);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 13);
}

TEST(Polinom, add_equal_mon_to_first_mon_of_pol_with_delete) {
	Polinom p;

	p += Monom{ 28,1,2,3 };
	p += Monom{ -5,3,4,5 };
	p += Monom{ 1,5,6,7 };
	EXPECT_EQ(p.getSize(), 3);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 1);

	p += Monom{ -1,5,6,7 };
	EXPECT_EQ(p.getSize(), 2);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, -5);
}

TEST(Polinom, add_mon_is_lower_than_the_last_mon_of_pol) {
	Polinom p;

	p += Monom{ 28,1,2,3 };
	p += Monom{ -5,3,4,5 };
	EXPECT_EQ(p.getSize(), 2);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, -5);

	p += Monom{ -1,1,0,0 };
	EXPECT_EQ(p.getSize(), 3);

	p.reset();
	p.goNext();
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, -1);
}

TEST(Polinom, add_mon_is_equal_to_the_last_mon_of_pol) {
	Polinom p;

	p += Monom{ 28,1,2,3 };
	p += Monom{ -5,3,4,5 };
	EXPECT_EQ(p.getSize(), 2);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, -5);

	p += Monom{ -1,1,2,3 };
	EXPECT_EQ(p.getSize(), 2);

	p.reset();
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, 27);
}

TEST(Polinom, add_mon_is_equal_to_the_last_mon_of_pol_with_delete) {
	Polinom p;

	p += Monom{ 28,1,2,3 };
	p += Monom{ -5,3,4,5 };
	EXPECT_EQ(p.getSize(), 2);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, -5);

	p += Monom{ -28,1,2,3 };
	EXPECT_EQ(p.getSize(), 1);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, -5);
}

TEST(Polinom, add_mon_to_middle_of_pol) {
	Polinom p;

	p += Monom{ 28,1,2,3 };
	p += Monom{ -5,3,4,5 };
	p += Monom{ 1,5,6,7 };
	EXPECT_EQ(p.getSize(), 3);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 1);

	p += Monom{ 12,3,4,2 };
	EXPECT_EQ(p.getSize(), 4);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 1);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, -5);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, 12);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, 28);
}

TEST(Polinom, add_mon_to_middle_of_pol_with_equal_node) {
	Polinom p;

	p += Monom{ 28,1,2,3 };
	p += Monom{ -5,3,4,5 };
	p += Monom{ 1,5,6,7 };
	EXPECT_EQ(p.getSize(), 3);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 1);

	p += Monom{ 12,3,4,5 };
	EXPECT_EQ(p.getSize(), 3);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 1);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, 7);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, 28);
}

TEST(Polinom, add_mon_to_middle_of_pol_with_delete) {
	Polinom p;

	p += Monom{ 28,1,2,3 };
	p += Monom{ -5,3,4,5 };
	p += Monom{ 1,5,6,7 };
	EXPECT_EQ(p.getSize(), 3);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 1);

	p += Monom{ 5,3,4,5 };
	EXPECT_EQ(p.getSize(), 2);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 1);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, 28);
}