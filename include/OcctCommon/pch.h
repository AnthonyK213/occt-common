#ifndef OCCTCOMMON_GEOMETRY_H
#define OCCTCOMMON_GEOMETRY_H

#include <Adaptor3d_Curve.hxx>
#include <BRepAdaptor_CompCurve.hxx>
#include <Extrema_ExtPC.hxx>
#include <GC_MakeCircle.hxx>
#include <GeomAbs_Shape.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <GeomPlate_BuildAveragePlane.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Line.hxx>
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

class Standard_EXPORT BrepCurveList;

} // namespace Collections

/// @brief
namespace Intersect {

class Standard_EXPORT Intersection;

} // namespace Intersect

class Standard_EXPORT Arc;
class Standard_EXPORT ArcCurve;
class Standard_EXPORT BoundingBox;
class Standard_EXPORT Box;
class Standard_EXPORT Brep;
class Standard_EXPORT Circle;
class Standard_EXPORT Curve;
class Standard_EXPORT Ellipse;
class Standard_EXPORT GeometryBase;
class Standard_EXPORT Interval;
class Standard_EXPORT Line;
class Standard_EXPORT LineCurve;
class Standard_EXPORT Mesh;
class Standard_EXPORT NurbsCurve;
class Standard_EXPORT Plane;
class Standard_EXPORT Point3d;
class Standard_EXPORT PolyCurve;
class Standard_EXPORT Polyline;
class Standard_EXPORT PolylineCurve;
class Standard_EXPORT Quaternion;
class Standard_EXPORT Rectangle3d;
class Standard_EXPORT Surface;
class Standard_EXPORT Transform;
class Standard_EXPORT Vector3d;

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

class Standard_EXPORT OcctMath;

} // namespace OcctCommon

template <typename T> using Arc_ = std::shared_ptr<T>;
template <typename T> using Box_ = std::unique_ptr<T>;
template <typename T> using Vec_ = std::vector<T>;

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
