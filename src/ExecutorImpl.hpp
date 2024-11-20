#pragma once 
#include "Executor.hpp"

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

        private:
            Pose pose;

            void Move(void) noexcept;
            void TurnLeft(void) noexcept;
            void TurnRight(void) noexcept;

            class ICommand
            {
            public:
                virtual ~ICommand() = default;
                virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
            };
            class MoveCommand final : public ICommand
            {
            public:
                void DoOperate(ExecutorImpl& executor) const noexcept override;
            };
            class TurnLeftCommand final : public ICommand
            {
            public:
                void DoOperate(ExecutorImpl& executor) const noexcept override;
            };
            class TurnRightCommand final : public ICommand
            {
            public:
                void DoOperate(ExecutorImpl& executor) const noexcept override;
            };
    };
}  // namespace adas

