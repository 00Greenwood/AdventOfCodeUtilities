#include "precompiled.hxx"

#include "Line.hxx"

bool Line::contains(const Position& point) const {
    // Vertical line
    if (is_vertical() && point.x == end.x && point.y >= std::min(start.y, end.y) && point.y <= std::max(start.y, end.y)) {
        return true;
    }
    // Horizontal line
    if (is_horizontal() && point.y == end.y && point.x >= std::min(start.x, end.x) && point.x <= std::max(start.x, end.x)) {
        return true;
    }   
     return false;   
}

bool Line::crosses(const Line& other) const {
    // Check if one line is vertical and the other is horizontal
    if (is_vertical() && other.is_horizontal()) {
        return (other.start.x < start.x && other.end.x > start.x) &&
               (start.y < other.start.y && end.y > other.start.y);
    }
    if (is_horizontal() && other.is_vertical()) {
        return (start.x < other.start.x && end.x > other.start.x) &&
               (other.start.y < start.y && other.end.y > start.y);
    }
    return false; // Parallel lines do not cross
}
