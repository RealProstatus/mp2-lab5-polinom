#include"gtest.h"
#include"../mp2-lab5-polinom/TList.h"

TEST(TList, empty_list_creation) {
    ASSERT_NO_THROW(TList<int> list);
    ASSERT_NO_FATAL_FAILURE(TList<int> list2);
}

TEST(TListTest, insert_first_empty) {
    TList<int> list;
    ASSERT_NO_THROW(list.insertFirst(42));
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TListTest, insert_first_not_empty) {
    TList<int> list;
    list.insertFirst(10);
    ASSERT_NO_THROW(list.insertFirst(20));
    EXPECT_EQ(list.getSize(), 2);
}

TEST(TListTest, delete_first_not_empty) {
    TList<int> list;
    list.insertFirst(10);
    list.insertFirst(20);
    ASSERT_NO_THROW(list.deleteFirst());
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TListTest, delete_first_single_element) {
    TList<int> list;
    list.insertFirst(100);
    ASSERT_NO_THROW(list.deleteFirst());
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TListTest, insert_last_empty) {
    TList<int> list;
    ASSERT_NO_THROW(list.insertLast(99));
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TListTest, insert_last_not_empty) {
    TList<int> list;
    list.insertLast(10);
    ASSERT_NO_THROW(list.insertLast(20));
    EXPECT_EQ(list.getSize(), 2);
}

TEST(TListTest, delete_last_two_elements) {
    TList<int> list;
    list.insertLast(10);
    list.insertLast(20);
    ASSERT_NO_THROW(list.deleteLast());
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TListTest, delete_last_single_element) {
    TList<int> list;
    list.insertLast(55);
    ASSERT_NO_THROW(list.deleteLast());
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TListTest, ñopy_ñonstructor) {
    TList<int> original;
    original.insertLast(1);
    original.insertLast(2);
    TList<int> copy(original);
    copy.deleteLast();
    EXPECT_EQ(original.getSize(), 2);
    EXPECT_EQ(copy.getSize(), 1);
}

TEST(TListTest, destructor_has_no_leaks) {
    TList<int>* list = new TList<int>();
    list->insertLast(1);
    list->insertLast(2);
    delete list;
    SUCCEED();
}

TEST(TListTest, combined_operations) {
    TList<int> list;
    list.insertFirst(3);
    list.insertLast(4);
    list.deleteFirst();
    list.insertFirst(2);
    list.deleteLast();
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TListTest, delete_from_empty_list) {
    TList<int> list;
    list.deleteFirst();
    list.deleteLast();
    EXPECT_EQ(list.getSize(), 0);
}