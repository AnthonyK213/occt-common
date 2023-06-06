#ifndef OCCTCOMMON_GEOMETRY_VECTOR3D_H
#define OCCTCOMMON_GEOMETRY_VECTOR3D_H

#include <OcctCommon/OcctCommon.h>

namespace OcctCommon {
namespace Geometry {

class Vector3d {
public:
  Vector3d(double x, double y, double z);
  explicit Vector3d(__CPnt point);
  explicit Vector3d(const gp_Vec &vec);
  explicit Vector3d(const gp_XYZ &xyz);
  Vector3d(__CVec vector);
  Vector3d(Vector3d &&vector) noexcept;

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
  static Vector3d XAxis();
  static Vector3d YAxis();
  static Vector3d ZAxis();
  static Vector3d Zero();

public:
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
  int CompareTo(__CVec other);
  bool EpsilonEquals(__CVec other, double epsilon);
  bool Equals(__CVec vector);
  int IsParallelTo(__CVec other, double angleTolerance);
  int IsParallelTo(__CVec other);
  bool IsPerpendicularTo(__CVec other, double angleTolerance);
  bool IsPerpendicularTo(__CVec other);
  bool IsTiny();
  bool PerpendicularTo(__CVec other);
  bool Reverse();
  bool Rotate(double angleRadiance, __CVec rotationAxis);
  std::string ToString();
  void Transform(__CTrsf transformation);
  bool Unitize();

public:
  bool operator!=(__CVec other);
  bool operator==(__CVec other);

public:
  const gp_Vec &Data() const;
  gp_Vec &DataMut();

private:
  gp_Vec m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
