#pragma once
#include "ExecutorImpl.hpp"

namespace adas
{
class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
};

class MoveCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        // 实现代码
    }
};

class TurnLeftCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        // 实现代码
    }
};

class TurnRightCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        // 实现代码
    }
};

class FastCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        // 实现代码
    }
};
} // namespace adas