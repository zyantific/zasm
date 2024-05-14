#include <chrono>
#include <gtest/gtest.h>
#include <zasm/core/errors.hpp>

namespace zasm::tests
{
    TEST(ErrorTests, TestBasic)
    {
        Error error(ErrorCode::InvalidMode);
        ASSERT_EQ(error, ErrorCode::InvalidMode);
        ASSERT_EQ(error.getCode(), ErrorCode::InvalidMode);
    }

    TEST(ErrorTests, TestExt)
    {
        Error error(ErrorCode::InvalidMode, "test message");
        ASSERT_EQ(error, ErrorCode::InvalidMode);
        ASSERT_EQ(error.getCode(), ErrorCode::InvalidMode);
        ASSERT_EQ(error.getErrorMessage(), std::string("test message"));
    }

    TEST(ErrorTests, TestExtClear)
    {
        Error error(ErrorCode::InvalidMode, "test message");
        ASSERT_EQ(error, ErrorCode::InvalidMode);
        ASSERT_EQ(error.getCode(), ErrorCode::InvalidMode);
        ASSERT_EQ(error.getErrorMessage(), std::string("test message"));

        error.clear();
        ASSERT_TRUE(error.empty());
        ASSERT_EQ(error, ErrorCode::None);
    }

    TEST(ErrorTests, TestCopy1)
    {
        Error error(ErrorCode::InvalidMode);
        ASSERT_EQ(error, ErrorCode::InvalidMode);
        ASSERT_EQ(error.getCode(), ErrorCode::InvalidMode);

        Error error2(error);
        ASSERT_EQ(error2, ErrorCode::InvalidMode);
        ASSERT_EQ(error2.getCode(), ErrorCode::InvalidMode);
    }

    TEST(ErrorTests, TestCopy2)
    {
        Error error(ErrorCode::InvalidMode);
        ASSERT_EQ(error, ErrorCode::InvalidMode);
        ASSERT_EQ(error.getCode(), ErrorCode::InvalidMode);

        Error error2;
        error2 = error;
        ASSERT_EQ(error2, ErrorCode::InvalidMode);
        ASSERT_EQ(error2.getCode(), ErrorCode::InvalidMode);
    }

    TEST(ErrorTests, TestCopyExt1)
    {
        Error error(ErrorCode::InvalidMode, "test message");
        ASSERT_EQ(error, ErrorCode::InvalidMode);
        ASSERT_EQ(error.getCode(), ErrorCode::InvalidMode);
        ASSERT_EQ(error.getErrorMessage(), std::string("test message"));

        Error error2(error);
        ASSERT_EQ(error2, ErrorCode::InvalidMode);
        ASSERT_EQ(error2.getCode(), ErrorCode::InvalidMode);
        ASSERT_EQ(error2.getErrorMessage(), std::string("test message"));
    }

    TEST(ErrorTests, TestCopyExt2)
    {
        Error error(ErrorCode::InvalidMode, "test message");
        ASSERT_EQ(error, ErrorCode::InvalidMode);
        ASSERT_EQ(error.getCode(), ErrorCode::InvalidMode);
        ASSERT_EQ(error.getErrorMessage(), std::string("test message"));

        Error error2;
        error2 = error;
        ASSERT_EQ(error2, ErrorCode::InvalidMode);
        ASSERT_EQ(error2.getCode(), ErrorCode::InvalidMode);
        ASSERT_EQ(error2.getErrorMessage(), std::string("test message"));
    }

    TEST(ErrorTests, TestMoveExt1)
    {
        Error error(ErrorCode::InvalidMode, "test message");
        ASSERT_EQ(error, ErrorCode::InvalidMode);
        ASSERT_EQ(error.getCode(), ErrorCode::InvalidMode);
        ASSERT_EQ(error.getErrorMessage(), std::string("test message"));

        Error error2(std::move(error));
        ASSERT_EQ(error2, ErrorCode::InvalidMode);
        ASSERT_EQ(error2.getCode(), ErrorCode::InvalidMode);
        ASSERT_EQ(error2.getErrorMessage(), std::string("test message"));

        ASSERT_TRUE(error.empty());
    }

