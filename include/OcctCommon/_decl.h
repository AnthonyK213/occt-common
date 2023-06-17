#ifndef OCCTCOMMON_GEOMETRY_H
#define OCCTCOMMON_GEOMETRY_H

#ifdef __linux__
#define DllExport
#elif _WIN32
#define DllExport __declspec(dllexport)
#endif

#define GP_WRAPPER                                                             \
public:                                                                        \
  using _gpWrapper::_gpWrapper;

#include <Extrema_ExtPC.hxx>
#include <GC_MakeCircle.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <GeomPlate_BuildAveragePlane.hxx>
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
#include <gp_GTrsf.hxx>
#include <gp_Lin.hxx>
#include <gp_Mat.hxx>
#include <gp_Pln.hxx>
#include <gp_Pnt.hxx>
#include <gp_Quaternion.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>
#include <gp_XYZ.hxx>
#include <string>
#include <vector>

/// @brief Contains commonly-used types used in OcctCommon.
namespace OcctCommon {

/// @brief The Geometry namespace contains geometric types used in OcctCommon.
namespace Geometry {

/// @brief
namespace Collections {

class DllExport BrepCurveList;

} // namespace Collections

/// @brief
namespace Intersect {

class DllExport Intersection;

} // namespace Intersect

class DllExport Arc;
class DllExport ArcCurve;
class DllExport BoundingBox;
class DllExport Box;
class DllExport Circle;
class DllExport Curve;
class DllExport GeometryBase;
class DllExport Interval;
class DllExport Line;
class DllExport LineCurve;
class DllExport Mesh;
class DllExport NurbsCurve;
class DllExport Plane;
class DllExport Point3d;
class DllExport PolyCurve;
class DllExport Polyline;
class DllExport PolylineCurve;
class DllExport Quaternion;
class DllExport Surface;
class DllExport Transform;
class DllExport Vector3d;

/// @brief Transparent wrapper for gp_*.
template <typename T> class _gpWrapper {
public:
  _gpWrapper() noexcept {}
  _gpWrapper(const T &t) noexcept : m_data(t) {}
  const T &Data() const { return m_data; }
  // T &DataMut() { return m_data; }

protected:
  T m_data;
};

} // namespace Geometry

class DllExport OcctMath;

} // namespace OcctCommon

using __CArc = const OcctCommon::Geometry::Arc &;
using __CBB = const OcctCommon::Geometry::BoundingBox &;
using __CBox = const OcctCommon::Geometry::Box &;
using __CCirc = const OcctCommon::Geometry::Circle &;
using __CCrv = const OcctCommon::Geometry::Curve &;
using __CIntv = const OcctCommon::Geometry::Interval &;
using __CLin = const OcctCommon::Geometry::Line &;
using __CPln = const OcctCommon::Geometry::Plane &;
using __CPnt = const OcctCommon::Geometry::Point3d &;
using __CTrsf = const OcctCommon::Geometry::Transform &;
using __CVec = const OcctCommon::Geometry::Vector3d &;
using __Math = OcctCommon::OcctMath;

#endif
