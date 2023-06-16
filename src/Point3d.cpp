#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Transform.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Point3d::Point3d(double x, double y, double z) : _gpWrapper({x, y, z}) {}

Point3d::Point3d(__CVec vector) : _gpWrapper(vector.Data().XYZ()) {}

Point3d::Point3d(__CPnt point) : _gpWrapper(point.m_data) {}

__CPnt Point3d::Origin() {
  static Point3d Point3d_Origin(gp::Origin());
  return Point3d_Origin;
}

__CPnt Point3d::Unset() {
  static Point3d Point3d_Unset(__Math::UnsetValue, __Math::UnsetValue,
                               __Math::UnsetValue);
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

Point3d Point3d::Subtract(__CPnt point, __CVec vector) {
  return Point3d(point.Data().Coord() - vector.Data().XYZ());
}

bool Point3d::IsValid() const {
  return __Math::IsValidDouble(X()) && __Math::IsValidDouble(Y()) &&
         __Math::IsValidDouble(Z());
}

inline double Point3d::X() const { return m_data.X(); };

inline double Point3d::Y() const { return m_data.Y(); };

inline double Point3d::Z() const { return m_data.Z(); };

double Point3d::DistanceTo(__CPnt point) const {
  return m_data.Distance(point.Data());
}

double Point3d::DistanceToSquared(__CPnt point) const {
  return m_data.SquareDistance(point.Data());
}

bool Point3d::operator!=(__CPnt other) const {
  if (X() == other.X() && Y() == other.Y())
    return Z() != other.Z();
  return true;
}

bool Point3d::operator==(__CPnt other) const {
  if (X() == other.X() && Y() == other.Y())
    return Z() == other.Z();
  return false;
}

const Point3d Point3d::operator-(__CVec vector) const {
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

const Point3d operator+(__CVec vector, __CPnt point) {
  return Point3d::Add(vector, point);
}

const Point3d Point3d::operator+(__CPnt other) const {
  return Point3d::Add(*this, other);
}

const Vector3d Point3d::operator-(__CPnt other) const {
  return Point3d::Subtract(*this, other);
}

} // namespace Geometry
} // namespace OcctCommon
