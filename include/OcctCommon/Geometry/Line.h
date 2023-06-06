#ifndef OCCTCOMMON_GEOMETRY_LINE_H
#define OCCTCOMMON_GEOMETRY_LINE_H

#include <OcctCommon/Geometry/BoundingBox.h>
#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Vector3d.h>
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
  Line(Line &&line) noexcept = default;
  Line &operator=(__CLin line) = default;

public:
  static __CLin Unset();
  BoundingBox BoundingBox() const;
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
  static bool TryFitlineToPoints(T begin, T end, Line &fitLine);

private:
  gp_Lin m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
