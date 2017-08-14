
#include "list.h"
#include <gtest/gtest.h>

List *list = nullptr;

void destroy_data(void *data)
{
    free(data);
}

TEST(ListTest, ListInit)
{

    list = (List *)malloc(sizeof(List));
    EXPECT_NE(nullptr, list);

    list_init(list, nullptr);
    EXPECT_EQ(0, list_size(list));
    EXPECT_EQ(nullptr, list_head(list));

    list_init(list, destroy_data);
    EXPECT_EQ(0, list_size(list));
    EXPECT_EQ(nullptr, list_head(list));
}

TEST(ListTest, InsetItem)
{
    char *bytes = (char *)malloc(100);
    for ( int i = 0 ; i < 100 ; ++i ) {
        bytes[i] = i;
    }

    int list_old_length = list_size(list);

    int ret = list_insert_next(list, nullptr, (void *)bytes);

    EXPECT_EQ(0, ret);
    EXPECT_EQ(list_old_length + 1, list_size(list));
}

TEST(ListTest, RemoveItem)
{
    char *bytes = nullptr;

    int list_old_length = list_size(list);
    int ret = list_remove_next(list, nullptr, (void**)&bytes);

    EXPECT_EQ(0, ret);
    EXPECT_EQ(list_old_length - 1, list_size(list));

    for ( int i = 0 ; i < 100 ; ++i ) {
        EXPECT_EQ(i, bytes[i]);
    }

    free(bytes);
}

TEST(ListTest, DestroyList)
{
    list_destroy(list);

    EXPECT_EQ(0, list_size(list));
}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

