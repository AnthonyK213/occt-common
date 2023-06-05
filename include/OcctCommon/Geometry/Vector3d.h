#ifndef OCCTCOMMON_GEOMETRY_VECTOR3D_H
#define OCCTCOMMON_GEOMETRY_VECTOR3D_H

#include <OcctCommon/OcctCommon.h>

namespace OcctCommon {
namespace Geometry {

struct Vector3d {

public:
  Vector3d(double x, double y, double z);
  explicit Vector3d(const Point3d &point);
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
  int CompareTo(__CVec other);
  static Vector3d CrossProduct(__CVec a, __CVec b);

public:
  const gp_Vec &Data() const;
  gp_Vec &DataMut();

private:
  gp_Vec m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
