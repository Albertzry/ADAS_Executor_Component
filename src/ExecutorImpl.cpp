#include "ExecutorImpl.hpp"
#include <memory>
#include "Command.hpp"
#include <unordered_map>

namespace adas
{
    Executor* Executor::NewExecutor(const Pose& pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }
    ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : poseHandler(pose)
    {
    }

    void ExecutorImpl::Execute(const std::string& commands) noexcept
    {
    //     for (const auto cmd : commands)
    //     {
    //         std::unique_ptr<ICommand> cmder;
    //         if (cmd == 'M')
    //         {
    //             cmder = std::make_unique<MoveCommand>();
    //         }
    //         else if (cmd == 'L')
    //         {
    //             cmder = std::make_unique<TurnLeftCommand>();
    //         }
    //         else if (cmd == 'R')
    //         {
    //             cmder = std::make_unique<TurnRightCommand>();
    //         }
    //         else if (cmd == 'F')
    //         {
    //             cmder = std::make_unique<FastCommand>();
    //         }
    //         else if (cmd == 'B') {
    //             cmder = std::make_unique<ReverseCommand>();
    //         }
    //         if (cmder) {
    //             cmder->DoOperate(*this);
    //         }
    //     }

        // std::unordered_map<char, std::function<void(PoseHandler & poseHandler)>> cmderMap;
        // cmderMap.emplace('M', MoveCommand());
        // cmderMap.emplace('L', TurnLeftCommand());
        // cmderMap.emplace('R', TurnRightCommand());
        // cmderMap.emplace('F', FastCommand());

        const std::unordered_map<char, std::function<void(PoseHandler & poseHandler)>> cmderMap {
            {'M', MoveCommand()},
            {'L', TurnLeftCommand()},
            {'R', TurnRightCommand()},
            {'F', FastCommand()},
        };

        for (const auto cmd : commands) {
            const auto it = cmderMap.find(cmd);
            if (it != cmderMap.end()) {
                it->second(poseHandler);
            }
        }
    }

    // void ExecutorImpl::Move() noexcept
    // {
    //     if (pose.heading == 'E') {
    //         ++pose.x;
    //     } else if (pose.heading == 'W') {
    //         --pose.x;
    //     } else if (pose.heading == 'N') {
    //         ++pose.y;
    //     } else if (pose.heading == 'S') {
    //         --pose.y;
    //     }
    // }
    // void ExecutorImpl::TurnLeft() noexcept
    // {
    //     if (pose.heading == 'E')
    //     {
    //         pose.heading = 'N';
    //     }
    //     else if (pose.heading == 'W')
    //     {
    //         pose.heading = 'S';
    //     }
    //     else if (pose.heading == 'N')
    //     {
    //         pose.heading = 'W';
    //     }
    //     else if (pose.heading == 'S')
    //     {
    //         pose.heading = 'E';
    //     }
    // }
    // void ExecutorImpl::TurnRight() noexcept
    // {
    //     if (pose.heading == 'E')
    //     {
    //         pose.heading = 'S';
    //     }
    //     else if (pose.heading == 'W')
    //     {
    //         pose.heading = 'N';
    //     }
    //     else if (pose.heading == 'N')
    //     {
    //         pose.heading = 'E';
    //     }
    //     else if (pose.heading == 'S')
    //     {
    //         pose.heading = 'W';
    //     }
    // }

    // void ExecutorImpl::Fast() noexcept
    // {
    //     fast = !fast;
    // }
    // bool ExecutorImpl::IsFast() const noexcept
    // {
    // return fast;
    // }

    Pose ExecutorImpl::Query() const noexcept
    {
        return poseHandler.Query();
    }
}// namespace adas
