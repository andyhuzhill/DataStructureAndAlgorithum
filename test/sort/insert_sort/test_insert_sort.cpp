
#include "../insert_sort.h"
#include <gtest/gtest.h>

int less_than(const void *key1, const void *key2)
{
    int *elem1 = (int *)key1;
    int *elem2 = (int *)key2;
    return *elem1 < *elem2;
}

TEST(InsertSort, InsertSort)
{
    int data[] = {231 , 252 , 233 , 97 , 226 , 199 , 82 , 96 , 82 , 165 ,};

    int sorted_data[] = {252, 233, 231, 226, 199, 165, 97, 96, 82, 82,};
    printf("Befort sort:\n");
    for (int i = 0; i < sizeof(data) / sizeof(int); ++i) {
        printf("data[%d] = %d\n", i, data[i]);
    }

    int ret = insert_sort(data, sizeof(data) / sizeof(int), sizeof(int), less_than);

    printf("After sort:\n");
    for (int i = 0; i < sizeof(data) / sizeof(int); ++i) {
        printf("data[%d] = %d\n", i, data[i]);
    }
    for (int i = 0; i < sizeof(data) / sizeof(int); ++i) {
        EXPECT_EQ(sorted_data[i], data[i]);
    }
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

