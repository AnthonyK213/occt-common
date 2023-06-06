#ifndef OCCTCOMMON_GEOMETRY_VECTOR3D_H
#define OCCTCOMMON_GEOMETRY_VECTOR3D_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class Vector3d {
public:
  Vector3d(double x, double y, double z);
  explicit Vector3d(__CPnt point);
  explicit Vector3d(const gp_Vec &vec);
  explicit Vector3d(const gp_XYZ &xyz);
  explicit Vector3d(const gp_Dir &dir);
  Vector3d(__CVec vector);
  Vector3d(Vector3d &&vector) noexcept = default;
  Vector3d &operator=(__CVec vector) = default;
  Vector3d &operator=(Vector3d &&vector) noexcept = default;

public:
  bool IsUnitVector() const;
  bool IsValid() const;
  bool IsZero() const;
  double Length() const;
  double SquareLength() const;
  static Vector3d Unset();
  double X() const;
  double Y() const;
  double Z() const;

public:
  static __CVec XAxis();
  static __CVec YAxis();
  static __CVec ZAxis();
  static __CVec Zero();
  static Vector3d Add(__CVec vector1, __CVec vector2);
  static bool AreOrthogonal(__CVec x, __CVec y, __CVec z);
  static bool AreOrithonormal(__CVec x, __CVec y, __CVec z);
  static bool AreRighthanded(__CVec x, __CVec y, __CVec z);
  static Vector3d CrossProduct(__CVec a, __CVec b);
  static Vector3d Divide(__CVec vector, double t);
  static Vector3d Mulitply(__CVec vector, double t);
  static Vector3d Mulitply(double t, __CVec vector);
  static double Mulitply(__CVec vector1, __CVec vector2);
  static Vector3d Negate(__CVec vector);
  static Vector3d Subtract(__CVec vector1, __CVec vector2);
  static double VectorAngle(__CVec a, __CVec b, __CPln plane);
  static double VectorAngle(__CVec a, __CVec b, __CVec vNormal);
  static double VectorAngle(__CVec a, __CVec b);

public:
  int CompareTo(__CVec other) const;
  bool EpsilonEquals(__CVec other, double epsilon) const;
  bool Equals(__CVec vector) const;
  int IsParallelTo(__CVec other, double angleTolerance) const;
  int IsParallelTo(__CVec other) const;
  bool IsPerpendicularTo(__CVec other, double angleTolerance) const;
  bool IsPerpendicularTo(__CVec other) const;
  bool IsTiny() const;
  bool PerpendicularTo(__CVec other);
  bool Reverse();
  bool Rotate(double angleRadiance, __CVec rotationAxis);
  std::string ToString() const;
  void Transform(__CTrsf transformation);
  bool Unitize();

public:
  bool operator!=(__CVec other) const;
  bool operator<(__CVec other) const;
  bool operator<=(__CVec other) const;
  bool operator==(__CVec other) const;
  bool operator>(__CVec other) const;
  bool operator>=(__CVec other) const;
  Vector3d operator*(__CVec vector) const;
  Vector3d &operator*=(__CVec vector);
  Vector3d operator*(double t) const;
  Vector3d &operator*=(double t);
  friend Vector3d operator*(double t, __CVec vector);
  Vector3d operator-() const;
  Vector3d operator-(__CVec vector) const;
  Vector3d &operator-=(__CVec vector);
  Vector3d operator/(double t) const;
  Vector3d &operator/=(double t);
  Vector3d operator+(__CVec vector) const;
  Vector3d &operator+=(__CVec vector);

public:
  const gp_Vec &Data() const;
  gp_Vec &DataMut();

private:
  gp_Vec m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
