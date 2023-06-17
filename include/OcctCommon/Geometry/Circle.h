#ifndef OCCTCOMMON_GEOMETRY_CIRCLE_H
#define OCCTCOMMON_GEOMETRY_CIRCLE_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class Circle final : public _gpWrapper<gp_Circ> {
  GP_WRAPPER

public:
  Circle(__CArc arc);

  Circle(double radius);

  Circle(__CPln plane, double radius);

  Circle(__CPln plane, __CPnt center, double radius);

  Circle(__CPnt center, double radius);

  Circle(__CPnt point1, __CPnt point2, __CPnt point3);

  Circle(__CPnt startPoint, __CVec tangentAtP, __CPnt pointOnCircle);

  Circle(__CCirc circle) = default;

  Circle(Circle &&circle) noexcept = default;

  Circle &operator=(__CCirc circle) = default;

  Circle &operator=(Circle &&circle) noexcept = default;

public:
  static __CCirc Unset();

  BoundingBox GetBoundingBox() const;

  Point3d Center() const;

  double Circumference() const;

  double Diameter() const;

  bool IsValid() const;

  Vector3d Normal() const;

  Plane GetPlane() const;

  double Radius() const;

public:
  template <typename T>
  static bool TryFitCircleToPoints(T begin, T end, Circle &circle);

  static Circle TryFitCircleTT(__CCrv c1, __CCrv c2, double t1, double t2);

  static Circle TryFitCircleTTT(__CCrv c1, __CCrv c2, __CCrv c3, double t1,
                                double t2, double t3);

  bool ClosestParameter(__CPnt testPoint, double &t);

  Point3d ClosestPoint(__CPnt testPoint);

  Vector3d DerivativeAt(int32_t derivative, double t);

  bool EpsilonEquals(__CCirc other, double epsilon);

  bool IsInPlane(__CPln plane, double tolerance);

  Point3d PointAt(double t);

  void Reverse();

  bool Rotate(double angle, __CVec axis, __CPnt point);

  bool Rotate(double angle, __CVec axis);

  bool Rotate(double sinAngle, double conAngle, __CVec axis, __CPnt point);

  bool Rotate(double sinAngle, double conAngle, __CVec axis);

  Vector3d TangentAt(double t);

  NurbsCurve ToNurbsCurve();

  NurbsCurve ToNurbsCurve(int32_t degree, int32_t cvCount);

  bool Transform(__CTrsf xform);

  bool Translate(__CVec delta);
};

} // namespace Geometry
} // namespace OcctCommon

#endif
