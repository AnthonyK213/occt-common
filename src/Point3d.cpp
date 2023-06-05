#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/Math.h>

namespace OcctCommon {
namespace Geometry {

Point3d::Point3d(double x, double y, double z) : m_data(x, y, z) {}

Point3d::Point3d(const gp_Pnt &pnt) : m_data(pnt) {}

Point3d::Point3d(const gp_XYZ &xyz) : m_data(xyz) {}

Point3d::Point3d(const Vector3d &vector) : m_data() {}

Point3d::Point3d(const Point3d &point) : m_data(point.m_data) {}

Point3d::Point3d(Point3d &&point) noexcept : m_data(std::move(point.m_data)) {}

Point3d Point3d::Origin() { return Point3d{0.0, 0.0, 0.0}; }

Point3d Point3d::Unset() {
  return Point3d{__Math::UnsetValue(), __Math::UnsetValue(),
                 __Math::UnsetValue()};
}

Point3d Point3d::Add(const Point3d &point1, const Point3d &point2) {
  return Point3d(point1.Coord() + point2.Coord());
}

Point3d Point3d::Divide(const Point3d &point, double t) {
  return Point3d(point.Coord() / t);
}

Point3d Point3d::Multiply(const Point3d &point, double t) {
  return Point3d(point.Coord() * t);
}

Point3d Point3d::Multiply(double t, const Point3d &point) {
  return Point3d(point.Coord() * t);
}

Vector3d Point3d::Subtract(const Point3d &point1, const Point3d &point2) {}

Point3d Point3d::Subtract(const Point3d &point, const Vector3d &vector) {}

bool Point3d::IsValid() const {
  return __Math::IsValidDouble(X()) && __Math::IsValidDouble(Y()) &&
         __Math::IsValidDouble(Z());
}

inline double Point3d::X() const { return m_data.X(); };

inline double Point3d::Y() const { return m_data.Y(); };

inline double Point3d::Z() const { return m_data.Z(); };

Point3d &Point3d::operator=(const Point3d &point) {
  this->m_data = point.m_data;
  return *this;
}

Point3d &Point3d::operator=(Point3d &&point) noexcept {
  this->m_data = std::move(point.m_data);
  return *this;
}

bool Point3d::operator!=(const Point3d &other) const {
  if (IsValid() ^ other.IsValid())
    return false;

  return !(X() == other.X() && Y() == other.Y() && Z() == other.Z());
}

bool Point3d::operator==(const Point3d &other) const {
  if (!IsValid() || !other.IsValid())
    return false;

  return X() == other.X() && Y() == other.Y() && Z() == other.Z();
}

const Point3d Point3d::operator-(const Vector3d &vector) const {}

const Point3d Point3d::operator-() const { return Point3d(-X(), -Y(), -Z()); }

const Point3d Point3d::operator*(double t) const {
  return Point3d::Multiply(*this, t);
}

const Point3d operator*(double t, const Point3d &point) {
  return Point3d::Multiply(point, t);
}

const Point3d Point3d::operator/(double t) const {
  return Point3d::Divide(*this, t);
}

const Point3d Point3d::operator+(const Vector3d &vector) const {}

const Point3d operator+(const Vector3d &vector, const Point3d &point) {}

const Point3d Point3d::operator+(const Point3d &other) const {
  return Point3d::Add(*this, other);
}

const Vector3d Point3d::operator-(const Point3d &other) const {}

const gp_Pnt &Point3d::Data() const {
  const gp_Pnt &pnt = m_data;
  return pnt;
}

gp_Pnt &Point3d::DataMut() {
  gp_Pnt &pnt = m_data;
  return pnt;
}

const gp_XYZ &Point3d::Coord() const { return m_data.Coord(); }

gp_XYZ &Point3d::ChangeCoord() { return m_data.ChangeCoord(); }

} // namespace Geometry
} // namespace OcctCommon
