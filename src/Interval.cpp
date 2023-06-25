#include <OcctCommon/Geometry/Interval.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Interval::Interval(double t0, double t1) : m_t0(t0), m_t1(t1) {}

C_Intv Interval::Unset() noexcept {
  static Interval Interval_Unset{_Math::UnsetValue, _Math::UnsetValue};
  return Interval_Unset;
}

bool Interval::IsDecreasing() const { return m_t0 > m_t1; }

bool Interval::IsIncreasing() const { return m_t0 < m_t1; }

bool Interval::IsSingleton() const { return IsValid() && m_t0 == m_t1; }

bool Interval::IsValid() const {
  return _Math::IsValidDouble(m_t0) && _Math::IsValidDouble(m_t1);
}

double Interval::Length() const { return m_t1 - m_t0; }

double Interval::Max() const { return std::max(m_t0, m_t1); }

double Interval::Mid() const { return (m_t0 + m_t1) / 2.0; }

double Interval::Min() const { return std::min(m_t0, m_t1); }

double Interval::T0() const { return m_t0; }

double Interval::T1() const { return m_t1; }

Interval Interval::FromIntersection(C_Intv a, C_Intv b) {
  if (a.IsValid() && b.IsValid()) {
    double min_ = std::max(a.Min(), b.Min());
    double max_ = std::min(a.Max(), b.Max());
    if (min_ <= max_) {
      return Interval(min_, max_);
    }
  }
  return Interval::Unset();
}

Interval Interval::FromUnion(C_Intv a, C_Intv b) {
  if (a.IsValid() && b.IsValid()) {
    double min_ = std::min(a.Min(), b.Min());
    double max_ = std::max(a.Max(), b.Max());
    return Interval(min_, max_);
  }
  return Interval::Unset();
}

int Interval::CompareTo(C_Intv other) const {
  if (m_t0 < other.m_t0) {
    return -1;
  }
  if (m_t0 > other.m_t0) {
    return 1;
  }
  if (m_t1 < other.m_t1) {
    return -1;
  }
  if (m_t1 > other.m_t1) {
    return 1;
  }
  return 0;
}

bool Interval::EpsilonEquals(C_Intv other, double epsilon) const {
  return _Math::EpsilonEquals(m_t0, other.m_t0, epsilon) &&
         _Math::EpsilonEquals(m_t1, other.m_t1, epsilon);
}

bool Interval::Equals(C_Intv other) const { return *this == other; }

void Interval::Grow(double value) {
  if (IsDecreasing()) {
    Swap();
  }
  if (m_t0 > value) {
    m_t0 = value;
  }
  if (m_t1 < value) {
    m_t1 = value;
  }
}

bool Interval::IncludesInterval(C_Intv interval) const {
  return IncludesInterval(interval, false);
}

bool Interval::IncludesInterval(C_Intv interval, bool strict) const {
  return IncludesParameter(interval.m_t0, strict) &&
         IncludesParameter(interval.m_t1, strict);
}

bool Interval::IncludesParameter(double t) const {
  return IncludesParameter(t, false);
}

bool Interval::IncludesParameter(double t, bool strict) const {
  if (!_Math::IsValidDouble(t)) {
    return false;
  }
  if (strict) {
    return (m_t0 <= m_t1 && m_t0 < t && t < m_t1) ||
           (m_t1 <= m_t0 && m_t1 < t && t < m_t0);
  } else {
    return (m_t0 <= m_t1 && m_t0 <= t && t <= m_t1) ||
           (m_t1 <= m_t0 && m_t1 <= t && t <= m_t0);
  }
}

void Interval::MakeIncreasing() {
  if (IsDecreasing()) {
    Swap();
  }
}

Interval Interval::NormalizedIntervalAt(C_Intv intervalParameter) const {
  double t = NormalizedParameterAt(intervalParameter.m_t0);
  double t2 = NormalizedParameterAt(intervalParameter.m_t1);
  return Interval(t, t2);
}

double Interval::NormalizedParameterAt(double intervalParameter) const {
  if (_Math::IsValidDouble(intervalParameter)) {
    if (m_t0 != m_t1) {
      return (intervalParameter == m_t1)
                 ? 1.0
                 : ((intervalParameter - m_t0) / Length());
    }
    return m_t0;
  }
  return _Math::UnsetValue;
}

double Interval::ParameterAt(double normalizedParameter) const {
  if (!_Math::IsValidDouble(normalizedParameter)) {
    return _Math::UnsetValue;
  }
  return (1.0 - normalizedParameter) * m_t0 + normalizedParameter * m_t1;
}

Interval Interval::ParameterIntervalAt(C_Intv normalizedInterval) const {
  double t = ParameterAt(normalizedInterval.m_t0);
  double t2 = ParameterAt(normalizedInterval.m_t1);
  return Interval(t, t2);
}

void Interval::Reverse() {
  double temp = m_t0;
  m_t0 = -m_t1;
  m_t1 = -temp;
}

void Interval::Swap() { std::swap(m_t0, m_t1); }

bool Interval::operator!=(C_Intv other) const { return CompareTo(other) != 0; }

bool Interval::operator<(C_Intv other) const { return CompareTo(other) < 0; }

bool Interval::operator<=(C_Intv other) const { return CompareTo(other) <= 0; }

bool Interval::operator==(C_Intv other) const { return CompareTo(other) == 0; }

bool Interval::operator>(C_Intv other) const { return CompareTo(other) > 0; }

bool Interval::operator>=(C_Intv other) const { return CompareTo(other) >= 0; }

const Interval Interval::operator-(double number) const {
  return Interval(m_t0 - number, m_t1 - number);
}

const Interval Interval::operator+(double number) const {
  return Interval(m_t0 + number, m_t1 + number);
}

Interval &Interval::operator-=(double number) {
  m_t0 -= number;
  m_t1 -= number;
  return *this;
}

Interval &Interval::operator+=(double number) {
  m_t0 += number;
  m_t1 += number;
  return *this;
}

const Interval operator-(double number, C_Intv interval) {
  return Interval(number - interval.T0(), number - interval.T1());
}

const Interval operator+(double number, C_Intv interval) {
  return Interval(number + interval.T0(), number + interval.T1());
}

} // namespace Geometry
} // namespace OcctCommon
