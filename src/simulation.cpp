#include "elevator/simulation.hpp"
#include <stdexcept>

namespace elevator {
Simulation::Simulation(Config config) : config_(config) {
    // Не допускаем некорректного начального состояния даже у каркаса.
    if (config.floors < 2 || config.floors > 30 ||
        config.elevators < 2 || config.elevators > 8 ||
        config.capacity < 1 || config.capacity > 20 ||
        config.travel_ticks < 1 || config.travel_ticks > 60 ||
        config.door_ticks < 1 || config.door_ticks > 60) {
        throw std::invalid_argument("Configuration is outside SRS limits");
    }
    elevators_.reserve(static_cast<std::size_t>(config.elevators));
    for (int id = 1; id <= config.elevators; ++id) {
        elevators_.emplace_back(id, config.capacity);
    }
}
const Config& Simulation::config() const noexcept { return config_; }
const std::vector<Elevator>& Simulation::elevators() const noexcept { return elevators_; }
} // namespace elevator
