#include "OcctCommon/Geometry/Point3d.h"
#include "OcctCommon/Math.h"

using math = OcctCommon::OcctMath;

namespace OcctCommon {
namespace Geometry {

Point3d::Point3d(double x, double y, double z) : m_data(x, y, z) {}

Point3d::Point3d(const Point3d &point) : m_data(point.m_data) {}

Point3d::Point3d(Point3d &&point) noexcept : m_data(std::move(point.m_data)) {}

inline Point3d Point3d::Origin() { return Point3d{0.0, 0.0, 0.0}; }

inline Point3d Point3d::Unset() {
  return Point3d{math::UnsetValue(), math::UnsetValue(), math::UnsetValue()};
}

Point3d Point3d::Add(const Point3d &point1, const Point3d &point2) {
  return Point3d(point1.X() + point1.X(), point1.Y() + point1.Y(),
                 point1.Z() + point1.Z());
}

inline bool Point3d::IsValid() const {
  return math::IsValidDouble(X()) && math::IsValidDouble(Y()) &&
         math::IsValidDouble(Z());
}

inline double Point3d::X() const { return m_data.X(); };

inline double Point3d::Y() const { return m_data.Y(); };

inline double Point3d::Z() const { return m_data.Z(); };

bool Point3d::operator==(const Point3d &other) {
  if (!IsValid() || !other.IsValid())
    return false;

  return X() == other.X() && Y() == other.Y() && Z() == other.Z();
}

gp_Pnt Point3d::Pnt() const { return m_data; }

gp_Pnt &Point3d::PntMut() {
  gp_Pnt &pnt = m_data;
  return pnt;
}

} // namespace Geometry
} // namespace OcctCommon
