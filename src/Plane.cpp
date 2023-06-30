#include <OcctCommon/Geometry/Plane.h>
#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Plane::Plane(double a, double b, double c, double d)
    : _gpWrapper({a, b, c, d}) {}

Plane::Plane(C_Pnt origin, C_Pnt xPoint, C_Pnt yPoint) {
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

Plane::Plane(C_Pnt origin, C_Vec xDirection, C_Vec yDirection) {
  if (origin.IsValid() && xDirection.IsValid() && yDirection.IsValid()) {
    gp_Vec normal = xDirection.Data() ^ yDirection.Data();
    if (normal.SquareMagnitude() != 0.0) {
      m_data = gp_Ax3(origin.Data(), normal, xDirection.Data());
      return;
    }
  }
  *this = Plane::Unset();
}

Plane::Plane(C_Pnt origin, C_Vec normal) {
  if (origin.IsValid() && normal.IsValid()) {
    m_data = gp_Pln(origin.Data(), normal.Data());
    return;
  }
  *this = Plane::Unset();
}

Plane::Plane(C_Pln plane) : _gpWrapper(plane.m_data) {}

C_Pln Plane::Unset() noexcept {
  static Plane Plane_Unset(gp_Pln(Point3d::Unset().Data(), gp::DZ()));
  return Plane_Unset;
}

C_Pln Plane::WorldXY() noexcept {
  static Plane Plane_WorldXY{gp_Ax3(gp::XOY())};
  return Plane_WorldXY;
}

C_Pln Plane::WorldYZ() noexcept {
  static Plane Plane_WorldYZ{gp_Ax3(gp::YOZ())};
  return Plane_WorldYZ;
}

C_Pln Plane::WorldZX() noexcept {
  static Plane Plane_WorldZX{gp_Ax3(gp::ZOX())};
  return Plane_WorldZX;
}

bool Plane::IsValid() const {
  return OcctMath::IsValidXYZ(m_data.Location().XYZ());
}

Vector3d Plane::Normal() const { return ZAxis(); }

Point3d Plane::Origin() const { return Point3d(m_data.Location()); }

double Plane::OriginX() const { return m_data.Location().X(); }

double Plane::OriginY() const { return m_data.Location().Y(); }

double Plane::OriginZ() const { return m_data.Location().Z(); }

Vector3d Plane::XAxis() const {
  return Vector3d(m_data.XAxis().Direction());
}

Vector3d Plane::YAxis() const {
  return Vector3d(m_data.YAxis().Direction());
}

Vector3d Plane::ZAxis() const {
  return Vector3d(m_data.Axis().Direction());
}

Plane Plane::CreateFromFrame(C_Pnt origin, C_Vec xDirection,
                             C_Vec yDirection) {
  return Plane(origin, xDirection, yDirection);
}

Plane Plane::CreateFromNormal(C_Pnt origin, C_Vec normal) {
  return Plane(origin, normal);
}

Plane Plane::CreateFromNormalYup(C_Pnt origin, C_Vec yDirection) {
  gp_Ax3 ax3(origin.Data(), yDirection.Data());
  return Plane(gp_Ax3(origin.Data(), ax3.XDirection(), ax3.YDirection()));
}

Plane Plane::CreateFromPoints(C_Pnt origin, C_Pnt xPoint, C_Pnt yPoint) {
  return Plane(origin, xPoint, yPoint);
}

Plane Plane::Clone() const {
  return *this;
}

} // namespace Geometry
} // namespace OcctCommon
