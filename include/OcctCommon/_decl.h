#ifndef OCCTCOMMON_GEOMETRY_H
#define OCCTCOMMON_GEOMETRY_H

#ifdef __linux__
#define DllExport
#elif _WIN32
#define DllExport __declspec(dllexport)
#endif

#include <Geom_BSplineCurve.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Line.hxx>
#include <Standard_Handle.hxx>
#include <gp.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Ax3.hxx>
#include <gp_Circ.hxx>
#include <gp_Lin.hxx>
#include <gp_Pln.hxx>
#include <gp_Pnt.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>
#include <gp_XYZ.hxx>
#include <string>
#include <vector>

const double OCCTCOMMON_UNSET_VALUE = -1.23432101234321e+308;

namespace OcctCommon {
namespace Geometry {

class DllExport Arc;
class DllExport ArcCurve;
class DllExport BoundingBox;
class DllExport Box;
class DllExport Circle;
class DllExport Curve;
class DllExport GeometryBase;
class DllExport Line;
class DllExport LineCurve;
class DllExport Mesh;
class DllExport NurbsCurve;
class DllExport Plane;
class DllExport Point3d;
class DllExport PolyCurve;
class DllExport Polyline;
class DllExport PolylineCurve;
class DllExport Surface;
class DllExport Transform;
class DllExport Vector3d;

} // namespace Geometry

class DllExport OcctMath;

} // namespace OcctCommon

using __CArc = const OcctCommon::Geometry::Arc &;
using __CCirc = const OcctCommon::Geometry::Circle &;
using __CLin = const OcctCommon::Geometry::Line &;
using __CPln = const OcctCommon::Geometry::Plane &;
using __CPnt = const OcctCommon::Geometry::Point3d &;
using __CTrsf = const OcctCommon::Geometry::Transform &;
using __CVec = const OcctCommon::Geometry::Vector3d &;
using __Math = OcctCommon::OcctMath;

#endif
