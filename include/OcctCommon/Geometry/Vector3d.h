#ifndef OCCTCOMMON_GEOMETRY_VECTOR3D_H
#define OCCTCOMMON_GEOMETRY_VECTOR3D_H

#include <OcctCommon/_decl.h>

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
  explicit Vector3d(__CPnt point);

  /// @brief Copy constructor.
  /// @param vector
  Vector3d(__CVec vector);

  /// @brief Move constructor.
  /// @param vector
  Vector3d(Vector3d &&vector) noexcept = default;

  /// @brief
  /// @param vector
  /// @return
  Vector3d &operator=(__CVec vector) = default;

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
  static __CVec Unset();

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
  static __CVec XAxis();

  /// @brief
  /// @return
  static __CVec YAxis();

  /// @brief
  /// @return
  static __CVec ZAxis();

  /// @brief
  /// @return
  static __CVec Zero();

  /// @brief
  /// @param vector1
  /// @param vector2
  /// @return
  static Vector3d Add(__CVec vector1, __CVec vector2);

  /// @brief
  /// @param x
  /// @param y
  /// @param z
  /// @return
  static bool AreOrthogonal(__CVec x, __CVec y, __CVec z);

  /// @brief
  /// @param x
  /// @param y
  /// @param z
  /// @return
  static bool AreOrithonormal(__CVec x, __CVec y, __CVec z);

  /// @brief
  /// @param x
  /// @param y
  /// @param z
  /// @return
  static bool AreRighthanded(__CVec x, __CVec y, __CVec z);

  /// @brief
  /// @param a
  /// @param b
  /// @return
  static Vector3d CrossProduct(__CVec a, __CVec b);

  /// @brief
  /// @param vector
  /// @param t
  /// @return
  static Vector3d Divide(__CVec vector, double t);

  /// @brief
  /// @param vector
  /// @param t
  /// @return
  static Vector3d Mulitply(__CVec vector, double t);

  /// @brief
  /// @param t
  /// @param vector
  /// @return
  static Vector3d Mulitply(double t, __CVec vector);

  /// @brief
  /// @param vector1
  /// @param vector2
  /// @return
  static double Mulitply(__CVec vector1, __CVec vector2);

  /// @brief
  /// @param vector
  /// @return
  static Vector3d Negate(__CVec vector);

  /// @brief
  /// @param vector1
  /// @param vector2
  /// @return
  static Vector3d Subtract(__CVec vector1, __CVec vector2);

  /// @brief
  /// @param a
  /// @param b
  /// @param plane
  /// @return
  static double VectorAngle(__CVec a, __CVec b, __CPln plane);

  /// @brief
  /// @param a
  /// @param b
  /// @param vNormal
  /// @return
  static double VectorAngle(__CVec a, __CVec b, __CVec vNormal);

  /// @brief
  /// @param a
  /// @param b
  /// @return
  static double VectorAngle(__CVec a, __CVec b);

public:
  /// @brief
  /// @param other
  /// @return
  int CompareTo(__CVec other) const;

  /// @brief
  /// @param other
  /// @param epsilon
  /// @return
  bool EpsilonEquals(__CVec other, double epsilon) const;

  /// @brief
  /// @param vector
  /// @return
  bool Equals(__CVec vector) const;

  /// @brief
  /// @param other
  /// @param angleTolerance
  /// @return
  int IsParallelTo(__CVec other, double angleTolerance) const;

  /// @brief
  /// @param other
  /// @return
  int IsParallelTo(__CVec other) const;

  /// @brief
  /// @param other
  /// @param angleTolerance
  /// @return
  bool IsPerpendicularTo(__CVec other, double angleTolerance) const;

  /// @brief
  /// @param other
  /// @return
  bool IsPerpendicularTo(__CVec other) const;

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
  bool PerpendicularTo(__CVec other);

  /// @brief
  /// @return
  bool Reverse();

  /// @brief
  /// @param angleRadians
  /// @param rotationAxis
  /// @return
  bool Rotate(double angleRadians, __CVec rotationAxis);

  /// @brief
  /// @return
  std::string ToString() const;

  /// @brief
  /// @param transformation
  /// @return
  void Transform(__CTrsf transformation);

  /// @brief
  /// @return
  bool Unitize();

public:
  /// @brief
  /// @param other
  /// @return
  bool operator!=(__CVec other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator<(__CVec other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator<=(__CVec other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator==(__CVec other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator>(__CVec other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator>=(__CVec other) const;

  /// @brief
  /// @param vector
  /// @return
  const double operator*(__CVec vector) const;

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
  const Vector3d operator-(__CVec vector) const;

  /// @brief
  /// @param t
  /// @return
  const Vector3d operator/(double t) const;

  /// @brief
  /// @param vector
  /// @return
  const Vector3d operator+(__CVec vector) const;

  /// @brief
  /// @param vector
  /// @return
  Vector3d &operator+=(__CVec vector);

  /// @brief
  /// @param vector
  Vector3d &operator*=(__CVec vector);

  /// @brief
  /// @param t
  Vector3d &operator*=(double t);

  /// @brief
  /// @param vector
  /// @return
  Vector3d &operator-=(__CVec vector);

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
const Vector3d operator*(double t, __CVec vector);

} // namespace Geometry
} // namespace OcctCommon

#endif
