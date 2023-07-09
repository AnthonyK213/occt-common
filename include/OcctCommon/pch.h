#ifndef OCCTCOMMON_GEOMETRY_H
#define OCCTCOMMON_GEOMETRY_H

#include <opencascade/Adaptor3d_Curve.hxx>
#include <opencascade/BRepAdaptor_CompCurve.hxx>
#include <opencascade/CPnts_AbscissaPoint.hxx>
#include <opencascade/Extrema_ExtPC.hxx>
#include <opencascade/GC_MakeCircle.hxx>
#include <opencascade/GeomAPI_Interpolate.hxx>
#include <opencascade/GeomAbs_Shape.hxx>
#include <opencascade/GeomAdaptor_Curve.hxx>
#include <opencascade/GeomPlate_BuildAveragePlane.hxx>
#include <opencascade/Geom_BSplineCurve.hxx>
#include <opencascade/Geom_BoundedCurve.hxx>
#include <opencascade/Geom_Circle.hxx>
#include <opencascade/Geom_Curve.hxx>
#include <opencascade/Geom_Geometry.hxx>
#include <opencascade/Geom_Line.hxx>
#include <opencascade/Geom_OffsetCurve.hxx>
#include <opencascade/Geom_TrimmedCurve.hxx>
#include <opencascade/Precision.hxx>
#include <opencascade/Standard.hxx>
#include <opencascade/Standard_Handle.hxx>
#include <opencascade/Standard_TypeDef.hxx>
#include <opencascade/TColgp_Array1OfPnt.hxx>
#include <opencascade/TopoDS.hxx>
#include <opencascade/TopoDS_Edge.hxx>
#include <opencascade/TopoDS_Shape.hxx>
#include <opencascade/TopoDS_Wire.hxx>
#include <opencascade/gp.hxx>
#include <opencascade/gp_Ax1.hxx>
#include <opencascade/gp_Ax2.hxx>
#include <opencascade/gp_Ax3.hxx>
#include <opencascade/gp_Circ.hxx>
#include <opencascade/gp_Elips.hxx>
#include <opencascade/gp_GTrsf.hxx>
#include <opencascade/gp_Lin.hxx>
#include <opencascade/gp_Mat.hxx>
#include <opencascade/gp_Pln.hxx>
#include <opencascade/gp_Pnt.hxx>
#include <opencascade/gp_Quaternion.hxx>
#include <opencascade/gp_Trsf.hxx>
#include <opencascade/gp_Vec.hxx>
#include <opencascade/gp_XYZ.hxx>

#include <algorithm>
#include <iterator>
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
#ifndef IS_CONTAINER_OF
#define IS_CONTAINER_OF(Container, Class)                                      \
  typename std::enable_if<                                                     \
      std::is_same<                                                            \
          typename std::iterator_traits<typename std::remove_reference<        \
              Container>::type::iterator>::value_type,                         \
          Class>::value,                                                       \
      void>::type
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
  _gpWrapper() : m_data() {}
  _gpWrapper(const T &t) noexcept : m_data(t) {}
  const T &Data() const { return m_data; }

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
using C_NCrv = const OcctCommon::Geometry::NurbsCurve &;
using C_Pln = const OcctCommon::Geometry::Plane &;
using C_Pnt = const OcctCommon::Geometry::Point3d &;
using C_Trsf = const OcctCommon::Geometry::Transform &;
using C_Vec = const OcctCommon::Geometry::Vector3d &;
using C_Srf = const OcctCommon::Geometry::Surface &;
using C_Brp = const OcctCommon::Geometry::Brep &;
using C_Msh = const OcctCommon::Geometry::Mesh &;
using C_Rect = const OcctCommon::Geometry::Rectangle3d &;
using _Math = OcctCommon::OcctMath;

#endif
