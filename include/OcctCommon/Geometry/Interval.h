#ifndef OCCTCOMMON_GEOMETRY_INTERVAL_H
#define OCCTCOMMON_GEOMETRY_INTERVAL_H

#include <OcctCommon/_decl.h>

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
  Interval(__CIntv interval) = default;

  /// @brief 
  /// @param interval 
  Interval(Interval &&interval) noexcept = default;

  /// @brief 
  /// @param interval 
  /// @return 
  Interval &operator=(__CIntv interval) = default;

  /// @brief 
  /// @param interval 
  /// @return 
  Interval &operator=(Interval &&interval) noexcept = default;

public:
  /// @brief 
  /// @return 
  static __CIntv Unset() noexcept;

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
  static Interval FromIntersection(__CIntv a, __CIntv b);

  /// @brief 
  /// @param a 
  /// @param b 
  /// @return 
  static Interval FromUnion(__CIntv a, __CIntv b);

  /// @brief 
  /// @param other 
  /// @return 
  int CompareTo(__CIntv other) const;

  /// @brief 
  /// @param other 
  /// @param epsilon 
  /// @return 
  bool EpsilonEquals(__CIntv other, double epsilon) const;

  /// @brief 
  /// @param other 
  /// @return 
  bool Equals(__CIntv other) const;

  /// @brief 
  /// @param value 
  void Grow(double value);

  /// @brief 
  /// @param interval 
  /// @return 
  bool IncludesInterval(__CIntv interval) const;

  /// @brief 
  /// @param interval 
  /// @param strict 
  /// @return 
  bool IncludesInterval(__CIntv interval, bool strict) const;
  
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
  Interval NormalizedIntervalAt(__CIntv intervalParameter) const;

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
  Interval ParameterIntervalAt(__CIntv normalizedInterval) const;

  /// @brief Changes interval to [-T1, -T0].
  void Reverse();

  /// @brief Exchanges T0 and T1.
  void Swap();
  
public:
  bool operator!=(__CIntv other) const;

  bool operator<(__CIntv other) const;

  bool operator<=(__CIntv other) const;

  bool operator==(__CIntv other) const;

  bool operator>(__CIntv other) const;

  bool operator>=(__CIntv other) const;

  const Interval operator-(double number) const;

  const Interval operator+(double number) const;

  void operator-=(double number);

  void operator+=(double number);

private:
  double m_t0;
  double m_t1;
};

const Interval operator-(double number, __CIntv interval);

const Interval operator+(double number, __CIntv interval);

} // namespace Geometry
} // namespace OcctCommon

#endif
