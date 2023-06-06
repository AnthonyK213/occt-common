#include <OcctCommon/OcctMath.h>

namespace OcctCommon {

bool OcctMath::IsValidDouble(double x) {
  return x != OcctMath::UnsetValue() && !std::isnan(x);
}

bool OcctMath::IsValidXYZ(const gp_XYZ &xyz) {
  return OcctMath::IsValidDouble(xyz.X()) && OcctMath::IsValidDouble(xyz.Y()) &&
         OcctMath::IsValidDouble(xyz.Z());
}

double OcctMath::UnsetValue() {
  static const double OCCTCOMMON_UNSET_VALUE = -1.23432101234321e+308;
  return OCCTCOMMON_UNSET_VALUE;
}

} // namespace OcctCommon
