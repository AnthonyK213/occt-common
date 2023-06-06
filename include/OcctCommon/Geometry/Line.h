#ifndef OCCTCOMMON_GEOMETRY_LINE_H
#define OCCTCOMMON_GEOMETRY_LINE_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class Line {
public:
  Line(double x0, double y0, double z0, double x1, double y1, double z1);
  Line(__CPnt from, __CPnt to);
  Line(__CPnt start, __CVec direction, double length);
  Line(__CPnt start, __CVec span);
  Line(__CLin line);
  explicit Line(const gp_Lin &lin);
  Line(Line &&line) noexcept = default;
  Line &operator=(__CLin line) = default;
  Line &operator=(Line &&line) noexcept = default;

public:
  static __CLin Unset();
  BoundingBox GetBoundingBox() const;
  Vector3d Direction() const;
  __CPnt From() const;
  double FromX() const;
  double FromY() const;
  double FromZ() const;
  bool IsValid() const;
  double Length() const;
  __CPnt To() const;
  double ToX() const;
  double ToY() const;
  double ToZ() const;
  Vector3d UnitTangent() const;

public:
  template <typename T>
  static bool TryFitLineToPoints(T first, T last, Line &fitLine);
  double ClosestParameter(__CPnt testPoint) const;
  double ClosestParameter(__CPnt testPoint, bool limitToFiniteSegment) const;
  double DistanceTo(__CPnt testPoint, bool limitToFiniteSegment) const;
  bool EpsilonEquals(__CLin other, double epsilon) const;
  bool Equals(__CLin other) const;
  bool Extend(double startLength, double endLength);
  bool ExtendThroughBox(__CBB box, double additionalLength);
  bool ExtendThroughBox(__CBB box);
  bool ExtendThroughBox(__CBox box);
  void Flip();
  double MaximumDistanceTo(__CLin testLine) const;
  double MaximumDistanceTo(__CPnt testPoint) const;
  double MinimumDistanceTo(__CLin testLine) const;
  double MinimumDistanceTo(__CPnt testPoint) const;
  Point3d PointAt(double t) const;
  Point3d PointAtLength(double distance) const;
  NurbsCurve ToNurbsCurve() const;
  std::string ToString() const;
  bool Transform(__CTrsf xform);
  bool TryGetPlane(Plane &plane) const;

public:
  bool operator!=(__CLin other) const;
  bool operator==(__CLin other) const;

public:
  const gp_Lin &Data() const;
  gp_Lin &DataMut();

private:
  gp_Lin m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
