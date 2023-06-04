#ifndef OCCTCOMMON_MATH_H
#define OCCTCOMMON_MATH_H

#include <cmath>

namespace OcctCommon {

class OcctMath {
public:
  static bool IsValidDouble(double x);

public:
  static double UnsetValue();
};

} // namespace OcctCommon

#endif
