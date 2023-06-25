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
  explicit Point3d(C_Vec vector);

  /// @brief
  /// @param point
  Point3d(C_Pnt point);

  /// @brief
  /// @param point
  Point3d(Point3d &&point) noexcept = default;

  /// @brief
  /// @param point
  /// @return
  Point3d &operator=(C_Pnt point) = default;

  /// @brief
  /// @param point
  /// @return
  Point3d &operator=(Point3d &&point) noexcept = default;

public:
  /// @brief
  /// @return
  static C_Pnt Origin();

  /// @brief
  /// @return
  static C_Pnt Unset();

  /// @brief
  /// @param point1
  /// @param point2
  /// @return
  static Point3d Add(C_Pnt point1, C_Pnt point2);

  /// @brief
  /// @param point
  /// @param vector
  /// @return
  static Point3d Add(C_Pnt point, C_Vec vector);

  /// @brief
  /// @param vector
  /// @param point
  /// @return
  static Point3d Add(C_Vec vector, C_Pnt point);

  /// @brief
  /// @param point
  /// @param t
  /// @return
  static Point3d Divide(C_Pnt point, double t);

  /// @brief
  /// @param point
  /// @param t
  /// @return
  static Point3d Multiply(C_Pnt point, double t);

  /// @brief
  /// @param t
  /// @param point
  /// @return
  static Point3d Multiply(double t, C_Pnt point);

  /// @brief
  /// @param point1
  /// @param point2
  /// @return
  static Vector3d Subtract(C_Pnt point1, C_Pnt point2);

  /// @brief
  /// @param point
  /// @param vector
  /// @return
  static Point3d Subtract(C_Pnt point, C_Vec vector);

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
  static void Interpolate(C_Pnt point1, C_Pnt point2, double t);

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
  double DistanceTo(C_Pnt point) const;

  /// @brief
  /// @param point
  /// @return
  double DistanceToSquared(C_Pnt point) const;

  /// @brief
  /// @param other
  /// @param epsilon
  /// @return
  bool EpsilonEquals(C_Pnt other, double epsilon) const;

  /// @brief
  /// @param other
  /// @return
  bool Equals(C_Pnt other) const;

  /// @brief
  /// @return
  std::string ToString() const;

  /// @brief
  /// @param xform
  /// @return
  void Transform(C_Trsf xform);

public:
  /// @brief
  /// @param other
  /// @return
  bool operator!=(C_Pnt other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator<(C_Pnt other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator<=(C_Pnt other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator==(C_Pnt other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator>(C_Pnt other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator>=(C_Pnt other) const;

  /// @brief
  /// @param vector
  /// @return
  const Point3d operator-(C_Vec vector) const;

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
  const Point3d operator+(C_Vec vector) const;

  /// @brief
  /// @param other
  /// @return
  const Point3d operator+(C_Pnt other) const;

  /// @brief
  /// @param other
  /// @return
  const Vector3d operator-(C_Pnt other) const;

  /// @brief
  /// @param t
  Point3d &operator*=(double t);

  /// @brief
  /// @param t
  Point3d &operator/=(double t);

  /// @brief
  /// @param vector
  Point3d &operator+=(C_Vec vector);

  /// @brief
  /// @param other
  Point3d &operator+=(C_Pnt other);
};

/// @brief
/// @param vector
/// @param point
/// @return
const Point3d operator+(C_Vec vector, C_Pnt point);

/// @brief
/// @param t
/// @param point
/// @return
const Point3d operator*(double t, C_Pnt point);

} // namespace Geometry
} // namespace OcctCommon

#endif
