#ifndef OCCTCOMMON_GEOMETRY_POINT3D_H
#define OCCTCOMMON_GEOMETRY_POINT3D_H

#include <OcctCommon/OcctCommon.h>
#include <OcctCommon/Geometry/Transform.h>

namespace OcctCommon {
namespace Geometry {

struct Point3d {
public:
  Point3d(double x, double y, double z);
  explicit Point3d(const gp_Pnt &pnt);
  explicit Point3d(const gp_XYZ &xyz);
  explicit Point3d(const Vector3d &vector);
  Point3d(__CPnt point);
  Point3d(Point3d &&point) noexcept;

public:
  static Point3d Origin();
  static Point3d Unset();
  static Point3d Add(__CPnt point1, __CPnt point2);
  static Point3d Add(__CPnt point, __CVec vector);
  static Point3d Add(__CVec vector, __CPnt point);
  static Point3d Divide(__CPnt point, double t);
  static Point3d Multiply(__CPnt point, double t);
  static Point3d Multiply(double t, __CPnt point);
  static Vector3d Subtract(__CPnt point1, __CPnt point2);
  static Point3d Subtract(__CPnt point, const Vector3d &vector);
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
  void Transform(Transform xform);

public:
  Point3d &operator=(__CPnt point);
  Point3d &operator=(Point3d &&point) noexcept;
  bool operator!=(__CPnt other) const;
  bool operator<(__CPnt other) const;
  bool operator<=(__CPnt other) const;
  bool operator==(__CPnt other) const;
  bool operator>(__CPnt other) const;
  bool operator>=(__CPnt other) const;
  const Point3d operator-(const Vector3d &vector) const;
  const Point3d operator-() const;
  const Point3d operator*(double t) const;
  friend const Point3d operator*(double t, __CPnt point);
  const Point3d operator/(double t) const;
  const Point3d operator+(const Vector3d &vector) const;
  friend const Point3d operator+(const Vector3d &vector, __CPnt point);
  const Point3d operator+(__CPnt other) const;
  const Vector3d operator-(__CPnt other) const;

public:
  const gp_Pnt &Data() const;
  gp_Pnt &DataMut();

private:
  gp_Pnt m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
