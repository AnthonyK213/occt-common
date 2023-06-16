#ifndef OCCTCOMMON_GEOMETRY_PLANE_H
#define OCCTCOMMON_GEOMETRY_PLANE_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class Plane final : public _gpWrapper<gp_Pln> {
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
  Plane(__CPnt origin, __CPnt xPoint, __CPnt yPoint);

  /// @brief
  /// @param origin
  /// @param xDirection
  /// @param yDirection
  Plane(__CPnt origin, __CVec xDirection, __CVec yDirection);

  /// @brief
  /// @param origin
  /// @param normal
  Plane(__CPnt origin, __CVec normal);

  /// @brief
  /// @param plane
  Plane(__CPln plane);

  /// @brief
  /// @param plane
  Plane(Plane &&plane) noexcept = default;

  /// @brief
  /// @param plane
  /// @return
  Plane &operator=(__CPln plane) = default;

  /// @brief
  /// @param plane
  /// @return
  Plane &operator=(Plane &&plane) noexcept = default;

public:
  /// @brief
  /// @return
  static __CPln Unset() noexcept;

  /// @brief
  /// @return
  static __CPln WorldXY() noexcept;

  /// @brief
  /// @return
  static __CPln WorldYZ() noexcept;

  /// @brief
  /// @return
  static __CPln WorldZX() noexcept;

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
  static Plane CreateFromFrame(__CPnt origin, __CVec xDirection,
                               __CVec yDirection);

  /// @brief
  /// @param origin
  /// @param normal
  /// @return
  static Plane CreateFromNormal(__CPnt origin, __CVec normal);

  /// @brief
  /// @param origin
  /// @param yDirection
  /// @return
  static Plane CreateFromNormalYup(__CPnt origin, __CVec yDirection);

  /// @brief
  /// @param origin
  /// @param xPoint
  /// @param yPoint
  /// @return
  static Plane CreateFromPoints(__CPnt origin, __CPnt xPoint, __CPnt yPoint);

  /// @brief
  /// @return
  Plane Clone() const;

  /// @brief
  /// @param testPoint
  /// @param s
  /// @param t
  /// @return
  bool ClosestParameter(__CPnt testPoint, double &s, double &t) const;

  /// @brief
  /// @param testPoint
  /// @return
  Point3d ClosestPoint(__CPnt testPoint) const;

  /// @brief
  /// @param bbox
  /// @param min
  /// @param max
  /// @return
  bool DistanceTo(__CBB bbox, double &min, double &max) const;

  /// @brief
  /// @param testPoint
  /// @return
  double DistanceTo(__CPnt testPoint) const;

  /// @brief
  /// @param other
  /// @param epsilon
  /// @return
  bool EpsilonEquals(__CPln other, double epsilon) const;

  /// @brief
  /// @param plane
  /// @return
  bool Equals(__CPln plane) const;

  /// @brief
  /// @param box
  /// @param s
  /// @param t
  /// @return
  bool ExtendThroughBox(__CBox box, Interval &s, Interval &t);

  /// @brief
  void Flip();

  /// @brief
  /// @return
  std::array<double, 4> GetPlaneEquation() const;

  /// @brief
  /// @param plane
  /// @param tolerance
  /// @return
  bool IsCoplanar(__CPln plane, double tolerance) const;

  /// @brief
  /// @param u
  /// @param v
  /// @return
  Point3d PointAt(double u, double v) const;

  /// @brief
  /// @param ptSample
  /// @param ptPlane
  /// @return
  bool RemapToPlaneSpace(__CPnt ptSample, Point3d &ptPlane) const;

  /// @brief
  /// @param angle
  /// @param axis
  /// @return
  bool Rotate(double angle, __CVec axis);

  /// @brief
  /// @param angle
  /// @param axis
  /// @param centerOfRotation
  /// @return
  bool Rotate(double angle, __CVec axis, __CPnt centerOfRotation);

  /// @brief
  /// @param sinAngle
  /// @param cosAngle
  /// @param axis
  /// @return
  bool Rotate(double sinAngle, double cosAngle, __CVec axis);

  /// @brief
  /// @param sinAngle
  /// @param cosAngle
  /// @param axis
  /// @param centerOfRotation
  /// @return
  bool Rotate(double sinAngle, double cosAngle, __CVec axis,
              __CPnt centerOfRotation);

  /// @brief
  /// @return
  std::string ToString() const;

  /// @brief
  /// @param xform
  /// @return
  bool Transform(__CTrsf xform);

  /// @brief
  /// @param delta
  /// @return
  bool Translate(__CVec delta);

  /// @brief
  /// @return
  bool UpdateEquation(); // ?

  /// @brief
  /// @param p
  /// @return
  double ValueAt(__CPnt p) const;

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
