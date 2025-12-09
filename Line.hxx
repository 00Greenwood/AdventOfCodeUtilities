#pragma once

#include "Position.hxx"

struct Line {
    Position start;
    Position end;
    
    bool is_horizontal() const { return start.y == end.y; }
    bool is_vertical() const { return start.x == end.x; }

    bool contains(const Position& point) const;

    bool crosses(const Line& other) const;
};