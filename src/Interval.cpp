#include <OcctCommon/Geometry/Interval.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Interval::Interval(double t0, double t1) : m_t0(t0), m_t1(t1) {}

__CIntv Interval::Unset() noexcept {
  static Interval Interval_Unset{__Math::UnsetValue, __Math::UnsetValue};
  return Interval_Unset;
}

bool Interval::IsDecreasing() const { return m_t0 > m_t1; }

bool Interval::IsIncreasing() const { return m_t0 < m_t1; }

bool Interval::IsSingleton() const { return IsValid() && m_t0 == m_t1; }

bool Interval::IsValid() const {
  return __Math::IsValidDouble(m_t0) && __Math::IsValidDouble(m_t1);
}

double Interval::Length() const { return m_t1 - m_t0; }

double Interval::Max() const { return std::max(m_t0, m_t1); }

double Interval::Mid() const { return (m_t0 + m_t1) / 2.0; }

double Interval::Min() const { return std::min(m_t0, m_t1); }

double Interval::T0() const { return m_t0; }

double Interval::T1() const { return m_t1; }

void Interval::Reverse() {
  double temp = m_t0;
  m_t0 = -m_t1;
  m_t1 = -temp;
}

void Interval::Swap() { std::swap(m_t0, m_t1); }

} // namespace Geometry
} // namespace OcctCommon
