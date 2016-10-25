
#include "../stack.h"
#include <gtest/gtest.h>

Stack *stack = nullptr;

void destroy_data(void *data)
{
    free(data);
}

TEST(StackTest, StackInit)
{
    stack = (Stack *)malloc(sizeof(Stack));
    EXPECT_NE(nullptr, stack);

    stack_init(stack, nullptr);
    EXPECT_EQ(0, stack_size(stack));

    stack_init(stack, destroy_data);
    EXPECT_EQ(0, stack_size(stack));
}

TEST(StackTest, PushItem)
{
    char *bytes = (char *)malloc(100);
    for ( int i = 0 ; i < 100 ; ++i ) {
        bytes[i] = i;
    }

    int stack_old_length = stack_size(stack);

    int ret = stack_push(stack, bytes);

    EXPECT_EQ(0, ret);
    EXPECT_EQ(stack_old_length + 1, stack_size(stack));
}

TEST(StackTest, PeekItem)
{
    char *bytes = nullptr;

    int stack_old_length = stack_size(stack);
    bytes = (char *)stack_peek(stack);

    EXPECT_EQ(stack_old_length, stack_size(stack));

    for ( int i = 0 ; i < 100 ; ++i ) {
        EXPECT_EQ(i, bytes[i]);
    }
}

TEST(StackTest, PopItem)
{
    char *bytes = nullptr;

    int stack_old_length = stack_size(stack);
    int ret = stack_pop(stack, (void **)&bytes);

    EXPECT_EQ(0, ret);
    EXPECT_EQ(stack_old_length - 1, stack_size(stack));

    for ( int i = 0 ; i < 100 ; ++i ) {
        EXPECT_EQ(i, bytes[i]);
    }

    free(bytes);
}

TEST(StackTest, DestroyStack)
{
    stack_destroy(stack);

    EXPECT_EQ(0, stack_size(stack));
}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


