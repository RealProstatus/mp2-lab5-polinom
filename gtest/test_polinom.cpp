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

TEST(Polinom, mul_pol_with_const_0) {
	Polinom p;

	p += Monom{ 28,1,2,3 };
	p += Monom{ -5,3,4,5 };
	p += Monom{ 1,5,6,7 };
	EXPECT_EQ(p.getSize(), 3);

	p *= 0;

	EXPECT_EQ(p.getSize(), 0);
}

TEST(Polinom, mul_pol_with_const_1) {
	Polinom p;

	p += Monom{ 28,1,2,3 };
	p += Monom{ -5,3,4,5 };
	p += Monom{ 1,5,6,7 };
	EXPECT_EQ(p.getSize(), 3);

	p *= 1;

	EXPECT_EQ(p.getSize(), 3);
	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 1);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, -5);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, 28);
	p.goNext();
	EXPECT_TRUE(p.isEnd());
}

TEST(Polinom, mul_pol_with_const_negaative_1) {
	Polinom p;

	p += Monom{ 28,1,2,3 };
	p += Monom{ -5,3,4,5 };
	p += Monom{ 1,5,6,7 };
	EXPECT_EQ(p.getSize(), 3);

	p *= -1;

	EXPECT_EQ(p.getSize(), 3);
	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, -1);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, 5);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, -28);
	p.goNext();
	EXPECT_TRUE(p.isEnd());
}

TEST(Polinom, mul_pol_with_const_saves_ptrs) {
	Polinom p;

	p += Monom{ 28,1,2,3 };
	p += Monom{ -5,3,4,5 };
	p += Monom{ 1,5,6,7 };
	EXPECT_EQ(p.getSize(), 3);

	p.reset();
	p.goNext();

	EXPECT_EQ(p.getCurrentValue().coeff, -5);

	p *= 1;

	EXPECT_EQ(p.getCurrentValue().coeff, -5);
}

TEST(Polinom, mul_pol_with_mon) {
	Polinom p;

	p += Monom{ 5,1,1,0 };
	p += Monom{ -73,0,0,2 };
	p += Monom{ 64.5,1,5,1 };

	p *= Monom{ 5,1,1,1 };

	EXPECT_EQ(p.getSize(), 3);

	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 322.5);
	EXPECT_EQ(p.getCurrentValue().x,2);
	EXPECT_EQ(p.getCurrentValue().y,6);
	EXPECT_EQ(p.getCurrentValue().z,2);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, 25);
	EXPECT_EQ(p.getCurrentValue().x, 2);
	EXPECT_EQ(p.getCurrentValue().y, 2);
	EXPECT_EQ(p.getCurrentValue().z, 1);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, -365);
	EXPECT_EQ(p.getCurrentValue().x, 1);
	EXPECT_EQ(p.getCurrentValue().y, 1);
	EXPECT_EQ(p.getCurrentValue().z, 3);
}

TEST(Polinom, mul_pol_with_mon_with_0) {
	Polinom p;

	p += Monom{ 5,1,1,0 };
	p += Monom{ -73,0,0,2 };
	p += Monom{ 64.5,1,5,1 };

	p *= Monom{ 0,1,1,1 };

	EXPECT_EQ(p.getSize(), 0);
}

TEST(Polinom, mul_pol_with_mon_saves_ptrs) {
	Polinom p;

	p += Monom{ 5,1,1,0 };
	p += Monom{ -73,0,0,2 };
	p += Monom{ 64.5,1,5,1 };

	p.reset();
	p.goNext();

	EXPECT_EQ(p.getCurrentValue().coeff, 5);

	p *= Monom{ 5,1,1,1 };

	EXPECT_EQ(p.getCurrentValue().coeff, 25);
}

TEST(Polinom, pol_plus_pol_at_ending) {
	Polinom p,p1;

	p += Monom{ 28,1,0,0 };
	p += Monom{ -5,3,0,0 };
	p += Monom{ 1,5,0,0 };

	p1 += Monom{ 35,0,0,1 };
	p1 += Monom{ 68,0,5,0 };
	p1 += Monom{ 55.5,0,9,9 };

	p += p1;

	EXPECT_EQ(p.getSize(), 6);
	p.reset();
	EXPECT_EQ(p.getCurrentValue().coeff, 1);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, -5);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, 28);
	p.goNext();
	EXPECT_EQ(p.getCurrentValue().coeff, 55.5);
}