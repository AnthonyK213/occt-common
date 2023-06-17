#ifndef OCCTCOMMON_GEOMETRY_POINT3D_H
#define OCCTCOMMON_GEOMETRY_POINT3D_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class Point3d final : public _gpWrapper<gp_Pnt> {
  GP_WRAPPER

public:
  /// @brief
  /// @param x
  /// @param y
  /// @param z
  Point3d(double x, double y, double z);

  /// @brief
  /// @param vector
  explicit Point3d(__CVec vector);

  /// @brief
  /// @param point
  Point3d(__CPnt point);

  /// @brief
  /// @param point
  Point3d(Point3d &&point) noexcept = default;

  /// @brief
  /// @param point
  /// @return
  Point3d &operator=(__CPnt point) = default;

  /// @brief
  /// @param point
  /// @return
  Point3d &operator=(Point3d &&point) noexcept = default;

public:
  /// @brief
  /// @return
  static __CPnt Origin();

  /// @brief
  /// @return
  static __CPnt Unset();

  /// @brief
  /// @param point1
  /// @param point2
  /// @return
  static Point3d Add(__CPnt point1, __CPnt point2);

  /// @brief
  /// @param point
  /// @param vector
  /// @return
  static Point3d Add(__CPnt point, __CVec vector);

  /// @brief
  /// @param vector
  /// @param point
  /// @return
  static Point3d Add(__CVec vector, __CPnt point);

  /// @brief
  /// @param point
  /// @param t
  /// @return
  static Point3d Divide(__CPnt point, double t);

  /// @brief
  /// @param point
  /// @param t
  /// @return
  static Point3d Multiply(__CPnt point, double t);

  /// @brief
  /// @param t
  /// @param point
  /// @return
  static Point3d Multiply(double t, __CPnt point);

  /// @brief
  /// @param point1
  /// @param point2
  /// @return
  static Vector3d Subtract(__CPnt point1, __CPnt point2);

  /// @brief
  /// @param point
  /// @param vector
  /// @return
  static Point3d Subtract(__CPnt point, __CVec vector);

  /// @brief
  /// @param input
  /// @param result
  /// @return
  static bool TryParse(std::string input, Point3d &result);

  /// @brief
  /// @param point1
  /// @param point2
  /// @param t
  /// @return
  static void Interpolate(__CPnt point1, __CPnt point2, double t);

public:
  /// @brief
  /// @return
  bool IsValid() const;

  /// @brief
  /// @return
  double X() const;

  /// @brief
  /// @return
  double Y() const;

  /// @brief
  /// @return
  double Z() const;

  /// @brief
  /// @param point
  /// @return
  double DistanceTo(__CPnt point) const;

  /// @brief
  /// @param point
  /// @return
  double DistanceToSquared(__CPnt point) const;

  /// @brief
  /// @param other
  /// @param epsilon
  /// @return
  bool EpsilonEquals(__CPnt other, double epsilon) const;

  /// @brief
  /// @param other
  /// @return
  bool Equals(__CPnt other) const;

  /// @brief
  /// @return
  std::string ToString() const;

  /// @brief
  /// @param xform
  /// @return
  void Transform(__CTrsf xform);

public:
  /// @brief
  /// @param other
  /// @return
  bool operator!=(__CPnt other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator<(__CPnt other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator<=(__CPnt other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator==(__CPnt other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator>(__CPnt other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator>=(__CPnt other) const;

  /// @brief
  /// @param vector
  /// @return
  const Point3d operator-(__CVec vector) const;

  /// @brief
  /// @return
  const Point3d operator-() const;

  /// @brief
  /// @param t
  /// @return
  const Point3d operator*(double t) const;

  /// @brief
  /// @param t
  /// @return
  const Point3d operator/(double t) const;

  /// @brief
  /// @param vector
  /// @return
  const Point3d operator+(__CVec vector) const;

  /// @brief
  /// @param other
  /// @return
  const Point3d operator+(__CPnt other) const;

  /// @brief
  /// @param other
  /// @return
  const Vector3d operator-(__CPnt other) const;

  /// @brief
  /// @param t
  Point3d &operator*=(double t);

  /// @brief
  /// @param t
  Point3d &operator/=(double t);

  /// @brief
  /// @param vector
  Point3d &operator+=(__CVec vector);

  /// @brief
  /// @param other
  Point3d &operator+=(__CPnt other);
};

/// @brief
/// @param vector
/// @param point
/// @return
const Point3d operator+(__CVec vector, __CPnt point);

/// @brief
/// @param t
/// @param point
/// @return
const Point3d operator*(double t, __CPnt point);

} // namespace Geometry
} // namespace OcctCommon

#endif
