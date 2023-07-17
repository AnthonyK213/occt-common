#include <OcctCommon/Geometry/BoundingBox.h>
#include <OcctCommon/Geometry/Box.h>
#include <OcctCommon/Geometry/Curve.h>
#include <OcctCommon/Geometry/Interval.h>
#include <OcctCommon/Geometry/NurbsCurve.h>
#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/PolyCurve.h>
#include <OcctCommon/Geometry/Polyline.h>
#include <OcctCommon/Geometry/PolylineCurve.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

// TODO
int32_t Curve::Dimension() const { return 0; }

Interval Curve::Domain() const {
  return Interval(m_data->FirstParameter(), m_data->LastParameter());
}

// TODO
bool Curve::HasBrepForm() const { return true; }

bool Curve::IsClosed() const { return m_data->IsClosed(); }

// TODO
bool Curve::IsDeformable() const { return true; }

bool Curve::IsPeriodic() const { return m_data->IsPeriodic(); }

// TODO
bool Curve::IsValid() const { return true; }

// TODO
uint32_t Curve::ObjectType() const { return 0; }

Point3d Curve::PointAtEnd() const { return PointAt(m_data->LastParameter()); }

Point3d Curve::PointAtStart() const {
  return PointAt(m_data->FirstParameter());
}

Vector3d Curve::TangentAtEnd() const {
  return TangentAt(m_data->LastParameter());
}

Vector3d Curve::TangentAtStart() const {
  return TangentAt(m_data->FirstParameter());
}

bool Curve::ChangeClosedCurveSeam(double t) { NOT_IMPL }

bool Curve::ChangeDimension(int32_t desireDimension){NOT_IMPL}

CurveOrientation Curve::ClosedCurveOrientation() const {NOT_IMPL}

CurveOrientation Curve::ClosedCurveOrientation(C_Pln plane) const {NOT_IMPL}

CurveOrientation Curve::ClosedCurveOrientation(C_Trsf xform) const {NOT_IMPL}

CurveOrientation Curve::ClosedCurveOrientation(C_Vec upDirection) const {
  NOT_IMPL
}

bool Curve::ClosestPoint(C_Pnt testPoint, double &t,
                         double maximumDistance) const {
  Extrema_ExtPC extrema(testPoint.Data(), *m_data);
  if (!extrema.IsDone()) {
    return false;
  }
  int count = extrema.NbExt();
  for (int i = 1; i <= count; ++i) {
    if (extrema.IsMin(i)) {
      if (maximumDistance >= 0.0 &&
          extrema.SquareDistance(i) > maximumDistance * maximumDistance) {
        continue;
      }
      t = extrema.Point(i).Parameter();
      return true;
    }
  }
  return false;
}

bool Curve::ClosestPoint(C_Pnt testPoint, double &t) const {
  return ClosestPoint(testPoint, t, -1.0);
}

bool Curve::ClosestPoints(C_Crv otherCurve, Point3d &pointOnThisCurve,
                          Point3d &pointOnOtherCurve) const {
  NOT_IMPL
}

bool Curve::CombineShortSegments(double tolerance){NOT_IMPL}

PointContainment Curve::Contains(C_Pnt testPoint, C_Pln plane,
                                 double tolerance) const {NOT_IMPL}

Vector3d Curve::CurvatureAt(double t) const {NOT_IMPL}

// TODO: Curvature evaluation side.
Vec_<Vector3d> Curve::DerivativeAt(double t, int32_t derivativeCount,
                                   CurvatureEvaluationSide side) const {
  return DerivativeAt(t, derivativeCount);
}

// NOTE: Just `derivative` at t and `derivativeCount`.
Vec_<Vector3d> Curve::DerivativeAt(double t, int32_t derivativeCount) const {
  if (derivativeCount < 0) {
    return Vec_<Vector3d>{};
  }
  if (derivativeCount == 0) {
    gp_Pnt p;
    m_data->D0(t, p);
    return Vec_<Vector3d>{Vector3d(p)};
  }
  gp_Vec d = m_data->DN(t, derivativeCount);
  return Vec_<Vector3d>{Vector3d(d)};
}

Vec_<Point3d> Curve::DivideAsContour(C_Pnt contourStart, C_Pnt contourEnd,
                                     double interval) const {NOT_IMPL}

Vec_<double> Curve::DivideByCount(int32_t segmentCount, bool includeEnds,
                                  Vec_<Point3d> &points) const {NOT_IMPL}

Vec_<double> Curve::DivideByCount(int32_t segmentCount,
                                  bool includeEnds) const {NOT_IMPL}

