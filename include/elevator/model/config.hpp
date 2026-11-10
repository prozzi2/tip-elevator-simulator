#pragma once

namespace elevator {
// Начальные значения из учебной SRS; проверка ввода добавляется следующим этапом.
struct Config {
    int floors = 10;
    int elevators = 2;
    int capacity = 4;
    int travel_ticks = 1;
    int door_ticks = 1;
};
} // namespace elevator
