#ifndef OCCTCOMMON_GEOMETRY_POINT3D_H
#define OCCTCOMMON_GEOMETRY_POINT3D_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class Point3d final : public _gpWrapper<gp_Pnt> {
  GP_BASE

public:
  Point3d(double x, double y, double z);
  explicit Point3d(__CVec vector);
  Point3d(__CPnt point);
  Point3d(Point3d &&point) noexcept = default;
  Point3d &operator=(__CPnt point) = default;
  Point3d &operator=(Point3d &&point) noexcept = default;

public:
  static __CPnt Origin();
  static __CPnt Unset();
  static Point3d Add(__CPnt point1, __CPnt point2);
  static Point3d Add(__CPnt point, __CVec vector);
  static Point3d Add(__CVec vector, __CPnt point);
  static Point3d Divide(__CPnt point, double t);
  static Point3d Multiply(__CPnt point, double t);
  static Point3d Multiply(double t, __CPnt point);
  static Vector3d Subtract(__CPnt point1, __CPnt point2);
  static Point3d Subtract(__CPnt point, __CVec vector);
  static bool TryParse(std::string input, Point3d &result);
  static void Interpolate(__CPnt point1, __CPnt point2, double t);

public:
  bool IsValid() const;
  double X() const;
  double Y() const;
  double Z() const;
  double DistanceTo(__CPnt point) const;
  double DistanceToSquared(__CPnt point) const;
  bool EpsilonEquals(__CPnt other, double epsilon) const;
  bool Equals(__CPnt other) const;
  std::string ToString() const;
  void Transform(__CTrsf xform);

public:
  bool operator!=(__CPnt other) const;
  bool operator<(__CPnt other) const;
  bool operator<=(__CPnt other) const;
  bool operator==(__CPnt other) const;
  bool operator>(__CPnt other) const;
  bool operator>=(__CPnt other) const;
  Point3d operator-(__CVec vector) const;
  Point3d &operator-=(__CVec vector);
  Point3d operator-() const;
  Point3d operator*(double t) const;
  Point3d &operator*=(double t);
  friend Point3d operator*(double t, __CPnt point);
  Point3d operator/(double t) const;
  Point3d &operator/=(double t);
  Point3d operator+(__CVec vector) const;
  Point3d &operator+=(__CVec vector);
  friend Point3d operator+(__CVec vector, __CPnt point);
  Point3d operator+(__CPnt other) const;
  Point3d &operator+=(__CPnt other);
  Vector3d operator-(__CPnt other) const;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
