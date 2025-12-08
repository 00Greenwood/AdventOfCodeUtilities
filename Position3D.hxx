#pragma once

struct Position3D {
  long double x;
  long double y;
  long double z;

   long double distance(const Position3D&) const;

   bool operator==(const Position3D& other) const;

   bool operator<(const Position3D& other) const;
};