Vec_<double> Curve::DivideByLength(int32_t segmentLength, bool includeEnds,
                                   Vec_<Point3d> &points) const {NOT_IMPL}

Vec_<double> Curve::DivideByLength(int32_t segmentLength, bool includeEnds,
                                   bool reverse,
                                   Vec_<Point3d> &points) const {NOT_IMPL}

Vec_<double> Curve::DivideByLength(int32_t segmentLength, bool includeEnds,
                                   bool reverse) const {NOT_IMPL}

Vec_<double> Curve::DivideByLength(int32_t segmentLength,
                                   bool includeEnds) const {NOT_IMPL}

Vec_<Point3d> Curve::DivideEquidistant(double distance) const {NOT_IMPL}

// TODO
GeometryBase *Curve::Duplicate() const {
  return nullptr;
}

Curve *Curve::DuplicateCurve() const {NOT_IMPL}

Vec_<Arc_<Curve>> Curve::DuplicateSegments() const {NOT_IMPL}

// TODO
GeometryBase *Curve::DuplicateShallow() const {
  return nullptr;
}

Curve *Curve::Extend(CurveEnd side, CurveExtensionStyle style,
                     Vec_<GeometryBase *> geometry) const {NOT_IMPL}

Curve *Curve::Extend(CurveEnd side, CurveExtensionStyle style,
                     C_Pnt endPoint) const {NOT_IMPL}

Curve *Curve::Extend(CurveEnd side, double length,
                     CurveExtensionStyle style) const {NOT_IMPL}

Curve *Curve::Extend(C_Intv domain) const {NOT_IMPL}

Curve *Curve::Extend(double t0, double t1) const {NOT_IMPL}

Curve *Curve::ExtendByArc(CurveEnd side,
                          Vec_<GeometryBase *> geometry) const {NOT_IMPL}

Curve *Curve::ExtendByLine(CurveEnd side,
                           Vec_<GeometryBase *> geometry) const {NOT_IMPL}

// TODO
Curve *Curve::ExtendOnSurface() const {NOT_IMPL}

Vec_<double> Curve::ExtremeParameters(C_Vec direction) const {NOT_IMPL}

Curve *Curve::Fair(double distanceTolerance, double angleTolerance,
                   int32_t clampStart, int32_t clampEnd,
                   int32_t iterations) const {
  NOT_IMPL
}

// TODO
bool Curve::FilletSurfaceToCurve() const { NOT_IMPL }

bool Curve::FilletSurfaceToRail() const { NOT_IMPL }

bool Curve::FindLocalInflection(C_Vec N, C_Intv subDomain, double seed,
                                double &curveParameter,
                                double &angleError) const {NOT_IMPL}

Curve *Curve::Fit(int32_t degree, double fitTolerance,
                  double angleTolerance) const {
  NOT_IMPL
}

bool Curve::FrameAt(double t, Plane &plane) const {NOT_IMPL}

BoundingBox Curve::GetBoundingBox(C_Pln plane, Box &worldBox) const {NOT_IMPL}

BoundingBox Curve::GetBoundingBox(C_Pln plane) const {NOT_IMPL}

BoundingBox Curve::GetBoundingBox(bool accurate) const {NOT_IMPL}

BoundingBox Curve::GetBoundingBox(C_Trsf xform) const {NOT_IMPL}

ConicSectionType Curve::GetConicSectionType() const {NOT_IMPL}

ConicSectionType Curve::GetConicSectionType(Point3d &focus1, Point3d &focus2,
                                            Point3d &center) const {
  NOT_IMPL
}

bool Curve::GetCurveParameterFromNurbsFormParameter(
    double nurbsParameter, double &curvePrameter) const {
  NOT_IMPL
}

double Curve::GetLength() const { return GetLength(Domain()); }

double Curve::GetLength(C_Intv subdomain) const {
  return CPnts_AbscissaPoint::Length(*m_data, subdomain.T0(), subdomain.T1());
}

// TODO: `factorialTolerance`?
double Curve::GetLength(double factorialTolerance, C_Intv subDomain) const {
  return GetLength(subDomain);
}

// TODO: `factorialTolerance`?
double Curve::GetLength(double factorialTolerance) const { return GetLength(); }

bool Curve::GetLocalPerpPoint(C_Pnt testPoint, double seedParameter,
                              C_Intv subDomain, double &curveParameter) const {
  NOT_IMPL
}

bool Curve::GetLocalPerpPoint(C_Pnt testPoint, double seedParameter,
                              double &curveParameter) const {
  NOT_IMPL
}

