#ifndef OCCTCOMMON_GEOMETRY_PLANE_H
#define OCCTCOMMON_GEOMETRY_PLANE_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class Plane final : public _gpWrapper<gp_Pln> {
  GP_BASE

public:
  Plane(double a, double b, double c, double d);
  Plane(__CPnt origin, __CPnt xPoint, __CPnt yPoint);
  Plane(__CPnt origin, __CVec xDirection, __CVec yDirection);
  Plane(__CPnt origin, __CVec normal);
  Plane(__CPln plane);
  Plane(Plane &&plane) noexcept = default;
  Plane &operator=(__CPln plane) = default;
  Plane &operator=(Plane &&plane) noexcept = default;

public:
  static __CPln Unset() noexcept;
  static __CPln WorldXY() noexcept;
  static __CPln WorldYZ() noexcept;
  static __CPln WorldZX() noexcept;
  bool IsValid() const;
  Vector3d Normal() const;
  Point3d Origin() const;
  double OriginX() const;
  double OriginY() const;
  double OriginZ() const;
  Vector3d XAxis() const;
  Vector3d YAxis() const;
  Vector3d ZAxis() const;

public:
  static Plane CreateFromFrame(__CPnt origin, __CVec xDirection,
                               __CVec yDirection);
  static Plane CreateFromNormal(__CPnt origin, __CVec normal);
  static Plane CreateFromNormalYup(__CPnt origin, __CVec yDirection);
  static Plane CreateFromPoints(__CPnt origin, __CPnt xPoint, __CPnt yPoint);
  Plane Clone() const;
  bool ClosestParameter(__CPnt testPoint, double &s, double &t) const;
  Point3d ClosestPoint(__CPnt testPoint) const;
  bool DistanceTo(__CBB bbox, double &min, double &max) const;
  double DistanceTo(__CPnt testPoint) const;
  bool EpsilonEquals(__CPln other, double epsilon) const;
  bool Equals(__CPln plane) const;
  bool ExtendThroughBox(__CBox box, Interval &s, Interval &t);
  void Flip();
  std::array<double, 4> GetPlaneEquation() const;
  bool IsCoplanar(__CPln plane, double tolerance) const;
  Point3d PointAt(double u, double v) const;
  bool RemapToPlaneSpace(__CPnt ptSample, Point3d &ptPlane) const;
  bool Rotate(double angle, __CVec axis);
  bool Rotate(double angle, __CVec axis, __CPnt centerOfRotation);
  bool Rotate(double sinAngle, double cosAngle, __CVec axis);
  bool Rotate(double sinAngle, double cosAngle, __CVec axis,
              __CPnt centerOfRotation);
  std::string ToString() const;
  bool Transform(__CTrsf xform);
  bool Translate(__CVec delta);
  bool UpdateEquation(); // ?
  double ValueAt(__CPnt p) const;

public:
  template <typename T>
  static int32_t FitPlaneToPoints(T first, T last, Plane &plane,
                                  double &maximumDeviation);

  template <typename T>
  static int32_t FitPlaneToPoints(T first, T last, Plane &plane);
};

} // namespace Geometry
} // namespace OcctCommon

#endif
