#ifndef OCCTCOMMON_GEOMETRY_POINT3D_H
#define OCCTCOMMON_GEOMETRY_POINT3D_H

#include <OcctCommon/Geometry/Transform.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <gp_Pnt.hxx>
#include <string>

namespace OcctCommon {
namespace Geometry {

struct Point3d {
public:
  Point3d(double x, double y, double z);
  explicit Point3d(const gp_Pnt &pnt);
  Point3d(const Point3d &point);
  Point3d(Point3d &&point) noexcept;

public:
  static Point3d Origin();
  static Point3d Unset();
  static Point3d Add(const Point3d &point1, const Point3d &point2);
  static Point3d Divide(const Point3d &point, double t);
  static Point3d Multiply(const Point3d &point, double t);
  static Point3d Multiply(double t, const Point3d &point);
  static Point3d Subtract(const Point3d &point1, const Point3d &point2);
  static bool TryParse(std::string input, Point3d &result);
  static void Interpolate(const Point3d &point1, const Point3d &point2,
                          double t);

public:
  bool IsValid() const;
  double X() const;
  double Y() const;
  double Z() const;
  double DistanceTo(const Point3d &point) const;
  double DistanceToSquared(const Point3d &point) const;
  bool EpsilonEquals(const Point3d &other, double epsilon) const;
  bool Equals(const Point3d &other) const;
  std::string ToString() const;
  void Transform(Transform xform);

public:
  Point3d &operator=(const Point3d &point);
  Point3d &operator=(Point3d &&point) noexcept;
  bool operator!=(const Point3d &other) const;
  bool operator<(const Point3d &other) const;
  bool operator<=(const Point3d &other) const;
  bool operator==(const Point3d &other) const;
  bool operator>(const Point3d &other) const;
  bool operator>=(const Point3d &other) const;
  const Point3d operator-(const Vector3d &vector) const;
  const Point3d operator-() const;
  const Point3d operator*(double t) const;
  friend const Point3d operator*(double t, const Point3d &point);
  const Point3d operator/(double t) const;
  const Point3d operator+(const Vector3d &vector) const;
  friend const Point3d operator+(const Vector3d &vector, const Point3d &point);
  const Point3d operator+(const Point3d &other) const;
  const Vector3d operator-(const Point3d &other) const;

public:
  gp_Pnt Data() const;
  gp_Pnt &DataMut();

private:
  gp_Pnt m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
