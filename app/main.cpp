#include "elevator/simulation.hpp"
#include <exception>
#include <iostream>

int main() {
    try {
        const elevator::Simulation simulation;
        std::cout << "Симулятор лифтов — вариант 15\n"
                  << "Этап: структура проекта и CMake\n"
                  << "Этажей: " << simulation.config().floors << '\n'
                  << "Лифтов: " << simulation.elevators().size() << '\n';
        for (const auto& cabin : simulation.elevators()) {
            std::cout << "Лифт " << cabin.id() << ": этаж " << cabin.floor()
                      << ", вместимость " << cabin.capacity() << '\n';
        }
        std::cout << "Движение, заявки и потоки пока не реализованы.\n";
    } catch (const std::exception& error) {
        std::cerr << "Ошибка: " << error.what() << '\n';
        return 1;
    }
}
