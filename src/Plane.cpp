#include <OcctCommon/Geometry/Plane.h>
#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Plane::Plane(double a, double b, double c, double d)
    : _gpWrapper({a, b, c, d}) {}

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

Plane::Plane(__CPnt origin, __CVec normal) {
  if (origin.IsValid() && normal.IsValid()) {
    m_data = gp_Pln(origin.Data(), normal.Data());
    return;
  }
  *this = Plane::Unset();
}

Plane::Plane(__CPln plane) : _gpWrapper(plane.m_data) {}

__CPln Plane::Unset() noexcept {
  static Plane Plane_Unset(gp_Pln(Point3d::Unset().Data(), gp::DZ()));
  return Plane_Unset;
}

__CPln Plane::WorldXY() noexcept {
  static Plane Plane_WorldXY{gp_Ax3(gp::XOY())};
  return Plane_WorldXY;
}

__CPln Plane::WorldYZ() noexcept {
  static Plane Plane_WorldYZ{gp_Ax3(gp::YOZ())};
  return Plane_WorldYZ;
}

__CPln Plane::WorldZX() noexcept {
  static Plane Plane_WorldZX{gp_Ax3(gp::ZOX())};
  return Plane_WorldZX;
}

bool Plane::IsValid() const {
  return OcctMath::IsValidXYZ(m_data.Location().XYZ());
}

inline Vector3d Plane::Normal() const { return ZAxis(); }

inline Point3d Plane::Origin() const { return Point3d(m_data.Location()); }

inline double Plane::OriginX() const { return m_data.Location().X(); }

inline double Plane::OriginY() const { return m_data.Location().Y(); }

inline double Plane::OriginZ() const { return m_data.Location().Z(); }

inline Vector3d Plane::XAxis() const {
  return Vector3d(m_data.XAxis().Direction());
}

inline Vector3d Plane::YAxis() const {
  return Vector3d(m_data.YAxis().Direction());
}

inline Vector3d Plane::ZAxis() const {
  return Vector3d(m_data.Axis().Direction());
}

Plane Plane::CreateFromFrame(__CPnt origin, __CVec xDirection,
                             __CVec yDirection) {
  return Plane(origin, xDirection, yDirection);
}

Plane Plane::CreateFromNormal(__CPnt origin, __CVec normal) {
  return Plane(origin, normal);
}

Plane Plane::CreateFromNormalYup(__CPnt origin, __CVec yDirection) {
  gp_Ax3 ax3(origin.Data(), yDirection.Data());
  return Plane(gp_Ax3(origin.Data(), ax3.XDirection(), ax3.YDirection()));
}

Plane Plane::CreateFromPoints(__CPnt origin, __CPnt xPoint, __CPnt yPoint) {
  return Plane(origin, xPoint, yPoint);
}

Plane Plane::Clone() const {
  return *this;
}

} // namespace Geometry
} // namespace OcctCommon
