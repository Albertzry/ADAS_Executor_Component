#include "PoseHandler.hpp"

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept
    : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading))
{
}

void PoseHandler::Move() noexcept
{
    if (reverse) {
        point -= facing->Move();
        if (fast) {
            point -= facing->Move();
        }
    } else {
        point += facing->Move();
        if (fast) {
            point += facing->Move();
        }
    }
}

void PoseHandler::TurnLeft() noexcept
{
    if (reverse) {
        if (fast) {
            point -= facing->Move();
        }
        facing = &(facing->RightOne());
    } else {
        if (fast) {
            point += facing->Move();
        }
        facing = &(facing->LeftOne());
    }
}

void PoseHandler::TurnRight() noexcept
{
    if (reverse) {
        if (fast) {
            point -= facing->Move();
        }
        facing = &(facing->LeftOne());
    } else {
        if (fast) {
            point += facing->Move();
        }
        facing = &(facing->RightOne());
    }
}

void PoseHandler::Fast() noexcept
{
    fast = !fast;
}

bool PoseHandler::IsFast() const noexcept
{
    return fast;
}

Pose PoseHandler::Query() const noexcept
{
    return {point.GetX(), point.GetY(), facing->GetHeading()};
}

void PoseHandler::Forward() noexcept
{
    point += facing->Move();
}

void PoseHandler::Backward() noexcept
{
    point -= facing->Move();
}

void PoseHandler::Reverse() noexcept
{
    reverse = !reverse;
}

bool PoseHandler::IsReverse() const noexcept
{
    return reverse;
}
}  // namespace adas