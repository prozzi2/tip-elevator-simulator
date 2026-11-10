#pragma once

#include "elevator/model/config.hpp"
#include "elevator/model/elevator.hpp"
#include <vector>

namespace elevator {
// Каркас координатора: создаёт кабины, пока не запускает потоки и такты.
class Simulation {
public:
    explicit Simulation(Config config = {});
    [[nodiscard]] const Config& config() const noexcept;
    [[nodiscard]] const std::vector<Elevator>& elevators() const noexcept;

private:
    Config config_;
    std::vector<Elevator> elevators_;
};
} // namespace elevator
