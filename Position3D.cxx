#include "precompiled.hxx"

#include "Position3D.hxx"

long double Position3D::distance(const Position3D& other) const {
  return sqrtl((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y) + (other.z - z) * (other.z - z));
}

bool Position3D::operator==(const Position3D& other) const {
  return x == other.x && y == other.y && z == other.z;
}

bool Position3D::operator<(const Position3D& other) const {
  if (x != other.x) {
    return x < other.x;
  }
  if (y != other.y) {
    return y < other.y;
  }
  return z < other.z;
}