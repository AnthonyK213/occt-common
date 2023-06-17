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
  /// @brief Changes interval to [-T1, -T0].
  void Reverse();

  /// @brief Exchanges T0 and T1.
  void Swap();

private:
  double m_t0;
  double m_t1;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
