#include <gtest/gtest.h>
#include <random>

#define IN_TESTS
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
        ASSERT_EQ(pool.getLength(id0), std::size(str1) - 1);
        ASSERT_EQ(pool.getRefCount(id0), 1);
        const auto* cstr0 = pool.get(id0);
        ASSERT_NE(cstr0, nullptr);
        ASSERT_EQ(strcmp(cstr0, str1), 0);

        const auto id1 = pool.aquire(str1);
        ASSERT_NE(id1, StringPool::Id::Invalid);
        ASSERT_EQ(id1, id0);
        ASSERT_EQ(pool.getLength(id1), std::size(str1) - 1);
        ASSERT_EQ(pool.getRefCount(id1), 2);
        const auto* cstr1 = pool.get(id1);
        ASSERT_EQ(cstr1, cstr0);
        ASSERT_EQ(strcmp(cstr1, str1), 0);

        const auto id2 = pool.aquire(str2);
        ASSERT_NE(id2, StringPool::Id::Invalid);
        ASSERT_NE(id2, id1);
        ASSERT_EQ(pool.getLength(id2), std::size(str2) - 1);
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
        ASSERT_EQ(pool.getLength(id0), std::size(str1) - 1);
        ASSERT_EQ(pool.getRefCount(id0), 1);

        const auto id1 = pool.aquire(str2);
        ASSERT_NE(id1, StringPool::Id::Invalid);
        ASSERT_EQ(pool.getLength(id1), std::size(str2) - 1);
        ASSERT_EQ(pool.getRefCount(id1), 1);

        const auto id2 = pool.aquire(str3);
        ASSERT_NE(id2, StringPool::Id::Invalid);
        ASSERT_EQ(pool.getLength(id2), std::size(str3) - 1);
        ASSERT_EQ(pool.getRefCount(id2), 1);

        ASSERT_EQ(pool.release(id1), 0);
        const auto* cstr0 = pool.get(id1);
        ASSERT_EQ(cstr0, nullptr);

        const auto id3 = pool.aquire(str4);
        ASSERT_NE(id3, StringPool::Id::Invalid);
        ASSERT_EQ(id1, id3);
        ASSERT_EQ(pool.getLength(id3), std::size(str4) - 1);
        ASSERT_EQ(pool.getRefCount(id3), 1);

        const auto id4 = pool.aquire(str4);
        ASSERT_NE(id4, StringPool::Id::Invalid);
        ASSERT_EQ(id4, id3);
        ASSERT_EQ(pool.getLength(id4), std::size(str4) - 1);
        ASSERT_EQ(pool.getRefCount(id3), 2);

        ASSERT_EQ(pool.release(id4), 1);
        ASSERT_EQ(pool.release(id4), 0);

        const auto id5 = pool.aquire(str5);
        ASSERT_NE(id5, StringPool::Id::Invalid);
        ASSERT_EQ(id5, id1);
        ASSERT_EQ(pool.getLength(id5), std::size(str5) - 1);
        ASSERT_EQ(pool.getRefCount(id5), 1);
    }

    constexpr auto kTestSize = 100'000;

    static constexpr const char kChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    static const std::vector<std::string> kInputStrings = []() {
        std::vector<std::string> strings;
        std::set<std::string> uniqueStrings;
        std::mt19937 prng(42);
        while (uniqueStrings.size() < kTestSize)
        {
            std::string str;
            for (size_t i = 0; i < 4 + (prng() % 24); ++i)
            {
                str.push_back(kChars[prng() % (sizeof(kChars) - 1)]);
            }
            uniqueStrings.emplace(std::move(str));
        }
        strings.insert(strings.end(), uniqueStrings.begin(), uniqueStrings.end());
        return strings;
    }();

    const auto fillPool = [](StringPool& pool, std::vector<StringPool::Id>& ids) {
        ids.clear();
        for (const auto& str : kInputStrings)
        {
            const auto id = pool.aquire(str);
            ASSERT_NE(id, StringPool::Id::Invalid);
            ASSERT_EQ(pool.getLength(id), str.size());
            ASSERT_EQ(pool.getRefCount(id), 1);

            const auto* cstr = pool.get(id);
            ASSERT_NE(cstr, nullptr);
            ASSERT_EQ(strcmp(cstr, str.c_str()), 0);

            ids.push_back(id);
        }
        ASSERT_EQ(ids.size(), kInputStrings.size());
    };

    TEST(StringPoolTests, TestManyStrings)
    {
        StringPool pool;
        std::vector<StringPool::Id> ids;

        fillPool(pool, ids);

        // Validate that the contents still match.
        for (size_t i = 0; i < kTestSize; i++)
        {
            const auto& str = kInputStrings[i];
            const auto* cstr = pool.get(ids[i]);
            ASSERT_NE(cstr, nullptr);
            ASSERT_EQ(strcmp(cstr, str.c_str()), 0);
        }
    }

    TEST(StringPoolTests, TestClearIndividually)
    {
        StringPool pool;
        std::vector<StringPool::Id> ids;

        fillPool(pool, ids);

        // Clear.
        for (auto id : ids)
        {
            ASSERT_EQ(pool.release(id), 0);
        }

        ASSERT_EQ(pool.size(), 0);
    }

    TEST(StringPoolTests, TestReuseSingle)
    {
        StringPool pool;
        std::vector<StringPool::Id> ids;

        fillPool(pool, ids);

        // Validate strings.
        for (auto i = 0U; i < kTestSize; i++)
        {
            const auto& str = kInputStrings[i];

            const auto* cstr = pool.get(ids[i]);
            ASSERT_NE(cstr, nullptr) << "i = " << i;
            ASSERT_EQ(strcmp(cstr, str.c_str()), 0) << "i = " << i;
        }

        // Clear.
        for (auto id : ids)
        {
            ASSERT_EQ(pool.release(id), 0);
        }

        fillPool(pool, ids);

        // Validate strings.
        for (auto i = 0U; i < kTestSize; i++)
        {
            const auto& str = kInputStrings[i];

            const auto* cstr = pool.get(ids[i]);
            ASSERT_NE(cstr, nullptr) << "i = " << i;
            ASSERT_EQ(strcmp(cstr, str.c_str()), 0) << "i = " << i;
        }
    }

    TEST(StringPoolTests, TestReuseMultiple)
    {
        StringPool pool;
        std::vector<StringPool::Id> ids;

        for (size_t i = 0; i < 5; i++)
        {
            fillPool(pool, ids);

            // Validate that the contents still match.
            for (auto i = 0U; i < kTestSize; i++)
            {
                const auto& str = kInputStrings[i];

                const auto* cstr = pool.get(ids[i]);
                ASSERT_NE(cstr, nullptr);
                ASSERT_EQ(strcmp(cstr, str.c_str()), 0);
            }

            // Clear.
            for (auto id : ids)
            {
                ASSERT_EQ(pool.release(id), 0);
            }
        }
    }

} // namespace zasm::tests
