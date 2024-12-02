#include "ExecutorImpl.hpp"
#include <memory>
#include "Command.hpp"
#include <unordered_map>
#include "CmderFactory.hpp"
#include "Singleton.hpp"


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
        // const std::unordered_map<char, std::function<void(PoseHandler & poseHandler)>> cmderMap {
        //     {'M', MoveCommand()},
        //     {'L', TurnLeftCommand()},
        //     {'R', TurnRightCommand()},
        //     {'F', FastCommand()},
        //     {'B', ReverseCommand()},
        // };

        // for (const auto cmd : commands) {
        //     const auto it = cmderMap.find(cmd);
        //     if (it != cmderMap.end()) {
        //         it->second(poseHandler);
        //     }
        // }
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
        
        std::for_each(cmders.begin(), cmders.end(), [this](const Cmder& cmder) noexcept { cmder(poseHandler); });
    }

    Pose ExecutorImpl::Query() const noexcept
    {
        return poseHandler.Query();
    }
}// namespace adas
