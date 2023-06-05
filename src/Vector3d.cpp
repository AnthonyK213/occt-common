#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/Math.h>
#include <OcctCommon/OcctCommon.h>

namespace OcctCommon {
namespace Geometry {

Vector3d::Vector3d(double x, double y, double z) : m_data(x, y, z) {}

Vector3d::Vector3d(__CPnt point) : m_data(point.X(), point.Y(), point.Z()) {}

Vector3d::Vector3d(const gp_Vec &vec) : m_data(vec) {}

Vector3d::Vector3d(const gp_XYZ &xyz) : m_data(xyz) {}

Vector3d::Vector3d(__CVec vector) : m_data(vector.m_data) {}

Vector3d::Vector3d(Vector3d &&vector) noexcept
    : m_data(std::move(vector.m_data)) {}

// Tolerance?
inline bool Vector3d::IsUnitVector() const { return Length() == 1.0; }

inline bool Vector3d::IsValid() const {
  return __Math::IsValidDouble(X()) && __Math::IsValidDouble(Y()) &&
         __Math::IsValidDouble(Z());
}

inline bool Vector3d::IsZero() const {
  return X() == 0.0 && Y() == 0.0 && Z() == 0.0;
}

inline double Vector3d::Length() const { return m_data.Magnitude(); }

inline double Vector3d::SquareLength() const {
  return m_data.SquareMagnitude();
}

Vector3d Vector3d::Unset() {
  return Vector3d(OCCTCOMMON_UNSET_VALUE, OCCTCOMMON_UNSET_VALUE,
                  OCCTCOMMON_UNSET_VALUE);
}

inline double Vector3d::X() const { return m_data.X(); }

inline double Vector3d::Y() const { return m_data.Y(); }

inline double Vector3d::Z() const { return m_data.Z(); }

Vector3d Vector3d::XAxis() { return Vector3d(1.0, 0.0, 0.0); }

Vector3d Vector3d::YAxis() { return Vector3d(0.0, 1.0, 0.0); }

Vector3d Vector3d::ZAxis() { return Vector3d(0.0, 0.0, 1.0); }

Vector3d Vector3d::Zero() { return Vector3d(0.0, 0.0, 0.0); }

Vector3d Vector3d::Add(__CVec vector1, __CVec vector2) {
  return Vector3d(vector1.Data() + vector2.Data());
}

bool Vector3d::AreOrthogonal(__CVec x, __CVec y, __CVec z) {
  if (x.IsZero() || y.IsZero() || z.IsZero())
    return false;
  return Vector3d(x.Data().CrossCrossed(y.Data(), z.Data())).IsZero();
}

bool Vector3d::AreOrithonormal(__CVec x, __CVec y, __CVec z) {
  if (!Vector3d::AreOrthogonal(x, y, z))
    return false;
  return x.IsUnitVector() && y.IsUnitVector() && z.IsUnitVector();
}

bool Vector3d::AreRighthanded(__CVec x, __CVec y, __CVec z) {
  if (!AreOrithonormal(x, y, z))
    return false;
  return x.Data().DotCross(y.Data(), z.Data()) > 0.0;
}

Vector3d Vector3d::CrossProduct(__CVec a, __CVec b) {
  return Vector3d(a.Data().Crossed(b.Data()));
}

Vector3d Vector3d::Divide(__CVec vector, double t) {
  return Vector3d(vector.Data() / t);
}

Vector3d Vector3d::Mulitply(__CVec vector, double t) {
  return Vector3d(vector.Data() * t);
}

Vector3d Vector3d::Mulitply(double t, __CVec vector) {
  return Vector3d(vector.Data() * t);
}

Vector3d Vector3d::Negate(__CVec vector) {
  return Vector3d(-vector.X(), -vector.Y(), -vector.Z());
}

Vector3d Vector3d::Subtract(__CVec vector1, __CVec vector2) {
  return Vector3d(vector1.Data() - vector2.Data());
}

int Vector3d::CompareTo(__CVec other) {
  if (X() < other.X()) {
    return -1;
  } else if (X() == other.X()) {
    if (Y() < other.Y()) {
      return -1;
    } else if (Y() == other.Y()) {
      if (Z() < other.Z()) {
        return -1;
      } else if (Z() == other.Z()) {
        return 0;
      } else {
        return 1;
      }
    } else {
      return 1;
    }
  } else {
    return 1;
  }
}

const gp_Vec &Vector3d::Data() const {
  const gp_Vec &vec = m_data;
  return vec;
}

gp_Vec &Vector3d::DataMut() {
  gp_Vec &vec = m_data;
  return vec;
}

} // namespace Geometry
} // namespace OcctCommon
