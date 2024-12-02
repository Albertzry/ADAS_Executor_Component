#pragma once
#include "PoseHandler.hpp"
#include <functional>
#include "ActionGroup.hpp"

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

    // void operator()(PoseHandler& poseHandler) const noexcept
    // {
    //     poseHandler.Move();
    // }
ActionGroup operator()(PoseHandler& poseHandler) const noexcept
{
    ActionGroup actionGroup;
    const auto action =
        poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;

    if (poseHandler.IsFast()) {
        actionGroup.PushAction(action);
    }

    actionGroup.PushAction(action);
    return actionGroup;
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
    //  void operator()(PoseHandler& poseHandler) const noexcept
    // {
    //     poseHandler.TurnLeft();
    // }
ActionGroup operator()(PoseHandler& poseHandler) const noexcept
{
    ActionGroup actionGroup;
    const auto action =
        poseHandler.IsReverse() ? ActionType::REVERSE_TURNLEFT_ACTION : ActionType::TURNLEFT_ACTION;

    if (poseHandler.IsFast()) {
        if (poseHandler.IsReverse()) {
            actionGroup.PushAction(ActionType::BACKWARD_1_STEP_ACTION);
        }
        else {
            actionGroup.PushAction(ActionType::FORWARD_1_STEP_ACTION);
        }
    }

    actionGroup.PushAction(action);
    return actionGroup;
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

    //  void operator()(PoseHandler& poseHandler) const noexcept
    // {
    //     poseHandler.TurnRight();
    // }
ActionGroup operator()(PoseHandler& poseHandler) const noexcept
{
    ActionGroup actionGroup;
    const auto action =
        poseHandler.IsReverse() ? ActionType::REVERSE_TURNRIGHT_ACTION : ActionType::TURNRIGHT_ACTION;

    if (poseHandler.IsFast()) {
        if(poseHandler.IsReverse()) {
            actionGroup.PushAction(ActionType::BACKWARD_1_STEP_ACTION);
        }
        else {
            actionGroup.PushAction(ActionType::FORWARD_1_STEP_ACTION);
        }
    }

    actionGroup.PushAction(action);
    return actionGroup;
}
};

class FastCommand final //: public ICommand
{
public:
    // void DoOperate(PoseHandler& poseHandler) const noexcept override
    // {
    //     poseHandler.Fast();
    // }

    // void operator()(PoseHandler& poseHandler) const noexcept
    // {
    //     poseHandler.Fast();
    // }
ActionGroup operator()(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Fast();
    return ActionGroup();
}
};

class ReverseCommand final
{
public:
    // void operator()(PoseHandler& poseHandler) const noexcept
    // {
    //     poseHandler.Reverse();
    // }
ActionGroup operator()(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Reverse();
    return ActionGroup();
};
};

class TurnRoundCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsReverse()) {
            return ActionGroup();
        }

        if (poseHandler.IsFast()) {
            return ActionGroup({
                ActionType::FORWARD_1_STEP_ACTION,
                ActionType::TURNLEFT_ACTION,
                ActionType::FORWARD_1_STEP_ACTION,
                ActionType::TURNLEFT_ACTION
            });
        }

        return ActionGroup({
            ActionType::TURNLEFT_ACTION,
            ActionType::FORWARD_1_STEP_ACTION,
            ActionType::TURNLEFT_ACTION
        });
    }
};
} // namespace adas