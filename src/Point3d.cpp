#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Transform.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Point3d::Point3d(double x, double y, double z) : _gpWrapper({x, y, z}) {}

Point3d::Point3d(C_Vec vector) : _gpWrapper(vector.Data().XYZ()) {}

Point3d::Point3d(C_Pnt point) : _gpWrapper(point.m_data) {}

C_Pnt Point3d::Origin() {
  static Point3d Point3d_Origin(gp::Origin());
  return Point3d_Origin;
}

C_Pnt Point3d::Unset() {
  static Point3d Point3d_Unset(_Math::UnsetValue, _Math::UnsetValue,
                               _Math::UnsetValue);
  return Point3d_Unset;
}

Point3d Point3d::Add(C_Pnt point1, C_Pnt point2) {
  return Point3d(point1.Data().Coord() + point2.Data().Coord());
}

Point3d Point3d::Add(C_Pnt point, C_Vec vector) {
  return Point3d(point.Data().Coord() + vector.Data().XYZ());
}

Point3d Point3d::Add(C_Vec vector, C_Pnt point) {
  return Point3d(point.Data().Coord() + vector.Data().XYZ());
}

Point3d Point3d::Divide(C_Pnt point, double t) {
  return Point3d(point.Data().Coord() / t);
}

Point3d Point3d::Multiply(C_Pnt point, double t) {
  return Point3d(point.Data().Coord() * t);
}

Point3d Point3d::Multiply(double t, C_Pnt point) {
  return Point3d(point.Data().Coord() * t);
}

Vector3d Point3d::Subtract(C_Pnt point1, C_Pnt point2) {
  return Vector3d(point1.Data().Coord() - point2.Data().Coord());
}

Point3d Point3d::Subtract(C_Pnt point, C_Vec vector) {
  return Point3d(point.Data().Coord() - vector.Data().XYZ());
}

bool Point3d::IsValid() const {
  return _Math::IsValidDouble(X()) && _Math::IsValidDouble(Y()) &&
         _Math::IsValidDouble(Z());
}

inline double Point3d::X() const { return m_data.X(); };

inline double Point3d::Y() const { return m_data.Y(); };

inline double Point3d::Z() const { return m_data.Z(); };

double Point3d::DistanceTo(C_Pnt point) const {
  return m_data.Distance(point.Data());
}

double Point3d::DistanceToSquared(C_Pnt point) const {
  return m_data.SquareDistance(point.Data());
}

bool Point3d::operator!=(C_Pnt other) const {
  if (X() == other.X() && Y() == other.Y())
    return Z() != other.Z();
  return true;
}

bool Point3d::operator==(C_Pnt other) const {
  if (X() == other.X() && Y() == other.Y())
    return Z() == other.Z();
  return false;
}

const Point3d Point3d::operator-(C_Vec vector) const {
  return Point3d::Subtract(*this, vector);
}

const Point3d Point3d::operator-() const { return Point3d(-X(), -Y(), -Z()); }

const Point3d Point3d::operator*(double t) const {
  return Point3d::Multiply(*this, t);
}

const Point3d Point3d::operator/(double t) const {
  return Point3d::Divide(*this, t);
}

const Point3d Point3d::operator+(C_Vec vector) const {
  return Point3d::Add(*this, vector);
}

const Point3d Point3d::operator+(C_Pnt other) const {
  return Point3d::Add(*this, other);
}

const Vector3d Point3d::operator-(C_Pnt other) const {
  return Point3d::Subtract(*this, other);
}

Point3d &Point3d::operator*=(double t) {
  m_data.SetX(m_data.X() * t);
  m_data.SetY(m_data.Y() * t);
  m_data.SetZ(m_data.Z() * t);
  return *this;
}

Point3d &Point3d::operator/=(double t) {
  m_data.SetX(m_data.X() / t);
  m_data.SetY(m_data.Y() / t);
  m_data.SetZ(m_data.Z() / t);
  return *this;
}

Point3d &Point3d::operator+=(C_Vec vector) {
  m_data.SetXYZ(m_data.Coord() + vector.Data().XYZ());
  return *this;
}

Point3d &Point3d::operator+=(C_Pnt other) {
  m_data.SetXYZ(m_data.Coord() + other.Data().Coord());
  return *this;
}

const Point3d operator+(C_Vec vector, C_Pnt point) {
  return Point3d::Add(vector, point);
}

const Point3d operator*(double t, C_Pnt point) {
  return Point3d::Multiply(point, t);
}

} // namespace Geometry
} // namespace OcctCommon
