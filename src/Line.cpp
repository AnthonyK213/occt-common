#include <OcctCommon/Geometry/BoundingBox.h>
#include <OcctCommon/Geometry/Line.h>
#include <OcctCommon/Geometry/Transform.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Line::Line(double x0, double y0, double z0, double x1, double y1, double z1)
    : m_from(x0, y0, z0), m_to(x1, y1, z1) {}

Line::Line(__CPnt from, __CPnt to) : m_from(from), m_to(to) {}

Line::Line(__CPnt start, __CVec direction, double length) {
  gp_Dir dir = direction.Data();
  m_from = start;
  m_to = Point3d(start.Data().XYZ() + dir.XYZ() * length);
}

Line::Line(__CPnt start, __CVec span)
    : m_from(start), m_to(start.Data().XYZ() + span.Data().XYZ()) {}

__CLin Line::Unset() {
  static Line Line_Unset{Point3d::Unset(), Point3d::Unset()};
  return Line_Unset;
}

// TODO
BoundingBox Line::GetBoundingBox() const { return BoundingBox(); }

Vector3d Line::Direction() const { return m_to - m_from; }

__CPnt Line::From() const { return m_from; }

double Line::FromX() const { return m_from.X(); }

double Line::FromY() const { return m_from.Y(); }

double Line::FromZ() const { return m_from.Z(); }

bool Line::IsValid() const {
  if (m_from.IsValid() && m_to.IsValid())
    return m_from != m_to;
  return false;
}

double Line::Length() const { return m_from.DistanceTo(m_to); }

__CPnt Line::To() const { return m_to; }

double Line::ToX() const { return m_to.X(); }

double Line::ToY() const { return m_to.Y(); }

double Line::ToZ() const { return m_to.Z(); }

Vector3d Line::UnitTangent() const {
  Vector3d tangent = Direction();
  tangent.Unitize();
  return tangent;
}

double Line::ClosestParameter(__CPnt testPoint) const {
  Handle(Geom_Line) line = new Geom_Line(m_from.Data(), Direction().Data());
  GeomAdaptor_Curve adaptor = GeomAdaptor_Curve(line);
  Extrema_ExtPC extrema = Extrema_ExtPC(testPoint.Data(), adaptor);
  if (!extrema.IsDone()) {
    throw std::runtime_error("");
  }
  Point3d point = Point3d(extrema.Point(1).Value());
  if (point == m_from) {
    return 0.0;
  }
  return (point - m_from) * Direction() / m_from.DistanceToSquared(m_to);
}

Point3d Line::ClosestParameter(__CPnt testPoint,
                               bool limitToFiniteSegment) const {
  double t = ClosestParameter(testPoint);
  if (limitToFiniteSegment) {
    t = std::max(t, 0.0);
    t = std::min(t, 1.0);
  }
  return PointAt(t);
}

void Line::Flip() { std::swap(m_from, m_to); }

Point3d Line::PointAt(double t) const { return m_from * (1.0 - t) + m_to * t; }

Point3d Line::PointAtLength(double distance) const {
  return m_from + UnitTangent() * distance;
}

bool Line::operator!=(__CLin other) const {
  return m_from != other.m_from || m_to != other.m_to;
}

bool Line::operator==(__CLin other) const {
  return m_from == other.m_from && m_to == other.m_to;
}

} // namespace Geometry
} // namespace OcctCommon
