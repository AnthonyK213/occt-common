#ifndef OCCTCOMMON_GEOMETRY_PLANE_H
#define OCCTCOMMON_GEOMETRY_PLANE_H

#include <OcctCommon/pch.h>

namespace OcctCommon {
namespace Geometry {

class Plane final : public GpWrapper<gp_Pln> {
  GP_WRAPPER

public:
  /// @brief
  /// @param a
  /// @param b
  /// @param c
  /// @param d
  Plane(double a, double b, double c, double d);

  /// @brief
  /// @param origin
  /// @param xPoint
  /// @param yPoint
  Plane(C_Pnt origin, C_Pnt xPoint, C_Pnt yPoint);

  /// @brief
  /// @param origin
  /// @param xDirection
  /// @param yDirection
  Plane(C_Pnt origin, C_Vec xDirection, C_Vec yDirection);

  /// @brief
  /// @param origin
  /// @param normal
  Plane(C_Pnt origin, C_Vec normal);

  /// @brief
  /// @param plane
  Plane(C_Pln plane);

  /// @brief
  /// @param plane
  Plane(Plane &&plane) noexcept = default;

  /// @brief
  /// @param plane
  /// @return
  Plane &operator=(C_Pln plane) = default;

  /// @brief
  /// @param plane
  /// @return
  Plane &operator=(Plane &&plane) noexcept = default;

public:
  /// @brief
  /// @return
  static C_Pln Unset() noexcept;

  /// @brief
  /// @return
  static C_Pln WorldXY() noexcept;

  /// @brief
  /// @return
  static C_Pln WorldYZ() noexcept;

  /// @brief
  /// @return
  static C_Pln WorldZX() noexcept;

  /// @brief
  /// @return
  bool IsValid() const;

  /// @brief
  /// @return
  Vector3d Normal() const;

  /// @brief
  /// @return
  Point3d Origin() const;

  /// @brief
  /// @return
  double OriginX() const;

  /// @brief
  /// @return
  double OriginY() const;

  /// @brief
  /// @return
  double OriginZ() const;

  /// @brief
  /// @return
  Vector3d XAxis() const;

  /// @brief
  /// @return
  Vector3d YAxis() const;

  /// @brief
  /// @return
  Vector3d ZAxis() const;

public:
  /// @brief
  /// @param origin
  /// @param xDirection
  /// @param yDirection
  /// @return
  static Plane CreateFromFrame(C_Pnt origin, C_Vec xDirection,
                               C_Vec yDirection);

  /// @brief
  /// @param origin
  /// @param normal
  /// @return
  static Plane CreateFromNormal(C_Pnt origin, C_Vec normal);

  /// @brief
  /// @param origin
  /// @param yDirection
  /// @return
  static Plane CreateFromNormalYup(C_Pnt origin, C_Vec yDirection);

  /// @brief
  /// @param origin
  /// @param xPoint
  /// @param yPoint
  /// @return
  static Plane CreateFromPoints(C_Pnt origin, C_Pnt xPoint, C_Pnt yPoint);

  /// @brief
  /// @return
  Plane Clone() const;

  /// @brief
  /// @param testPoint
  /// @param s
  /// @param t
  /// @return
  bool ClosestParameter(C_Pnt testPoint, double &s, double &t) const;

  /// @brief
  /// @param testPoint
  /// @return
  Point3d ClosestPoint(C_Pnt testPoint) const;

  /// @brief
  /// @param bbox
  /// @param min
  /// @param max
  /// @return
  bool DistanceTo(C_BB bbox, double &min, double &max) const;

  /// @brief
  /// @param testPoint
  /// @return
  double DistanceTo(C_Pnt testPoint) const;

  /// @brief
  /// @param other
  /// @param epsilon
  /// @return
  bool EpsilonEquals(C_Pln other, double epsilon) const;

  /// @brief
  /// @param plane
  /// @return
  bool Equals(C_Pln plane) const;

  /// @brief
  /// @param box
  /// @param s
  /// @param t
  /// @return
  bool ExtendThroughBox(C_Box box, Interval &s, Interval &t);

  /// @brief
  void Flip();

  /// @brief
  /// @return
  void GetPlaneEquation(double &a, double &b, double &c, double &d) const;

  /// @brief 
  /// @param plane 
  /// @return 
  bool IsCoplanar(C_Pln plane) const;

  /// @brief
  /// @param plane
  /// @param tolerance
  /// @return
  bool IsCoplanar(C_Pln plane, double tolerance) const;

  /// @brief
  /// @param u
  /// @param v
  /// @return
  Point3d PointAt(double u, double v) const;

  /// @brief
  /// @param ptSample
  /// @param ptPlane
  /// @return
  bool RemapToPlaneSpace(C_Pnt ptSample, Point3d &ptPlane) const;

  /// @brief
  /// @param angle
  /// @param axis
  /// @return
  bool Rotate(double angle, C_Vec axis);

  /// @brief
  /// @param angle
  /// @param axis
  /// @param centerOfRotation
  /// @return
  bool Rotate(double angle, C_Vec axis, C_Pnt centerOfRotation);

  /// @brief
  /// @param sinAngle
  /// @param cosAngle
  /// @param axis
  /// @return
  bool Rotate(double sinAngle, double cosAngle, C_Vec axis);

  /// @brief
  /// @param sinAngle
  /// @param cosAngle
  /// @param axis
  /// @param centerOfRotation
  /// @return
  bool Rotate(double sinAngle, double cosAngle, C_Vec axis,
              C_Pnt centerOfRotation);

  /// @brief
  /// @return
  std::string ToString() const;

  /// @brief
  /// @param xform
  /// @return
  bool Transform(C_Trsf xform);

  /// @brief
  /// @param delta
  /// @return
  bool Translate(C_Vec delta);

  /// @brief Get the value of the plane equation at the point.
  /// @param p Evaluation point.
  /// @return returns pe[0]*p.X + pe[1]*p.Y + pe[2]*p.Z + pe[3] where
  /// pe[0], pe[1], pe[2] and pe[3] are the coefficients of the plane equation.
  double ValueAt(C_Pnt p) const;

public:
  /// @brief
  /// @tparam T
  /// @param first
  /// @param last
  /// @param plane
  /// @param maximumDeviation
  /// @return
  template <typename T>
  static int32_t FitPlaneToPoints(T first, T last, Plane &plane,
                                  double &maximumDeviation);

  /// @brief
  /// @tparam T
  /// @param first
  /// @param last
  /// @param plane
  /// @return
  template <typename T>
  static int32_t FitPlaneToPoints(T first, T last, Plane &plane);
};

} // namespace Geometry
} // namespace OcctCommon

#endif
