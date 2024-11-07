#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include "Executor.hpp"
namespace adas
{
bool operator==(const Pose& lhs, const Pose& rhs)
{  // 为Pose定义==运算符重载，使得在测试中比较Pose对象变得简单明了， std::tie提高代码可读性
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}

// M
TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("M");
    // then
    const Pose target({1, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    // when
    executor->Execute("M");
    // then
    const Pose target({-1, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    // when
    executor->Execute("M");
    // then
    const Pose target({0, 1, 'N'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    // when
    executor->Execute("M");
    // then
    const Pose target({0, -1, 'S'});
    ASSERT_EQ(target, executor->Query());
}
}
