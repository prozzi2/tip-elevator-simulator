#include "elevator/model/elevator.hpp"

namespace elevator {
Elevator::Elevator(int id, int capacity) : id_(id), capacity_(capacity) {}
int Elevator::id() const noexcept { return id_; }
int Elevator::floor() const noexcept { return floor_; }
int Elevator::capacity() const noexcept { return capacity_; }
ElevatorState Elevator::state() const noexcept { return state_; }
} // namespace elevator
