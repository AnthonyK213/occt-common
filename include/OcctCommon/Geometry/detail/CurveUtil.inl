#ifndef OCCTCOMMON_GEOMETRY_CURVEUTIL_INL
#define OCCTCOMMON_GEOMETRY_CURVEUTIL_INL

#include <OcctCommon/Geometry/Curve.h>
#include <OcctCommon/Geometry/PolyCurve.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {
namespace CurveUtil {

template <typename C, typename T>
V_Curve CreateBooleanUnion(C &&curves, double tolerance) {
  NOT_IMPL
}

template <typename C, typename T>
H_Curve CreateControlPointCurve(C &&points, int32_t degree) {
  NOT_IMPL
}

template <typename C, typename T> H_Curve CreateControlPointCurve(C &&points) {
  NOT_IMPL
}

template <typename C, typename T>
H_Curve CreateInterpolatedCurve(C &&points, int32_t degree,
                                CurveKnotStyle knots, C_Vec startTangent,
                                C_Vec endTangent) {
  NOT_IMPL
}

// TODO: degree?
template <typename C, typename T>
H_Curve CreateInterpolatedCurve(C &&points, int32_t degree) {
  size_t count = points.size();
  Handle_TColgp_HArray1OfPnt aPoints = new TColgp_HArray1OfPnt(1, count);
  for (auto it = std::begin(points); it != std::end(points); ++it) {
    aPoints->SetValue(std::distance(std::begin(points), it) + 1, it->Data());
  }
  GeomAPI_Interpolate aInterpolater(aPoints, Standard_False,
                                    Precision::Approximation());
  aInterpolater.Perform();
  if (!aInterpolater.IsDone()) {
    return nullptr;
  }
  return std::make_shared<NurbsCurve>(aInterpolater.Curve());
}

template <typename C, typename T>
V_Curve JoinCurves(C &&curves, double joinTolerance, bool preserveDirection) {
  Handle(TopTools_HSequenceOfShape) edges = new TopTools_HSequenceOfShape();
  for (auto it = std::begin(curves); it != std::end(curves); ++it) {
    if ((*it)->Data()->GetType() == GeomAbs_OtherCurve) {
      Arc_<BRepAdaptor_CompCurve> compCurve =
          reinterpret_cast<const Arc_<BRepAdaptor_CompCurve> &>((*it)->Data());
      TopoDS_Wire wire = compCurve->Wire();
      BRepTools_WireExplorer expl(wire);
      while (expl.More()) {
        TopoDS_Edge edge = TopoDS::Edge(expl.Current());
        edges->Append(edge);
      }
    } else {
      edges->Append(BRepBuilderAPI_MakeEdge((*it)->Data()->BSpline()).Edge());
    }
  }
  Handle(TopTools_HSequenceOfShape) wires = new TopTools_HSequenceOfShape();
  ShapeAnalysis_FreeBounds::ConnectEdgesToWires(edges, joinTolerance, false,
                                                wires);
  Vec_<Arc_<Curve>> result{};
  for (auto it = wires->cbegin(); it != wires->cend(); ++it) {
    TopoDS_Wire wire = TopoDS::Wire(*it);
    result.push_back(std::make_shared<PolyCurve>(wire));
  }
  return result;
}

template <typename C, typename T>
V_Curve JoinCurves(C &&curves, double joinTolerance) {
  return JoinCurves(curves, joinTolerance, false);
}

template <typename C, typename T> V_Curve JoinCurves(C &&curves) {
  return JoinCurves(curves, _Math::ZeroTolerance, false);
}

} // namespace CurveUtil
} // namespace Geometry
} // namespace OcctCommon

#endif
