#pragma once

#include <cstdint>
#include <optional>

namespace elevator {
using RequestId = std::uint64_t;
using Tick = std::uint64_t;

enum class RequestStatus { Waiting, Assigned, InTransit, Completed };

struct Request {
    RequestId id = 0;
    int origin = 1;
    int destination = 2;
    Tick created_at = 0;
    std::optional<Tick> boarded_at;
    std::optional<Tick> completed_at;
    std::optional<int> elevator_id;
    RequestStatus status = RequestStatus::Waiting;
};
} // namespace elevator
