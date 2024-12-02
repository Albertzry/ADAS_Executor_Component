#pragma once 
#include "Executor.hpp"
#include "PoseHandler.hpp"


namespace adas
{
    class ExecutorImpl final : public Executor
    {
        public:
            explicit ExecutorImpl(const Pose& pose) noexcept;
            ~ExecutorImpl() noexcept = default;
            ExecutorImpl(const ExecutorImpl&) = delete;
            ExecutorImpl& operator=(const ExecutorImpl&) = delete;

        public:
            void Execute(const std::string& command) noexcept override;
            Pose Query(void) const noexcept override;

        public:
            void Move(void) noexcept;
            void TurnLeft(void) noexcept;
            void TurnRight(void) noexcept;
            void Fast(void) noexcept;
            bool IsFast(void) const noexcept;

        private:
            PoseHandler poseHandler;

    //     private:
    //         Pose pose;
    //         bool fast{false};
    
    //         class ICommand
    //         {
    //         public:
    //             virtual ~ICommand() = default;
    //             virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
    //         };
    //         class MoveCommand final : public ICommand
    //         {
    //         public:
    //             void DoOperate(ExecutorImpl& executor) const noexcept override
    //             {
    //                 if (executor.IsFast()) {
    //                     executor.Move();
    //                 }
    //                 executor.Move();
    //             }   
    //         };
    //         class TurnLeftCommand final : public ICommand
    //         {
    //         public:
    //             void DoOperate(ExecutorImpl& executor) const noexcept override
    //             {
    //                 if (executor.IsFast()) {
    //                     executor.Move();
    //                 }
    //                 executor.TurnLeft();
    //             }
    //         };
    //         class TurnRightCommand final : public ICommand
    //         {
    //         public:
    //             void DoOperate(ExecutorImpl& executor) const noexcept override
    //             {
    //                 if (executor.IsFast()) {
    //                     executor.Move();
    //                 }
    //                 executor.TurnRight();
    //             }
    //         };
    //         class FastCommand final : public ICommand
    //         {
    //         public:
    //             void DoOperate(ExecutorImpl& executor) const noexcept override
    //             {
    //                 executor.Fast();
    //             }
    //         };
    // };
} ;
}// namespace adas
