#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/Math.h>
#include <OcctCommon/OcctCommon.h>

namespace OcctCommon {
namespace Geometry {

Vector3d::Vector3d(double x, double y, double z) : m_data(x, y, z) {}

Vector3d::Vector3d(const Point3d &point)
    : m_data(point.X(), point.Y(), point.Z()) {}

Vector3d::Vector3d(const gp_Vec &vec) : m_data(vec) {}

Vector3d::Vector3d(const gp_XYZ &xyz) : m_data(xyz) {}

Vector3d::Vector3d(__CVec vector) : m_data(vector.m_data) {}

Vector3d::Vector3d(Vector3d &&vector) noexcept
    : m_data(std::move(vector.m_data)) {}

inline bool Vector3d::IsUnitVector() const { NotImplemented(); }

inline bool Vector3d::IsValid() const {
  return __Math::IsValidDouble(X()) && __Math::IsValidDouble(Y()) &&
         __Math::IsValidDouble(Z());
}

inline bool Vector3d::IsZero() const { NotImplemented(); }

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

static Vector3d Add(__CVec vector1, __CVec vector2) {
  return Vector3d(vector1.Data() + vector2.Data());
}

static bool AreOrthogonal(__CVec x, __CVec y, __CVec z) { NotImplemented(); }

static bool AreOrithonormal(__CVec x, __CVec y, __CVec z) { NotImplemented(); }

static bool AreRighthanded(__CVec x, __CVec y, __CVec z) { NotImplemented(); }

int CompareTo(__CVec other) { NotImplemented(); }

static Vector3d CrossProduct(__CVec a, __CVec b) { NotImplemented(); }

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
