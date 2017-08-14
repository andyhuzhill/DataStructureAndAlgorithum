
#include "strings.h"
#include <gtest/gtest.h>
#include <string.h>
#include <limits.h>

TEST(StringsTest, StringLength)
{
    const char *test1 = "Hello world!";
    EXPECT_EQ(12, my_strlen(test1));

    char test2[] = "Good morning!";
    EXPECT_EQ(13, my_strlen(test2));

    char *test3 = new char[15];
    memset(test3, 0, 15);

    for (int i = 0; i < 14; ++i) {
        test3[i] = i +  'A';
    }

    EXPECT_EQ(14, my_strlen(test3));

    delete[] test3;
}

TEST(StringsTest, StringCopy)
{
    char empty[12] = {0};
    char *result = my_strcpy(&empty[0], "Hello world");
    EXPECT_STREQ("Hello world", empty);
    EXPECT_EQ(result, empty);
    EXPECT_NE(nullptr, result);
    EXPECT_EQ(11, strlen(result));
    EXPECT_EQ(0, strcmp("Hello world", result));
    ASSERT_STREQ("Hello world", result);
}

TEST(StringsTest, StringSubstr)
{
    const char *test1 = "Good morning, everyone!";
    const char *test2 = "everyone";
    const char *test3 = "After";
   
    EXPECT_STREQ("everyone!", my_strstr1(test1, test2));
    EXPECT_STRNE("After", my_strstr1(test1, test3));
}

TEST(StringsTest, Atoi)
{
    EXPECT_EQ(-3924, my_atoi("-3924x8fc"));
    EXPECT_EQ(413, my_atoi("  +413"));
    EXPECT_EQ(0, my_atoi("++c"));
    EXPECT_EQ(0, my_atoi("++1"));
    EXPECT_EQ(8, my_atoi("008"));
    EXPECT_EQ(1, my_atoi("1e45"));
    EXPECT_EQ(0, my_atoi(""));
    EXPECT_EQ(INT_MAX, my_atoi("2147483648"));
}

TEST(StringsTest, HasUniqueCharacters)
{
    EXPECT_EQ(true, has_all_unique_char("ABCD"));
    EXPECT_EQ(false, has_all_unique_char("Hello world"));
    EXPECT_EQ(true, has_all_unique_char(""));
    EXPECT_EQ(false, has_all_unique_char("     "));
}

TEST(StringsTest, RevertString)
{
    char str1[] = "ABCDEFG";
    char str2[] = "ABCDEFGH";
    char str3[] = "";
    EXPECT_STREQ("GFEDCBA", revert_string(str1));
    EXPECT_STREQ("HGFEDCBA", revert_string(str2));
    EXPECT_STREQ("", revert_string(str3));
}

TEST(StringsTest, RemoveDuplicateCharacters)
{
    char str1[] = "ABCDEFHIJKABC";
    char str2[] = "hello world";
    char str3[] = "CDEFGHIJKLMNO";
    char str4[] = "";
    char str5[] = "aaaa";
    char str6[] = "aaabbb";
    char str7[] = "ababab";

    EXPECT_STREQ("ABCDEFHIJK", remove_duplicate_char(str1));
    EXPECT_STREQ("helo wrd", remove_duplicate_char(str2));
    EXPECT_STREQ("CDEFGHIJKLMNO", remove_duplicate_char(str3));
    EXPECT_STREQ("", remove_duplicate_char(str4));
    EXPECT_STREQ("a", remove_duplicate_char(str5));
    EXPECT_STREQ("ab", remove_duplicate_char(str6));
    EXPECT_STREQ("ab", remove_duplicate_char(str7));
}

TEST(StringsTest, IsAnagramString)
{
    char str1[] = "Hello abcd";
    char str2[] = "cdba olehl";

    EXPECT_EQ(true, is_anagram_string(str1, str2));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

