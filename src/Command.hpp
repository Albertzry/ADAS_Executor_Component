#pragma once
#include "PoseHandler.hpp"
#include <functional>
namespace adas
{
// class ICommand
// {
// public:
//     virtual ~ICommand() = default;
//     virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
// };

class MoveCommand final //: public ICommand
{
public:
    // void DoOperate(PoseHandler& poseHandler) const noexcept override
    // {
    //     if (poseHandler.IsFast()) {
    //         poseHandler.Move();
    //     }
    //     poseHandler.Move();
    // }
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Move();
    }
};

class TurnLeftCommand final //: public ICommand
{
public:
    // void DoOperate(PoseHandler& poseHandler) const noexcept override
    // {
    //     if (poseHandler.IsFast()) {
    //         poseHandler.Move();
    //     }
    //     poseHandler.TurnLeft();
    // }
     void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnLeft();
    }

};

class TurnRightCommand final //: public ICommand
{
public:
    // void DoOperate(PoseHandler& poseHandler) const noexcept override
    // {
    //     if (poseHandler.IsFast()) {
    //         poseHandler.Move();
    //     }
    //     poseHandler.TurnRight();
    // }
     void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnRight();
    }
};

class FastCommand final //: public ICommand
{
public:
    // void DoOperate(PoseHandler& poseHandler) const noexcept override
    // {
    //     poseHandler.Fast();
    // }
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Fast();
    }
};

class ReverseCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Reverse();
    }
};


} // namespace adas