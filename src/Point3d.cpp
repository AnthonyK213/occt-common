#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/Math.h>
#include <OcctCommon/OcctCommon.h>

namespace OcctCommon {
namespace Geometry {

Point3d::Point3d(double x, double y, double z) : m_data(x, y, z) {}

Point3d::Point3d(const gp_Pnt &pnt) : m_data(pnt) {}

Point3d::Point3d(const gp_XYZ &xyz) : m_data(xyz) {}

Point3d::Point3d(__CVec vector) : m_data() {}

Point3d::Point3d(__CPnt point) : m_data(point.m_data) {}

__CPnt Point3d::Origin() {
  static Point3d Point3d_Origin(gp::Origin());
  return Point3d_Origin;
}

__CPnt Point3d::Unset() {
  static Point3d Point3d_Unset(__Math::UnsetValue(), __Math::UnsetValue(),
                               __Math::UnsetValue());
  return Point3d_Unset;
}

Point3d Point3d::Add(__CPnt point1, __CPnt point2) {
  return Point3d(point1.Data().Coord() + point2.Data().Coord());
}

Point3d Point3d::Add(__CPnt point, __CVec vector) {
  return Point3d(point.Data().Coord() + vector.Data().XYZ());
}

Point3d Point3d::Add(__CVec vector, __CPnt point) {
  return Point3d(point.Data().Coord() + vector.Data().XYZ());
}

Point3d Point3d::Divide(__CPnt point, double t) {
  return Point3d(point.Data().Coord() / t);
}

Point3d Point3d::Multiply(__CPnt point, double t) {
  return Point3d(point.Data().Coord() * t);
}

Point3d Point3d::Multiply(double t, __CPnt point) {
  return Point3d(point.Data().Coord() * t);
}

Vector3d Point3d::Subtract(__CPnt point1, __CPnt point2) {
  return Vector3d(point1.Data().Coord() - point2.Data().Coord());
}

Point3d Point3d::Subtract(__CPnt point, const Vector3d &vector) {
  return Point3d(point.Data().Coord() - vector.Data().XYZ());
}

bool Point3d::IsValid() const {
  return __Math::IsValidDouble(X()) && __Math::IsValidDouble(Y()) &&
         __Math::IsValidDouble(Z());
}

inline double Point3d::X() const { return m_data.X(); };

inline double Point3d::Y() const { return m_data.Y(); };

inline double Point3d::Z() const { return m_data.Z(); };

bool Point3d::operator!=(__CPnt other) const {
  if (IsValid() ^ other.IsValid())
    return false;

  return !(X() == other.X() && Y() == other.Y() && Z() == other.Z());
}

bool Point3d::operator==(__CPnt other) const {
  if (!IsValid() || !other.IsValid())
    return false;

  return X() == other.X() && Y() == other.Y() && Z() == other.Z();
}

const Point3d Point3d::operator-(const Vector3d &vector) const {
  return Point3d::Subtract(*this, vector);
}

const Point3d Point3d::operator-() const { return Point3d(-X(), -Y(), -Z()); }

const Point3d Point3d::operator*(double t) const {
  return Point3d::Multiply(*this, t);
}

const Point3d operator*(double t, __CPnt point) {
  return Point3d::Multiply(point, t);
}

const Point3d Point3d::operator/(double t) const {
  return Point3d::Divide(*this, t);
}

const Point3d Point3d::operator+(__CVec vector) const {
  return Point3d::Add(*this, vector);
}

const Point3d operator+(const Vector3d &vector, __CPnt point) {
  return Point3d::Add(vector, point);
}

const Point3d Point3d::operator+(__CPnt other) const {
  return Point3d::Add(*this, other);
}

const Vector3d Point3d::operator-(__CPnt other) const {
  return Point3d::Subtract(*this, other);
}

const gp_Pnt &Point3d::Data() const { return m_data; }

gp_Pnt &Point3d::DataMut() { return m_data; }

} // namespace Geometry
} // namespace OcctCommon
