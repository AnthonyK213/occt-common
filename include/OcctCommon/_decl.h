#ifndef OCCTCOMMON_GEOMETRY_H
#define OCCTCOMMON_GEOMETRY_H

#include <Extrema_ExtPC.hxx>
#include <GC_MakeCircle.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <GeomPlate_BuildAveragePlane.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Line.hxx>
#include <ShapeExtend_ComplexCurve.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Wire.hxx>
#include <gp.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Ax3.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_GTrsf.hxx>
#include <gp_Lin.hxx>
#include <gp_Mat.hxx>
#include <gp_Pln.hxx>
#include <gp_Pnt.hxx>
#include <gp_Quaternion.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>
#include <gp_XYZ.hxx>
#include <memory>
#include <string>
#include <vector>

#ifndef DllExport
#define DllExport Standard_EXPORT
#endif
#ifndef Box_
#define Box_(T) std::unique_ptr<T>
#endif
#ifndef Rc_
#define Rc_(T) std::shared_ptr<T>
#endif
#ifndef Vec_
#define Vec_(T) std::vector<T>
#endif
#ifndef GP_WRAPPER
#define GP_WRAPPER                                                             \
public:                                                                        \
  using _gpWrapper::_gpWrapper;
#endif
#ifndef NOT_IMPL
#define NOT_IMPL throw std::runtime_error("Not implemented.");
#endif

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
class DllExport Brep;
class DllExport Circle;
class DllExport Curve;
class DllExport Ellipse;
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

enum class BlendContinuity : int32_t {
  Position = 0,
  Tangency = 1,
  Curvature = 2,
};

enum class ConicSectionType : int32_t {
  Unknown = 0,
  Circle = 1,
  Ellipse = 2,
  Hyperbola = 3,
  Parabola = 4,
};

enum class Continuity : int32_t {
  None = 0,
  C0_continuous = 1,
  C1_continuous = 2,
  C2_continuous = 3,
  G1_continuous = 4,
  G2_continuous = 5,
  C0_locus_continuous = 6,
  C1_locus_continuous = 7,
  C2_locus_continuous = 8,
  G1_locus_continuous = 9,
  G2_locus_continuous = 10,
  Cinfinity_continuous = 11,
  Gsmooth_continuous = 12,
};

enum class CurvatureEvaluationSide : int32_t {
  Default = 0,
  Below = -1,
  Above = 1,
};

enum class CurveEnd : int32_t {
  None = 0,
  Start = 1,
  End = 2,
  Both = 3,
};

enum class CurveExtensionStyle : int32_t {
  Line = 0,
  Arc = 1,
  Smooth = 2,
};

enum class CurveKnotStyle : int32_t {
  Uniform = 0,
  Chord = 1,
  ChordSquareRoot = 2,
  UniformPeriodic = 3,
  ChordPeriodic = 4,
  ChordSquareRootPeriodic = 5,
};

enum class CurveOffsetCornerStyle : int32_t {
  None = 0,
  Sharp = 1,
  Round = 2,
  Smooth = 3,
  Chamfer = 4,
};

enum class CurveOffsetEndStyle : int32_t {
  None = 0,
  Flat = 1,
  Round = 2,
};

enum class CurveOrientation : int32_t {
  Undefined = 0,
  Clockwise = -1,
  CounterClockwise = 1,
};

enum class CurveSimplifyOptions : int32_t {
  None = 0x00,
  SplitAtFullyMultipleKnots = 0x01,
  RebuildLInes = 0x02,
  RebuildArcs = 0x04,
  RebuildRationals = 0x08,
  AdjustG1 = 0x10,
  Merge = 0x20,
  All = 0x3F,
};

enum class PointContainment : int32_t {
  Unset,
  Inside,
  Outside,
  Coincident,
};

enum class PreserveEnd : int32_t {
  None = 0,
  Position = 1,
  Tangency = 2,
  Curvature = 3,
};

enum class RegionContainment : int32_t {
  Disjoint = 0,
  MutualIntersection = 1,
  AInsideB = 2,
  BInsideA = 3,
};

enum class SmoothingCoordinateSystem : int32_t {
  World = 0,
  CPlane = 1,
  Object = 2,
};

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

using C_Arc = const OcctCommon::Geometry::Arc &;
using C_BB = const OcctCommon::Geometry::BoundingBox &;
using C_Box = const OcctCommon::Geometry::Box &;
using C_Circ = const OcctCommon::Geometry::Circle &;
using C_Crv = const OcctCommon::Geometry::Curve &;
using C_Intv = const OcctCommon::Geometry::Interval &;
using C_Lin = const OcctCommon::Geometry::Line &;
using C_Pln = const OcctCommon::Geometry::Plane &;
using C_Pnt = const OcctCommon::Geometry::Point3d &;
using C_Trsf = const OcctCommon::Geometry::Transform &;
using C_Vec = const OcctCommon::Geometry::Vector3d &;
using C_Srf = const OcctCommon::Geometry::Surface &;
using C_Brp = const OcctCommon::Geometry::Brep &;
using C_Msh = const OcctCommon::Geometry::Mesh &;
using _Math = OcctCommon::OcctMath;

#endif