bool Curve::GetLocalTangentPoint(C_Pnt testPoint, double seedParameter,
                                 C_Intv subDomain,
                                 double &curveParameter) const {
  NOT_IMPL
}

bool Curve::GetLocalTangentPoint(C_Pnt testPoint, double seedParameter,
                                 double &curveParameter) const {
  NOT_IMPL
}

bool Curve::GetNextDiscontinuity(Continuity continuityType, double t0,
                                 double t1, double &t) const {
  NOT_IMPL
}

bool Curve::GetNextDiscontinuity(Continuity continuityType, double t0,
                                 double t1, double consAngleTolerance,
                                 double curvatureTolerance, double &t) const {
  NOT_IMPL
}

bool Curve::GetNurbsFormParameterFromCurveParameter(
    double curveParameter, double &nurbsParameter) const {NOT_IMPL}

Vec_<Plane> Curve::GetPerpendicularFrames(Vec_<double> parameters){NOT_IMPL}

int32_t Curve::HasNurbsForm() const {NOT_IMPL}

Vec_<Point3d> Curve::InflectionPoints() const {
  NOT_IMPL
}

bool Curve::IsArc() const { NOT_IMPL }

bool Curve::IsArc(double tolerance) const { NOT_IMPL }

bool Curve::IsCircle() const { NOT_IMPL }

bool Curve::IsCircle(double tolerance) const { NOT_IMPL }

bool Curve::IsClosable(double tolerance, double minimumAbsoluteSize,
                       double minimumRelativeSize) const {
  NOT_IMPL
}

bool Curve::IsClosable(double tolerance) const { NOT_IMPL }

bool Curve::IsContinuous(Continuity continuityType, double t) { NOT_IMPL }

bool Curve::IsEllipse() const { NOT_IMPL }

bool Curve::IsEllipse(double tolerance) const { NOT_IMPL }

bool Curve::IsInPlane(C_Pln testPlane) const {
  return IsInPlane(testPlane, _Math::ZeroTolerance);
}

bool Curve::IsLinear() const { NOT_IMPL }

bool Curve::IsLinear(double tolerance) const { NOT_IMPL }

bool Curve::IsPlanar() const { return IsPlanar(_Math::ZeroTolerance); }

bool Curve::IsPolyline() const { NOT_IMPL }

bool Curve::IsShort(double tolerance, C_Intv subDomain) const { NOT_IMPL }

bool Curve::IsShort(double tolerance) const { NOT_IMPL }

bool Curve::LengthParameter(double segmentLength, double &t,
                            C_Intv subDomain) const {
  return LengthParameter(segmentLength, t, 1e-8);
}

bool Curve::LengthParameter(double segmentLength, double &t,
                            double fractionalTolerance,
                            C_Intv subDomain) const {
  double length = GetLength(fractionalTolerance, subDomain);
  if (segmentLength > length || segmentLength < 0.0 || length == 0.0) {
    return false;
  }
  CPnts_AbscissaPoint pnt(*m_data, segmentLength, subDomain.T0(),
                          fractionalTolerance);
  if (!pnt.IsDone()) {
    return false;
  }
  t = pnt.Parameter();
  return true;
}

bool Curve::LengthParameter(double segmentLength, double &t,
                            double fractionalTolerance) const {
  double length = GetLength(fractionalTolerance);
  if (segmentLength > length || segmentLength < 0.0 || length == 0.0) {
    return false;
  }
  CPnts_AbscissaPoint pnt(*m_data, segmentLength, m_data->FirstParameter(),
                          fractionalTolerance);
  if (!pnt.IsDone()) {
    return false;
  }
  t = pnt.Parameter();
  return true;
}

bool Curve::LengthParameter(double segmentLength, double &t) const {
  return LengthParameter(segmentLength, t, 1e-8);
}

bool Curve::LocalClosestPoint(C_Pnt testPoint, double seed, double &t) const {
  NOT_IMPL
}

bool Curve::MakeClosed(double tolerance) { NOT_IMPL }

bool Curve::MakeDeformable(){NOT_IMPL}

Vec_<Point3d> Curve::MaxCurvaturePoints() const {
  NOT_IMPL
}

bool Curve::NormalizedLengthParameter(double s, double &t,
                                      C_Intv subDomain) const {
  return NormalizedLengthParameter(s, t, 1e-8, subDomain);
}

// TODO: `fractionalTolerance`?
bool Curve::NormalizedLengthParameter(double s, double &t,
                                      double fractionalTolerance,
                                      C_Intv subDomain) const {
  double segmentLength = GetLength(fractionalTolerance, subDomain) * s;
  return LengthParameter(segmentLength, t, fractionalTolerance, subDomain);
}

