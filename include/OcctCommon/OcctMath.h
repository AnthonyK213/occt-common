#ifndef OCCTCOMMON_MATH_H
#define OCCTCOMMON_MATH_H

#include <OcctCommon/pch.h>
#include <cmath>

namespace OcctCommon {

class OcctMath {
public:
  static bool EpsilonEquals(double x, double y, double epsilon);
  static bool IsValidDouble(double x);
  static bool IsValidXYZ(const gp_XYZ &xyz);
  static double ToDegrees(double radians);
  static double ToRadians(double degrees);

public:
  static constexpr double PI = 3.14159265358979323846;
  static constexpr double DefaultAngleTolerance = PI / 180.0;
  static constexpr double DefaultDistanceToleranceMillimeters = 0.01;
  static constexpr double Epsilon = 2.2204460492503131e-16;
  static constexpr double HalfPI = PI / 2.0;
  static constexpr double QuaterPI = PI / 4.0;
  static constexpr double SqrtEpsilon = 1.490116119385000000e-8;
  static constexpr double Tau = PI * 2.0;
  static constexpr double TwoPI = Tau;
  static constexpr double UnsetValue = -1.23432101234321e+308;
  static constexpr double ZeroTolerance = 2.3283064365386962890625e-10;
  static constexpr float UnsetSingle = -1.234321e+38f;
  static constexpr int32_t UnsetIntIndex = INT_MIN + 1;
};

} // namespace OcctCommon

#endif
