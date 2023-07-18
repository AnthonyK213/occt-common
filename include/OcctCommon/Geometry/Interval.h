#ifndef OCCTCOMMON_GEOMETRY_INTERVAL_H
#define OCCTCOMMON_GEOMETRY_INTERVAL_H

#include <OcctCommon/pch.h>

namespace OcctCommon {
namespace Geometry {

class Interval final {
public:
  /// @brief
  /// @param t0
  /// @param t1
  Interval(double t0, double t1);

  /// @brief
  /// @param interval
  Interval(C_Intv interval) = default;

  /// @brief
  /// @param interval
  Interval(Interval &&interval) noexcept = default;

  /// @brief
  /// @param interval
  /// @return
  Interval &operator=(C_Intv interval) = default;

  /// @brief
  /// @param interval
  /// @return
  Interval &operator=(Interval &&interval) noexcept = default;

public:
  /// @brief
  /// @return
  static C_Intv Unset() noexcept;

  /// @brief
  /// @return
  bool IsDecreasing() const;

  /// @brief
  /// @return
  bool IsIncreasing() const;

  /// @brief
  /// @return
  bool IsSingleton() const;

  /// @brief
  /// @return
  bool IsValid() const;

  /// @brief
  /// @return
  double Length() const;

  /// @brief
  /// @return
  double Max() const;

  /// @brief
  /// @return
  double Mid() const;

  /// @brief
  /// @return
  double Min() const;

  /// @brief
  /// @return
  double T0() const;

  /// @brief
  /// @return
  double T1() const;

public:
  /// @brief
  /// @param a
  /// @param b
  /// @return
  static Interval FromIntersection(C_Intv a, C_Intv b);

  /// @brief
  /// @param a
  /// @param b
  /// @return
  static Interval FromUnion(C_Intv a, C_Intv b);

  /// @brief
  /// @param other
  /// @return
  int32_t CompareTo(C_Intv other) const;

  /// @brief
  /// @param other
  /// @param epsilon
  /// @return
  bool EpsilonEquals(C_Intv other, double epsilon) const;

  /// @brief
  /// @param other
  /// @return
  bool Equals(C_Intv other) const;

  /// @brief
  /// @param value
  void Grow(double value);

  /// @brief
  /// @param interval
  /// @return
  bool IncludesInterval(C_Intv interval) const;

  /// @brief
  /// @param interval
  /// @param strict
  /// @return
  bool IncludesInterval(C_Intv interval, bool strict) const;

  /// @brief
  /// @param t
  /// @return
  bool IncludesParameter(double t) const;

  /// @brief
  /// @param t
  /// @param strict
  /// @return
  bool IncludesParameter(double t, bool strict) const;

  /// @brief
  void MakeIncreasing();

  /// @brief
  /// @param intervalParameter
  /// @return
  Interval NormalizedIntervalAt(C_Intv intervalParameter) const;

  /// @brief
  /// @param intervalParameter
  /// @return
  double NormalizedParameterAt(double intervalParameter) const;

  /// @brief
  /// @param normalizedParameter
  /// @return
  double ParameterAt(double normalizedParameter) const;

  /// @brief
  /// @param normalizedInterval
  /// @return
  Interval ParameterIntervalAt(C_Intv normalizedInterval) const;

  /// @brief Changes interval to [-T1, -T0].
  void Reverse();

  /// @brief Exchanges T0 and T1.
  void Swap();

public:
  bool operator!=(C_Intv other) const;

  bool operator<(C_Intv other) const;

  bool operator<=(C_Intv other) const;

  bool operator==(C_Intv other) const;

  bool operator>(C_Intv other) const;

  bool operator>=(C_Intv other) const;

  const Interval operator-(double number) const;

  const Interval operator+(double number) const;

  Interval &operator-=(double number);

  Interval &operator+=(double number);

private:
  double m_t0;
  double m_t1;
};

const Interval operator-(double number, C_Intv interval);

const Interval operator+(double number, C_Intv interval);

} // namespace Geometry
} // namespace OcctCommon

#endif
