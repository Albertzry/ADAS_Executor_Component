#include "ActionGroup.hpp"
#include "PoseHandler.hpp"

namespace adas
{
    class ForwardAction final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            poseHandler.Forward();
        }
    };
    class BackwardAction final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            poseHandler.Backward();
        }
    };
    class TurnLeftAction final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            poseHandler.TurnLeft();
        }
    };
    class TurnRightAction final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            poseHandler.TurnRight();
        }
    };
    class FastAction final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            poseHandler.Fast();
        }
    };
    class ReverseAction final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            poseHandler.Reverse();
        }
    };
} // namespace adas