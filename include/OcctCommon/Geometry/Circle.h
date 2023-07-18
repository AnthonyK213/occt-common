#ifndef OCCTCOMMON_GEOMETRY_CIRCLE_H
#define OCCTCOMMON_GEOMETRY_CIRCLE_H

#include <OcctCommon/pch.h>

namespace OcctCommon {
namespace Geometry {

class Circle final : public GpWrapper<gp_Circ> {
  GP_WRAPPER

public:
  Circle(C_Arc arc);

  Circle(double radius);

  Circle(C_Pln plane, double radius);

  Circle(C_Pln plane, C_Pnt center, double radius);

  Circle(C_Pnt center, double radius);

  Circle(C_Pnt point1, C_Pnt point2, C_Pnt point3);

  Circle(C_Pnt startPoint, C_Vec tangentAtP, C_Pnt pointOnCircle);

  Circle(C_Circ circle) = default;

  Circle(Circle &&circle) noexcept = default;

  Circle &operator=(C_Circ circle) = default;

  Circle &operator=(Circle &&circle) noexcept = default;

public:
  static C_Circ Unset();

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

  static Circle TryFitCircleTT(C_Crv c1, C_Crv c2, double t1, double t2);

  static Circle TryFitCircleTTT(C_Crv c1, C_Crv c2, C_Crv c3, double t1,
                                double t2, double t3);

  bool ClosestParameter(C_Pnt testPoint, double &t);

  Point3d ClosestPoint(C_Pnt testPoint);

  Vector3d DerivativeAt(int32_t derivative, double t);

  bool EpsilonEquals(C_Circ other, double epsilon);

  bool IsInPlane(C_Pln plane, double tolerance);

  Point3d PointAt(double t);

  void Reverse();

  bool Rotate(double angle, C_Vec axis, C_Pnt point);

  bool Rotate(double angle, C_Vec axis);

  bool Rotate(double sinAngle, double conAngle, C_Vec axis, C_Pnt point);

  bool Rotate(double sinAngle, double conAngle, C_Vec axis);

  Vector3d TangentAt(double t);

  NurbsCurve ToNurbsCurve();

  NurbsCurve ToNurbsCurve(int32_t degree, int32_t cvCount);

  bool Transform(C_Trsf xform);

  bool Translate(C_Vec delta);
};

} // namespace Geometry
} // namespace OcctCommon

#endif
