#pragma once

namespace elevator {
enum class Direction { Idle, Up, Down };
enum class ElevatorState { Idle, Moving, DoorsOpen };

// Пока хранит только начальное состояние кабины.
class Elevator {
public:
    Elevator(int id, int capacity);
    [[nodiscard]] int id() const noexcept;
    [[nodiscard]] int floor() const noexcept;
    [[nodiscard]] int capacity() const noexcept;
    [[nodiscard]] ElevatorState state() const noexcept;

private:
    int id_;
    int floor_ = 1;
    int capacity_;
    ElevatorState state_ = ElevatorState::Idle;
};
} // namespace elevator
