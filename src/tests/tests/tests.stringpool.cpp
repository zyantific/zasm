#include <gtest/gtest.h>
#include <zasm/core/stringpool.hpp>

namespace zasm::tests
{
    TEST(StringPoolTests, TestBasic)
    {
        StringPool pool;

        constexpr const char str1[] = "hello";
        constexpr const char str2[] = "Hello";

        const auto id0 = pool.aquire(str1);
        ASSERT_NE(id0, StringPool::Id::Invalid);
        ASSERT_EQ(pool.getLength(id0), std::size(str1));
        ASSERT_EQ(pool.getRefCount(id0), 1);
        const auto* cstr0 = pool.get(id0);
        ASSERT_NE(cstr0, nullptr);
        ASSERT_EQ(strcmp(cstr0, str1), 0);

        const auto id1 = pool.aquire(str1);
        ASSERT_NE(id1, StringPool::Id::Invalid);
        ASSERT_EQ(id1, id0);
        ASSERT_EQ(pool.getLength(id1), std::size(str1));
        ASSERT_EQ(pool.getRefCount(id1), 2);
        const auto* cstr1 = pool.get(id1);
        ASSERT_EQ(cstr1, cstr0);
        ASSERT_EQ(strcmp(cstr1, str1), 0);

        const auto id2 = pool.aquire(str2);
        ASSERT_NE(id2, StringPool::Id::Invalid);
        ASSERT_NE(id2, id1);
        ASSERT_EQ(pool.getLength(id2), std::size(str2));
        ASSERT_EQ(pool.getRefCount(id2), 1);
        const auto* cstr2 = pool.get(id2);
        ASSERT_EQ(strcmp(cstr2, str2), 0);
    }

    TEST(StringPoolTests, TestRelease)
    {
        StringPool pool;

        constexpr const char str1[] = "hello1";
        constexpr const char str2[] = "hello2";
        constexpr const char str3[] = "hello3";
        constexpr const char str4[] = "hello4";
        constexpr const char str5[] = "hello...";

        const auto id0 = pool.aquire(str1);
        ASSERT_NE(id0, StringPool::Id::Invalid);
        ASSERT_EQ(pool.getLength(id0), std::size(str1));
        ASSERT_EQ(pool.getRefCount(id0), 1);

        const auto id1 = pool.aquire(str2);
        ASSERT_NE(id1, StringPool::Id::Invalid);
        ASSERT_EQ(pool.getLength(id1), std::size(str2));
        ASSERT_EQ(pool.getRefCount(id1), 1);

        const auto id2 = pool.aquire(str3);
        ASSERT_NE(id2, StringPool::Id::Invalid);
        ASSERT_EQ(pool.getLength(id2), std::size(str3));
        ASSERT_EQ(pool.getRefCount(id2), 1);

        ASSERT_EQ(pool.release(id1), 0);
        const auto* cstr0 = pool.get(id1);
        ASSERT_EQ(cstr0, nullptr);

        const auto id3 = pool.aquire(str4);
        ASSERT_NE(id3, StringPool::Id::Invalid);
        ASSERT_EQ(id1, id3);
        ASSERT_EQ(pool.getLength(id3), std::size(str4));
        ASSERT_EQ(pool.getRefCount(id3), 1);

        const auto id4 = pool.aquire(str4);
        ASSERT_NE(id4, StringPool::Id::Invalid);
        ASSERT_EQ(id4, id3);
        ASSERT_EQ(pool.getLength(id4), std::size(str4));
        ASSERT_EQ(pool.getRefCount(id3), 2);

        ASSERT_EQ(pool.release(id4), 1);
        ASSERT_EQ(pool.release(id4), 0);

        const auto id5 = pool.aquire(str5);
        ASSERT_NE(id5, StringPool::Id::Invalid);
        ASSERT_NE(id5, id1);
        ASSERT_EQ(pool.getLength(id5), std::size(str5));
        ASSERT_EQ(pool.getRefCount(id5), 1);
    }

} // namespace zasm::tests