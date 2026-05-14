#include <gtest/gtest.h>
#include "../include/dotenv.hpp"

TEST(DotEnvTest, LoadDotEnvFile)
{
    dot_env env;
    EXPECT_EQ(env.load(".env.basic"), true);
}

TEST(DotEnvTest, LoadsBasicKeyValuePairs) 
{
    dot_env env;
    env.load(".env.basic");

    std::cout << "DB_HOST: " << env.get("DB_HOST") << std::endl;

    EXPECT_EQ(env.get("DB_HOST"), "localhost");
    EXPECT_EQ(env.get("DB_PORT"), "5432");
}

TEST(DotEnvTest, IgnoresComments) 
{
    dot_env env;
    env.load(".env.comments");

    EXPECT_EQ(env.get("KEY1"), "value1");
    EXPECT_EQ(env.get("KEY2"), "value2");
}

TEST(DotEnvTest, ReturnsEmptyIfKeyNotFound) 
{
    dot_env env;
    env.load(".env.basic");

    EXPECT_EQ(env.get("UNKNOWN"), "");
}

TEST(DotEnvTest, ReturnsDefaultValue) 
{
    dot_env env;
    env.load(".env.basic");

    EXPECT_EQ(env.get_or("UNKNOWN", "default"), "default");
}