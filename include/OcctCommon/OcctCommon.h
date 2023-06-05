#ifndef OCCTCOMMON_GEOMETRY_H
#define OCCTCOMMON_GEOMETRY_H

#include <Geom_BSplineCurve.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Line.hxx>
#include <Standard_Handle.hxx>
#include <gp_Pln.hxx>
#include <gp_Pnt.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>
#include <gp_XYZ.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <string>
#include <vector>

namespace OcctCommon {
namespace Geometry {

struct Arc;
struct BoundingBox;
struct Box;
struct Circle;
class Curve;
class GeometryBase;
struct Line;
class Mesh;
class NurbsCurve;
struct Plane;
struct Point3d;
class PolyCurve;
class Polyline;
class PolylineCurve;
class Surface;
struct Transform;
struct Vector3d;

} // namespace Geometry

class OcctMath;

} // namespace OcctCommon

using __CPnt = const OcctCommon::Geometry::Point3d &;
using __CVec = const OcctCommon::Geometry::Vector3d &;
using __CPln = const OcctCommon::Geometry::Plane &;
using __CTrsf = const OcctCommon::Geometry::Transform &;
using __Math = OcctCommon::OcctMath;

const double OCCTCOMMON_UNSET_VALUE = -1.23432101234321e+308;

#endif