// TODO: `fractionalTolerance`?
bool Curve::NormalizedLengthParameter(double s, double &t,
                                      double fractionalTolerance) const {
  double segmentLength = GetLength(fractionalTolerance) * s;
  return LengthParameter(segmentLength, t, fractionalTolerance);
}

bool Curve::NormalizedLengthParameter(double s, double &t) const {
  return NormalizedLengthParameter(s, t, 1e-8);
}

Vec_<double>
Curve::NormalizedLengthParameters(Vec_<double> s, double absoluteTolerance,
                                  C_Intv subDomain) const {NOT_IMPL}

Vec_<double> Curve::NormalizedLengthParameters(
    Vec_<double> s, double absoluteTolerance, double fractionalTolerance,
    C_Intv subDomain) const {NOT_IMPL}

Vec_<double> Curve::NormalizedLengthParameters(
    Vec_<double> s, double absoluteTolerance,
    double fractionalTolerance) const {NOT_IMPL}

Vec_<double> Curve::NormalizedLengthParameters(Vec_<double>,
                                               double absoluteTolerance) const {
    NOT_IMPL}

Vec_<Arc_<Curve>> Curve::Offset(C_Pln plane, double distance, double tolerance,
                                CurveOffsetCornerStyle cornerStyle) const {
    NOT_IMPL}

Vec_<Arc_<Curve>> Curve::Offset(C_Pnt directionPoint, C_Vec normal,
                                double distance, double tolerance,
                                CurveOffsetCornerStyle cornerStyle) const {
    NOT_IMPL}

Vec_<Arc_<Curve>> Curve::Offset(C_Pnt directionPoint, C_Vec normal,
                                double distance, double tolerance,
                                double angleTolerance, bool loose,
                                CurveOffsetCornerStyle cornerStyle,
                                CurveOffsetEndStyle endStyle) const {NOT_IMPL}

Curve *Curve::OffsetNormalToSurface(C_Srf surface,
                                    double height) const {NOT_IMPL}

// TODO
Vec_<Arc_<Curve>> Curve::OffsetOnSurface() const {
  NOT_IMPL
}

bool Curve::PerpendicularFrameAt(double t, Plane &plane) const {NOT_IMPL}

Point3d Curve::PointAt(double t) const {
  return Point3d{m_data->Value(t)};
}

Point3d Curve::PointAtLength(double length) const {NOT_IMPL}

Point3d Curve::PointAtNormalizedLength(double length) const {NOT_IMPL}

// TODO
Vec_<Arc_<Curve>> Curve::PullToBrepFace() const {NOT_IMPL}

Vec_<PolylineCurve> Curve::PullToMesh(C_Msh mesh,
                                      double tolerance) const {NOT_IMPL}

NurbsCurve *Curve::Rebuild(int32_t pointCount, int32_t degree,
                           bool preserveTangents) const {
  NOT_IMPL
}

bool Curve::RemoveShortSegments(double tolerance) { NOT_IMPL }

bool Curve::Reverse(){NOT_IMPL}

// TODO
Curve *Curve::RibbonOffset() const {
  NOT_IMPL
}

bool Curve::Rotate(double angleRadians, C_Vec rotaionAxis,
                   C_Pnt rotationCenter) {
  NOT_IMPL
}

bool Curve::Scale(double scaleFactor) { NOT_IMPL }

bool Curve::SetEndPoint(C_Pnt point) { NOT_IMPL }

bool Curve::SetStartPoint(C_Pnt point) { NOT_IMPL }

bool Curve::Simplify(CurveSimplifyOptions options, double distanceTolerance,
                     double angleToleranceRadians) {
  NOT_IMPL
}

bool Curve::SimplifyEnd(CurveEnd end, CurveSimplifyOptions options,
                        double distanceTolerance,
                        double angleToleranceRadians){NOT_IMPL}

Curve *Curve::Smooth(double smoothFactor, bool bXSmooth, bool bYSmooth,
                     bool bZSmooth, bool bFixBoundaries,
                     SmoothingCoordinateSystem coordinateSystem,
                     C_Pln plane) const {NOT_IMPL}

Curve *Curve::Smooth(double smoothFactor, bool bXSmooth, bool bYSmooth,
                     bool bZSmooth, bool bFixBoundaries,
                     SmoothingCoordinateSystem coordinateSystem) const {
    NOT_IMPL}

Vec_<Arc_<Curve>> Curve::Split(C_Brp cutter, double tolerance,
                               double angleToleranceRadians) const {NOT_IMPL}

Vec_<Arc_<Curve>> Curve::Split(Vec_<double> t) const {NOT_IMPL}

