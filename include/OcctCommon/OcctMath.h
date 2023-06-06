#ifndef OCCTCOMMON_MATH_H
#define OCCTCOMMON_MATH_H

#include <OcctCommon/_decl.h>
#include <cmath>

namespace OcctCommon {

class OcctMath {
public:
  static bool IsValidDouble(double x);
  static bool IsValidXYZ(const gp_XYZ &xyz);

public:
  static double UnsetValue();
};

} // namespace OcctCommon

#endif
