#include <OcctCommon/OcctMath.h>
#include <cmath>
#include <limits>

namespace OcctCommon {

bool OcctMath::EpsilonEquals(double x, double y, double epsilon) {
  if (std::isnan(x) || std::isnan(y))
    return false;
  if (x == std::numeric_limits<double>::infinity())
    return y == std::numeric_limits<double>::infinity();
  if (x == -std::numeric_limits<double>::infinity())
    return y == -std::numeric_limits<double>::infinity();
  if (std::abs(x) < epsilon && std::abs(y) < epsilon)
    return std::abs(x - y) < epsilon;
  if (x >= y - epsilon)
    return x <= y + epsilon;
  return false;
}

bool OcctMath::IsValidDouble(double x) {
  if (x != OcctMath::UnsetValue && !std::isinf(x))
    return !std::isnan(x);
  return false;
}

bool OcctMath::IsValidXYZ(const gp_XYZ &xyz) {
  if (OcctMath::IsValidDouble(xyz.X()) && OcctMath::IsValidDouble(xyz.Y()))
    return OcctMath::IsValidDouble(xyz.Z());
  return false;
}

double OcctMath::ToDegrees(double radians) {
  return radians * (180.0 / OcctMath::PI);
}

double OcctMath::ToRadians(double degrees) {
  return degrees * (OcctMath::PI / 180.0);
}

} // namespace OcctCommon
