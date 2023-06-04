#ifndef OCCTCOMMON_GEOMETRY_POINT3D_H
#define OCCTCOMMON_GEOMETRY_POINT3D_H

#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepTools_WireExplorer.hxx>
#include <BRep_Tool.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Conic.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Line.hxx>
#include <Geom_OffsetCurve.hxx>
#include <Geom_Transformation.hxx>
#include <IntTools_EdgeEdge.hxx>
#include <OcctCommon/Geometry/Transform.h>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Builder.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Wire.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Ax3.hxx>
#include <gp_Dir.hxx>
#include <gp_Pln.hxx>
#include <gp_Pnt.hxx>
#include <string>

namespace OcctCommon {
namespace Geometry {

struct Point3d {
public:
  Point3d(double x, double y, double z);
  Point3d(const Point3d &point);
  Point3d(Point3d &&point) noexcept;

public:
  static Point3d Origin();
  static Point3d Unset();
  static Point3d Add(const Point3d &point1, const Point3d &point2);
  static Point3d Divide(const Point3d &point, double t);
  static Point3d Multiply(const Point3d &point, double t);
  static Point3d Multiply(double t, const Point3d &point);
  static Point3d Subtract(const Point3d &point1, const Point3d &point2);
  static bool TryParse(std::string input, Point3d &result);
  static void Interpolate(const Point3d &point1, const Point3d &point2,
                          double t);

public:
  bool IsValid() const;
  double X() const;
  double Y() const;
  double Z() const;
  double DistanceTo(const Point3d &point) const;
  double DistanceToSquared(const Point3d &point) const;
  bool EpsilonEquals(const Point3d &other, double epsilon) const;
  bool Equals(const Point3d &other) const;
  std::string ToString() const;
  void Transform(Transform xform);

public:
  gp_Pnt Pnt() const;
  gp_Pnt &PntMut();

private:
  gp_Pnt m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
