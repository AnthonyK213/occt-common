#ifndef OCCTCOMMON_GEOMETRY_LINE_H
#define OCCTCOMMON_GEOMETRY_LINE_H

#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/pch.h>

namespace OcctCommon {
namespace Geometry {

class Line final {
public:
  /// @brief
  /// @param x0
  /// @param y0
  /// @param z0
  /// @param x1
  /// @param y1
  /// @param z1
  Line(double x0, double y0, double z0, double x1, double y1, double z1);

  /// @brief
  /// @param from
  /// @param to
  Line(C_Pnt from, C_Pnt to);

  /// @brief
  /// @param start
  /// @param direction
  /// @param length
  explicit Line(C_Pnt start, C_Vec direction, double length);

  /// @brief
  /// @param start
  /// @param span
  Line(C_Pnt start, C_Vec span);

  /// @brief
  /// @param line
  Line(C_Lin line) = default;

  /// @brief
  /// @param line
  Line(Line &&line) noexcept = default;

  /// @brief
  /// @param line
  /// @return
  Line &operator=(C_Lin line) = default;

  /// @brief
  /// @param line
  /// @return
  Line &operator=(Line &&line) noexcept = default;

public:
  /// @brief
  /// @return
  static C_Lin Unset();

  /// @brief
  /// @return
  BoundingBox GetBoundingBox() const;

  /// @brief
  /// @return
  Vector3d Direction() const;

  /// @brief
  /// @return
  C_Pnt From() const;

  /// @brief
  /// @return
  double FromX() const;

  /// @brief
  /// @return
  double FromY() const;

  /// @brief
  /// @return
  double FromZ() const;

  /// @brief
  /// @return
  bool IsValid() const;

  /// @brief
  /// @return
  double Length() const;

  /// @brief
  /// @return
  C_Pnt To() const;

  /// @brief
  /// @return
  double ToX() const;

  /// @brief
  /// @return
  double ToY() const;

  /// @brief
  /// @return
  double ToZ() const;

  /// @brief
  /// @return
  Vector3d UnitTangent() const;

public:
  /// @brief
  /// @param curve0
  /// @param curve1
  /// @param t0
  /// @param t1
  /// @param perpendicular0
  /// @param perpendicular1
  /// @param line
  /// @return
  static bool TryCreateBetweenCurves(C_Crv curve0, C_Crv curve1, double &t0,
                                     double &t1, bool perpendicular0,
                                     bool perpendicular1, Line &line);

  /// @brief
  /// @tparam T
  /// @param first
  /// @param last
  /// @param fitLine
  /// @return
  template <typename T>
  static bool TryFitLineToPoints(T first, T last, Line &fitLine);

  /// @brief
  /// @param testPoint
  /// @return
  double ClosestParameter(C_Pnt testPoint) const;

  /// @brief
  /// @param testPoint
  /// @param limitToFiniteSegment
  /// @return
  Point3d ClosestPoint(C_Pnt testPoint, bool limitToFiniteSegment) const;

  /// @brief
  /// @param testPoint
  /// @param limitToFiniteSegment
  /// @return
  double DistanceTo(C_Pnt testPoint, bool limitToFiniteSegment) const;

  /// @brief
  /// @param other
  /// @param epsilon
  /// @return
  bool EpsilonEquals(C_Lin other, double epsilon) const;

  /// @brief
  /// @param other
  /// @return
  bool Equals(C_Lin other) const;

  /// @brief
  /// @param startLength
  /// @param endLength
  /// @return
  bool Extend(double startLength, double endLength);

  /// @brief
  /// @param box
  /// @param additionalLength
  /// @return
  bool ExtendThroughBox(C_BB box, double additionalLength);

  /// @brief
  /// @param box
  /// @return
  bool ExtendThroughBox(C_BB box);

  /// @brief
  /// @param box
  /// @return
  bool ExtendThroughBox(C_Box box);

  /// @brief
  void Flip();

  /// @brief
  /// @param testLine
  /// @return
  double MaximumDistanceTo(C_Lin testLine) const;

  /// @brief
  /// @param testPoint
  /// @return
  double MaximumDistanceTo(C_Pnt testPoint) const;

  /// @brief
  /// @param testLine
  /// @return
  double MinimumDistanceTo(C_Lin testLine) const;

  /// @brief
  /// @param testPoint
  /// @return
  double MinimumDistanceTo(C_Pnt testPoint) const;

  /// @brief
  /// @param t
  /// @return
  Point3d PointAt(double t) const;

  /// @brief
  /// @param distance
  /// @return
  Point3d PointAtLength(double distance) const;

  /// @brief
  /// @return
  H_NurbsCurve ToNurbsCurve() const;

  /// @brief
  /// @return
  std::string ToString() const;

  /// @brief
  /// @param xform
  /// @return
  bool Transform(C_Trsf xform);

  /// @brief
  /// @param plane
  /// @return
  bool TryGetPlane(Plane &plane) const;

public:
  /// @brief
  /// @param other
  /// @return
  bool operator!=(C_Lin other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator==(C_Lin other) const;

private:
  Point3d m_from;
  Point3d m_to;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