Vec_<Arc_<Curve>> Curve::Split(C_Srf cutter, double tolerance,
                               double angleToleranceRadians) const {NOT_IMPL}

Vec_<Arc_<Curve>> Curve::Split(double t) const {NOT_IMPL}

Vector3d Curve::TangentAt(double t) const {
  gp_Vec v1 = m_data->DN(t, 1);
  return Vector3d{v1};
}

PolyCurve *Curve::ToArcsAndLines(double tolerance, double angleTolerance,
                                 double minimumLength,
                                 double maximumLength) const {NOT_IMPL}

NurbsCurve *Curve::ToNurbsCurve() const {NOT_IMPL}

NurbsCurve *Curve::ToNurbsCurve(C_Intv subDomain) const {NOT_IMPL}

PolylineCurve *Curve::ToPolyline(double tolerance, double angleTolerance,
                                 double minimumLength,
                                 double maximumLength) const {NOT_IMPL}

PolylineCurve *Curve::ToPolyline(
    int32_t mainSegmentCount, int32_t subSegmentCount, double maxAngleRadians,
    double maxChordLengthRatio, double maxAspectRatio, double tolerance,
    double minEdgeLength, double maxEdgeLength, bool keepStartPoint,
    C_Intv curveDomain) const {NOT_IMPL}

PolylineCurve *Curve::ToPolyline(
    int32_t mainSegmentCount, int32_t subSegmentCount, double maxAngleRadians,
    double maxChordLengthRatio, double maxAspectRatio, double tolerance,
    double minEdgeLength, double maxEdgeLength, bool keepStartPoint) const {
  NOT_IMPL
}

double Curve::TorsionAt(double t) const { NOT_IMPL }

bool Curve::Transform(C_Trsf xform) { NOT_IMPL }

bool Curve::Translate(double x, double y, double z) { NOT_IMPL }

bool Curve::Translate(C_Vec translationVector){NOT_IMPL}

Curve *Curve::Trim(CurveEnd side, double length) const {
  if (length <= 0) {
    throw std::runtime_error("length must be > 0");
  }
  double curveLength = GetLength();
  if (IsClosed() || length >= curveLength) {
    return nullptr;
  }
  // NOTE: WTF? Rhinocommon is wrong?
  if (side == CurveEnd::Both && 2.0 * length >= curveLength) {
    return nullptr;
  }
  double t0 = m_data->FirstParameter();
  double t1 = m_data->LastParameter();
  if (side == CurveEnd::Start || side == CurveEnd::Both) {
    double s0 = length / curveLength;
    NormalizedLengthParameter(s0, t0);
  }
  if (side == CurveEnd::End || side == CurveEnd::Both) {
    double s1 = (curveLength - length) / curveLength;
    NormalizedLengthParameter(s1, t1);
  }
  return Trim(t0, t1);
}

Curve *Curve::Trim(C_Intv domain) const {
  return Trim(domain.T0(), domain.T1());
}

bool Curve::TryGetArc(Arc &arc, double tolerance) const { NOT_IMPL }

bool Curve::TryGetArc(Arc &arc) const { NOT_IMPL }

bool Curve::TryGetArc(C_Pln plane, Arc &arc, double tolerance) const {
  NOT_IMPL
}

bool Curve::TryGetArc(C_Pln plane, Arc &arc) const { NOT_IMPL }

bool Curve::TryGetCircle(C_Circ &circle, double tolerance) const { NOT_IMPL }

bool Curve::TryGetCircle(C_Circ &circle) const { NOT_IMPL }

bool Curve::TryGetEllipse(Ellipse &ellipse, double tolerance) const { NOT_IMPL }

bool Curve::TryGetEllipse(Ellipse &ellipse) const { NOT_IMPL }

bool Curve::TryGetEllipse(C_Pln plane, Ellipse &ellipse,
                          double tolerance) const {
  NOT_IMPL
}

bool Curve::TryGetEllipse(C_Pln plane, Ellipse &ellipse) const { NOT_IMPL }

bool Curve::TryGetPlane(Plane &plane, double tolerance) const { NOT_IMPL }

bool Curve::TryGetPlane(Plane &plane) const { NOT_IMPL }

bool Curve::TryGetPolyline(Polyline &polyline, Vec_<double> &parameters) const {
  NOT_IMPL
}

bool Curve::TryGetPolyline(Polyline &polyline) const {NOT_IMPL}

Curve::~Curve() noexcept {}

const Arc_<Adaptor3d_Curve>& Curve::Data() const { return m_data; }

} // namespace Geometry
} // namespace OcctCommon
