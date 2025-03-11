#include"gtest.h"
#include"../mp2-lab5-polinom/TList.h"

TEST(TList, empty_list_creation) {
    ASSERT_NO_THROW(TList<int> list);
    ASSERT_NO_FATAL_FAILURE(TList<int> list2);
}

TEST(TList, insert_first_empty) {
    TList<int> list;
    ASSERT_NO_THROW(list.insertFirst(42));
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TList, insert_first_not_empty) {
    TList<int> list;
    list.insertFirst(10);
    ASSERT_NO_THROW(list.insertFirst(20));
    EXPECT_EQ(list.getSize(), 2);
}

TEST(TList, delete_first_not_empty) {
    TList<int> list;
    list.insertFirst(10);
    list.insertFirst(20);
    ASSERT_NO_THROW(list.deleteFirst());
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TList, delete_first_single_element) {
    TList<int> list;
    list.insertFirst(100);
    ASSERT_NO_THROW(list.deleteFirst());
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TList, insert_last_empty) {
    TList<int> list;
    ASSERT_NO_THROW(list.insertLast(99));
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TList, insert_last_not_empty) {
    TList<int> list;
    list.insertLast(10);
    ASSERT_NO_THROW(list.insertLast(20));
    EXPECT_EQ(list.getSize(), 2);
}

TEST(TList, delete_last_two_elements) {
    TList<int> list;
    list.insertLast(10);
    list.insertLast(20);
    ASSERT_NO_THROW(list.deleteLast());
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TList, delete_last_single_element) {
    TList<int> list;
    list.insertLast(55);
    ASSERT_NO_THROW(list.deleteLast());
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TList, copy_constructor) {
    TList<int> original;
    original.insertLast(1);
    original.insertLast(2);
    TList<int> copy(original);
    copy.deleteLast();
    EXPECT_EQ(original.getSize(), 2);
    EXPECT_EQ(copy.getSize(), 1);
}

TEST(TList, destructor_has_no_leaks) {
    TList<int>* list = new TList<int>();
    list->insertLast(1);
    list->insertLast(2);
    delete list;
    SUCCEED();
}

TEST(TList, combined_operations_1) {
    TList<int> list;
    list.insertFirst(3);
    list.insertLast(4);
    list.deleteFirst();
    list.insertFirst(2);
    list.deleteLast();
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TList, delete_from_empty_list) {
    TList<int> list;
    list.deleteFirst();
    list.deleteLast();
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TList, insert_current_in_empty) {
    TList<int> list;
    list.insertCurrent(10);
    list.reset();

    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.getCurrentValue(), 10);
}

TEST(TList, insert_current_at_first_position) {
    TList<int> list;
    list.insertFirst(20);
    list.reset();

    list.insertCurrent(10);

    EXPECT_EQ(list.getSize(), 2);
    list.reset();
    EXPECT_EQ(list.getCurrentValue(), 10);
    list.goNext();
    EXPECT_EQ(list.getCurrentValue(), 20);
}

TEST(TList, insert_current_in_middle) {
    TList<int> list;
    list.insertLast(10);
    list.insertLast(30);
    list.reset();
    list.goNext();

    list.insertCurrent(20);

    EXPECT_EQ(list.getSize(), 3);
    list.reset();
    EXPECT_EQ(list.getCurrentValue(), 10);
    list.goNext();
    EXPECT_EQ(list.getCurrentValue(), 20);
    list.goNext();
    EXPECT_EQ(list.getCurrentValue(), 30);
}

TEST(TList, delete_current_when_single_element) {
    TList<int> list;
    list.insertCurrent(42);

    list.reset();
    list.deleteCurrent();

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.isEnd());
}

TEST(TList, delete_first_element) {
    TList<int> list;
    list.insertLast(10);
    list.insertLast(20);
    list.reset();

    list.deleteCurrent();

    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.getCurrentValue(), 20);
}

TEST(TList, delete_middle_element) {
    TList<int> list;
    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);
    list.reset();
    list.goNext();

    list.deleteCurrent();

    EXPECT_EQ(list.getSize(), 2);
    EXPECT_EQ(list.getCurrentValue(), 30);
    list.reset();
    EXPECT_EQ(list.getCurrentValue(), 10);
    list.goNext();
    EXPECT_EQ(list.getCurrentValue(), 30);
}

TEST(TList, delete_last_element) {
    TList<int> list;
    list.insertLast(10);
    list.insertLast(20);
    list.reset();
    list.goNext();

    list.deleteCurrent();

    EXPECT_EQ(list.getSize(), 1);
    EXPECT_TRUE(list.isEnd());
}

TEST(TList, combined_operations_2) {
    TList<int> list;
    list.insertCurrent(30);
    list.reset();
    list.insertCurrent(10);
    
    list.goNext();
    list.insertCurrent(20);

    list.reset();
    list.goNext();
    list.deleteCurrent();

    EXPECT_EQ(list.getSize(), 2);
    list.reset();
    EXPECT_EQ(list.getCurrentValue(), 10);
    list.goNext();
    EXPECT_EQ(list.getCurrentValue(), 20);
}