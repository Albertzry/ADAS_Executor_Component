#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp"
#include <iostream>
using namespace std;

namespace adas
{
TEST(ExecutorReverseTest, should_return_x_minus_1_given_status_is_reverse_command_is_BM_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BM");
    // then
    const Pose target{-1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_S_given_status_is_reverse_command_is_BL_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BL");
    // then
    const Pose target{0, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_y_plus_1_given_command_is_BBM_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    // when
    executor->Execute("BBM");
    // then
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_N__x_minus_1_given_command_is_BFR_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BFR");
    // then
    const Pose target{-1, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}  // namespace adas
}