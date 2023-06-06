#include <OcctCommon/Geometry/Plane.h>
#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Plane::Plane(double a, double b, double c, double d) : m_data(a, b, c, d) {}

Plane::Plane(__CPnt origin, __CPnt xPoint, __CPnt yPoint) {
  if (origin.IsValid() && xPoint.IsValid() && yPoint.IsValid()) {
    gp_Vec xDir = xPoint.Data().Coord() - origin.Data().Coord();
    gp_Vec yDir = yPoint.Data().Coord() - origin.Data().Coord();
    gp_Vec normal = xDir ^ yDir;
    if (normal.SquareMagnitude() != 0.0) {
      m_data = gp_Ax3(origin.Data(), normal, xDir);
      return;
    }
  }
  *this = Plane::Unset();
}

Plane::Plane(__CPnt origin, __CVec xDirection, __CVec yDirection) {
  if (origin.IsValid() && xDirection.IsValid() && yDirection.IsValid()) {
    gp_Vec normal = xDirection.Data() ^ yDirection.Data();
    if (normal.SquareMagnitude() != 0.0) {
      m_data = gp_Ax3(origin.Data(), normal, xDirection.Data());
      return;
    }
  }
  *this = Plane::Unset();
}

Plane::Plane(__CPnt origin, __CVec normal)
    : m_data(origin.Data(), normal.Data()) {}

Plane::Plane(const gp_Pln &pln) : m_data(pln) {}

Plane::Plane(const gp_Ax3 &ax3) : m_data(ax3) {}

Plane::Plane(__CPln plane) : m_data(plane.m_data) {}

__CPln Plane::Unset() noexcept {
  static Plane Plane_Unset(Point3d::Unset(), Vector3d::ZAxis());
  return Plane_Unset;
}

bool Plane::IsValid() const {
  return OcctMath::IsValidDouble(m_data.Location().X()) &&
         OcctMath::IsValidDouble(m_data.Location().Y()) &&
         OcctMath::IsValidDouble(m_data.Location().Z());
}

} // namespace Geometry
} // namespace OcctCommon