    TEST(ErrorTests, TestMoveExt2)
    {
        Error error(ErrorCode::InvalidMode, "test message");
        ASSERT_EQ(error, ErrorCode::InvalidMode);
        ASSERT_EQ(error.getCode(), ErrorCode::InvalidMode);
        ASSERT_EQ(error.getErrorMessage(), std::string("test message"));

        Error error2;
        error2 = std::move(error);
        ASSERT_EQ(error2, ErrorCode::InvalidMode);
        ASSERT_EQ(error2.getCode(), ErrorCode::InvalidMode);
        ASSERT_EQ(error2.getErrorMessage(), std::string("test message"));

        ASSERT_TRUE(error.empty());
    }

#if defined(_DEBUG) && 0
    // Leak Tests.
    // Disabled by default, this is a very crude way to test for memory leaks.
    // The process runs for 5 seconds and creates/destroys Error objects in where we can observe
    // if the memory usage is stable.

    static constexpr auto kLeakTestDurationSecs = std::chrono::milliseconds(5000);

    TEST(ErrorTests, TestLeak1)
    {
        auto start = std::chrono::high_resolution_clock::now();
        while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start)
               < kLeakTestDurationSecs)
        {
            Error error(ErrorCode::InvalidMode, "test message");
            ASSERT_EQ(error, ErrorCode::InvalidMode);
            ASSERT_EQ(error.getCode(), ErrorCode::InvalidMode);
            ASSERT_EQ(error.getErrorMessage(), std::string("test message"));
        }
    }

    TEST(ErrorTests, TestLeak2)
    {
        auto start = std::chrono::high_resolution_clock::now();
        while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start)
               < kLeakTestDurationSecs)
        {
            Error error(ErrorCode::InvalidMode, "test message");
            ASSERT_EQ(error, ErrorCode::InvalidMode);
            ASSERT_EQ(error.getCode(), ErrorCode::InvalidMode);
            ASSERT_EQ(error.getErrorMessage(), std::string("test message"));

            Error error2(std::move(error));
            ASSERT_EQ(error2, ErrorCode::InvalidMode);
            ASSERT_EQ(error2.getCode(), ErrorCode::InvalidMode);
            ASSERT_EQ(error2.getErrorMessage(), std::string("test message"));
        }
    }

    TEST(ErrorTests, TestLeak3)
    {
        auto start = std::chrono::high_resolution_clock::now();
        while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start)
               < kLeakTestDurationSecs)
        {
            Error error(ErrorCode::InvalidMode, "test message");
            ASSERT_EQ(error, ErrorCode::InvalidMode);
            ASSERT_EQ(error.getCode(), ErrorCode::InvalidMode);
            ASSERT_EQ(error.getErrorMessage(), std::string("test message"));

            Error error2;
            error2 = std::move(error);
            ASSERT_EQ(error2, ErrorCode::InvalidMode);
            ASSERT_EQ(error2.getCode(), ErrorCode::InvalidMode);
            ASSERT_EQ(error2.getErrorMessage(), std::string("test message"));
        }
    }

    TEST(ErrorTests, TestLeak4)
    {
        auto start = std::chrono::high_resolution_clock::now();
        while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start)
               < kLeakTestDurationSecs)
        {
            Error error(ErrorCode::InvalidMode, "test message");
            ASSERT_EQ(error, ErrorCode::InvalidMode);
            ASSERT_EQ(error.getCode(), ErrorCode::InvalidMode);
            ASSERT_EQ(error.getErrorMessage(), std::string("test message"));

            error.clear();
            ASSERT_TRUE(error.empty());
            ASSERT_EQ(error, ErrorCode::None);
        }
    }
#endif

} // namespace zasm::tests
