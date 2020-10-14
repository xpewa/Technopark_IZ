#include <gtest/gtest.h>
#include "../functions.h"

void InsertionSort(t_symbol* mas, int Size) {
    for (int i = 1; i < Size; ++i) {
        t_symbol temp = mas[i];
        int j = i-1;
        for (; j>=0 && temp.count < mas[j].count; --j)
            mas[j+1] = mas[j];
        mas[j+1] = temp;
    }
}

TEST(test001, InsertionSort) {
    t_symbol a;
    a.count = 3;
    t_symbol b;
    b.count = 0;
    t_symbol c;
    c.count = 0;
    t_symbol d;
    d.count = 1;
    t_symbol e;
    e.count = 2;
    t_symbol mas[] = {a, b, c, d, e};

    InsertionSort(mas, 5);

    ASSERT_EQ(mas[0].count, 0);
    ASSERT_EQ(mas[1].count, 0);
    ASSERT_EQ(mas[2].count, 1);
    ASSERT_EQ(mas[3].count, 2);
    ASSERT_EQ(mas[4].count, 3);
}
TEST(test002, InsertionSort) {
    t_symbol a;
    a.count = 0;
    t_symbol b;
    b.count = 0;
    t_symbol c;
    c.count = 0;
    t_symbol mas[] = {a, b, c};

    InsertionSort(mas, 3);

    ASSERT_EQ(mas[0].count, 0);
    ASSERT_EQ(mas[1].count, 0);
    ASSERT_EQ(mas[2].count, 0);
}
