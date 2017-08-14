
#include "binarysearch.h"
#include <gtest/gtest.h>

#include <algorithm>
#include <random>

TEST(BinarySearch, IterSearch)
{
    std::vector<int> arr = std::vector<int>{1, 12, 15, 16, 17, 19, 30, 52, 55, 92};
    
    int index = binary_search(30, arr);
    EXPECT_EQ(6, index);

    index = binary_search(1, arr);
    EXPECT_EQ(0, index);

    index = binary_search(92, arr);
    EXPECT_EQ(9, index);

    index = binary_search(50, arr);
    EXPECT_EQ(-1, index);

    std::vector<long> arr2 = std::vector<long>{65331, 178239, 182436, 258557, 499682, 506961, 590055, 619904, 631781, 637956};

    index = binary_search(65331L, arr2);
    EXPECT_EQ(0, index);

    index = binary_search(637956L, arr2);
    EXPECT_EQ(9, index);

    index = binary_search(30L, arr2);
    EXPECT_EQ(-1, index);

    index = binary_search(619904L, arr2);
    EXPECT_EQ(619904, arr2[index]);
    EXPECT_EQ(7, index);

    std::random_device rd;
    std::default_random_engine el(rd());
    std::uniform_int_distribution<> dis(1, 67393535);

    std::vector<long> arr3;
    for (int i = 0; i < 10000; i++) {
        arr3.push_back(dis(el));
    }
    std::sort(std::begin(arr3), std::end(arr3));

    index = binary_search(arr3[500], arr3);
    EXPECT_EQ(500, index);
}

TEST(BinarySearch, RecursionSearch)
{
    std::vector<int> arr = std::vector<int>{1, 12, 15, 16, 17, 19, 30, 52, 55, 92};
    
    int index = binary_search_recursion(30, arr);
    EXPECT_EQ(6, index);

    index = binary_search_recursion(1, arr);
    EXPECT_EQ(0, index);

    index = binary_search_recursion(92, arr);
    EXPECT_EQ(9, index);

    index = binary_search_recursion(50, arr);
    EXPECT_EQ(-1, index);

    std::vector<long> arr2 = std::vector<long>{65331, 178239, 182436, 258557, 499682, 506961, 590055, 619904, 631781, 637956};

    index = binary_search_recursion(30L, arr2);
    EXPECT_EQ(-1, index);

    index = binary_search_recursion(65331L, arr2);
    EXPECT_EQ(0, index);

    index = binary_search_recursion(637956L, arr2);
    EXPECT_EQ(9, index);

    index = binary_search_recursion(619904L, arr2);
    EXPECT_EQ(619904, arr2[index]);
    EXPECT_EQ(7, index);

    std::random_device rd;
    std::default_random_engine el(rd());
    std::uniform_int_distribution<> dis(1, 67393535);

    std::vector<long> arr3;
    for (int i = 0; i < 10000; i++) {
        arr3.push_back(dis(el));
    }
    std::sort(std::begin(arr3), std::end(arr3));

    index = binary_search(arr3[500], arr3);
    EXPECT_EQ(500, index);
}
