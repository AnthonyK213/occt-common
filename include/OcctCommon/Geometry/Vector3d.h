#ifndef OCCTCOMMON_GEOMETRY_VECTOR3D_H
#define OCCTCOMMON_GEOMETRY_VECTOR3D_H

#include <OcctCommon/pch.h>

namespace OcctCommon {
namespace Geometry {

class Vector3d final : public _gpWrapper<gp_Vec> {
  GP_WRAPPER

public:
  /// @brief Initializes a new instance of a vector, using its three
  /// components.
  /// @param x The X (first) component.
  /// @param y The Y (second) component.
  /// @param z The Z (third) component.
  Vector3d(double x, double y, double z);

  /// @brief Initializes a new instance of a vector using a point.
  /// Initializes a new instance of a vector, copying the three components from
  /// the three coordinates of a point.
  /// @param point The point to copy from.
  explicit Vector3d(C_Pnt point);

  /// @brief Copy constructor.
  /// @param vector
  Vector3d(C_Vec vector);

  /// @brief Move constructor.
  /// @param vector
  Vector3d(Vector3d &&vector) noexcept = default;

  /// @brief
  /// @param vector
  /// @return
  Vector3d &operator=(C_Vec vector) = default;

  /// @brief
  /// @param vector
  /// @return
  Vector3d &operator=(Vector3d &&vector) noexcept = default;

public:
  /// @brief
  /// @return
  bool IsUnitVector() const;

  /// @brief
  /// @return
  bool IsValid() const;

  /// @brief
  /// @return
  bool IsZero() const;

  /// @brief
  /// @return
  double Length() const;

  /// @brief
  /// @return
  double SquareLength() const;

  /// @brief
  /// @return
  static C_Vec Unset();

  /// @brief
  /// @return
  double X() const;

  /// @brief
  /// @return
  double Y() const;

  /// @brief
  /// @return
  double Z() const;

public:
  /// @brief
  /// @return
  static C_Vec XAxis();

  /// @brief
  /// @return
  static C_Vec YAxis();

  /// @brief
  /// @return
  static C_Vec ZAxis();

  /// @brief
  /// @return
  static C_Vec Zero();

  /// @brief
  /// @param vector1
  /// @param vector2
  /// @return
  static Vector3d Add(C_Vec vector1, C_Vec vector2);

  /// @brief
  /// @param x
  /// @param y
  /// @param z
  /// @return
  static bool AreOrthogonal(C_Vec x, C_Vec y, C_Vec z);

  /// @brief
  /// @param x
  /// @param y
  /// @param z
  /// @return
  static bool AreOrithonormal(C_Vec x, C_Vec y, C_Vec z);

  /// @brief
  /// @param x
  /// @param y
  /// @param z
  /// @return
  static bool AreRighthanded(C_Vec x, C_Vec y, C_Vec z);

  /// @brief
  /// @param a
  /// @param b
  /// @return
  static Vector3d CrossProduct(C_Vec a, C_Vec b);

  /// @brief
  /// @param vector
  /// @param t
  /// @return
  static Vector3d Divide(C_Vec vector, double t);

  /// @brief
  /// @param vector
  /// @param t
  /// @return
  static Vector3d Mulitply(C_Vec vector, double t);

  /// @brief
  /// @param t
  /// @param vector
  /// @return
  static Vector3d Mulitply(double t, C_Vec vector);

  /// @brief
  /// @param vector1
  /// @param vector2
  /// @return
  static double Mulitply(C_Vec vector1, C_Vec vector2);

  /// @brief
  /// @param vector
  /// @return
  static Vector3d Negate(C_Vec vector);

  /// @brief
  /// @param vector1
  /// @param vector2
  /// @return
  static Vector3d Subtract(C_Vec vector1, C_Vec vector2);

  /// @brief
  /// @param a
  /// @param b
  /// @param plane
  /// @return
  static double VectorAngle(C_Vec a, C_Vec b, C_Pln plane);

  /// @brief
  /// @param a
  /// @param b
  /// @param vNormal
  /// @return
  static double VectorAngle(C_Vec a, C_Vec b, C_Vec vNormal);

  /// @brief
  /// @param a
  /// @param b
  /// @return
  static double VectorAngle(C_Vec a, C_Vec b);

public:
  /// @brief
  /// @param other
  /// @return
  int CompareTo(C_Vec other) const;

  /// @brief
  /// @param other
  /// @param epsilon
  /// @return
  bool EpsilonEquals(C_Vec other, double epsilon) const;

  /// @brief
  /// @param vector
  /// @return
  bool Equals(C_Vec vector) const;

  /// @brief
  /// @param other
  /// @param angleTolerance
  /// @return
  int IsParallelTo(C_Vec other, double angleTolerance) const;

  /// @brief
  /// @param other
  /// @return
  int IsParallelTo(C_Vec other) const;

  /// @brief
  /// @param other
  /// @param angleTolerance
  /// @return
  bool IsPerpendicularTo(C_Vec other, double angleTolerance) const;

  /// @brief
  /// @param other
  /// @return
  bool IsPerpendicularTo(C_Vec other) const;

  /// @brief
  /// @param tolerance
  /// @return
  bool IsTiny(double tolerance) const;

  /// @brief
  /// @return
  bool IsTiny() const;

  /// @brief
  /// @param other
  /// @return
  bool PerpendicularTo(C_Vec other);

  /// @brief
  /// @return
  bool Reverse();

  /// @brief
  /// @param angleRadians
  /// @param rotationAxis
  /// @return
  bool Rotate(double angleRadians, C_Vec rotationAxis);

  /// @brief
  /// @return
  std::string ToString() const;

  /// @brief
  /// @param transformation
  /// @return
  void Transform(C_Trsf transformation);

  /// @brief
  /// @return
  bool Unitize();

public:
  /// @brief
  /// @param other
  /// @return
  bool operator!=(C_Vec other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator<(C_Vec other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator<=(C_Vec other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator==(C_Vec other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator>(C_Vec other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator>=(C_Vec other) const;

  /// @brief
  /// @param vector
  /// @return
  const double operator*(C_Vec vector) const;

  /// @brief
  /// @param t
  /// @return
  const Vector3d operator*(double t) const;

  /// @brief
  /// @return
  const Vector3d operator-() const;

  /// @brief
  /// @param vector
  /// @return
  const Vector3d operator-(C_Vec vector) const;

  /// @brief
  /// @param t
  /// @return
  const Vector3d operator/(double t) const;

  /// @brief
  /// @param vector
  /// @return
  const Vector3d operator+(C_Vec vector) const;

  /// @brief
  /// @param vector
  /// @return
  Vector3d &operator+=(C_Vec vector);

  /// @brief
  /// @param vector
  Vector3d &operator*=(C_Vec vector);

  /// @brief
  /// @param t
  Vector3d &operator*=(double t);

  /// @brief
  /// @param vector
  /// @return
  Vector3d &operator-=(C_Vec vector);

  /// @brief
  /// @param t
  /// @return
  Vector3d &operator/=(double t);

  /// @brief
  /// @param index
  /// @return
  double operator[](int index);
};

/// @brief
/// @param t
/// @param vector
/// @return
const Vector3d operator*(double t, C_Vec vector);

} // namespace Geometry
} // namespace OcctCommon

#endif
