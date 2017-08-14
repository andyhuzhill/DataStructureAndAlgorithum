
#include "../dlist.h"
#include <gtest/gtest.h>

DList *dlist = nullptr;

void destroy_data(void *data)
{
    free(data);
}

TEST(DListTest, DListInit)
{
    dlist = (DList *)malloc(sizeof(DList));
    EXPECT_NE(nullptr, dlist);

    dlist_init(dlist, nullptr);
    EXPECT_EQ(0, dlist_size(dlist));
    EXPECT_EQ(nullptr, dlist_head(dlist));

    dlist_init(dlist, destroy_data);
    EXPECT_EQ(0, dlist_size(dlist));
    EXPECT_EQ(nullptr, dlist_head(dlist));
}

TEST(DListTest, InsetItemNext)
{
    char *bytes = (char *)malloc(100);
    for ( int i = 0 ; i < 100 ; ++i ) {
        bytes[i] = i;
    }

    int dlist_old_length = dlist_size(dlist);

    int ret = dlist_insert_next(dlist, dlist_tail(dlist), (void *)bytes);
    
    EXPECT_EQ(0, ret);
    EXPECT_EQ(dlist_old_length + 1, dlist_size(dlist));
}

TEST(DListTest, InsertItemPrev)
{
    char *bytes = (char *)malloc(100);
    for ( int i = 0 ; i < 100 ; ++i ) {
        bytes[i] = 100 - i;
    }

    int dlist_old_length = dlist_size(dlist);

    int ret = dlist_insert_prev(dlist, dlist_head(dlist), (void *)bytes);

    EXPECT_EQ(0, ret);
    EXPECT_EQ(dlist_old_length + 1, dlist_size(dlist));
}

TEST(DListTest, RemoveItem)
{
    char *bytes = nullptr;

    int dlist_old_length = dlist_size(dlist);

    dlist_remove(dlist, dlist_head(dlist), (void**)&bytes);

    EXPECT_EQ(dlist_old_length - 1, dlist_size(dlist));

    for ( int i = 0 ; i < 100 ; ++i ) {
        EXPECT_EQ(100 - i, bytes[i]);
    }

    free(bytes);
    bytes = nullptr;

    dlist_old_length = dlist_size(dlist);

    dlist_remove(dlist, dlist_head(dlist), (void**)&bytes);

    EXPECT_EQ(dlist_old_length - 1, dlist_size(dlist));

    for (int i = 0 ; i < 100 ; ++i ) {
        EXPECT_EQ(i, bytes[i]);
    }

    free(bytes);
    bytes = nullptr;
}

TEST(DListTest, DestroyDList)
{
    dlist_destroy(dlist);

    EXPECT_EQ(0, dlist_size(dlist));
}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

