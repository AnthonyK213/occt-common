#ifndef OCCTCOMMON_GEOMETRY_CURVE_H
#define OCCTCOMMON_GEOMETRY_CURVE_H

#include <OcctCommon/Geometry/GeometryBase.h>
#include <OcctCommon/Geometry/Point3d.h>

namespace OcctCommon {
namespace Geometry {

class Curve : public GeometryBase {
public:
  virtual int32_t Degree() const = 0;

  virtual int32_t Dimension() const;

  virtual Interval Domain() const;

  virtual bool HasBrepForm() const override;

  virtual bool IsClosed() const;

  virtual bool IsDeformable() const override;

  virtual bool IsPeriodic() const;

  virtual bool IsValid() const override;

  virtual uint32_t ObjectType() const override;

  virtual Point3d PointAtEnd() const;

  virtual Point3d PointAtStart() const;

  virtual int32_t SpanCount() const = 0;

  virtual Vector3d TangentAtEnd() const;

  virtual Vector3d TangentAtStart() const;

public:
  virtual bool ChangeClosedCurveSeam(double t);

  virtual bool ChangeDimension(int32_t desireDimension);

  virtual CurveOrientation ClosedCurveOrientation() const;

  virtual CurveOrientation ClosedCurveOrientation(C_Pln plane) const;

  virtual CurveOrientation ClosedCurveOrientation(C_Trsf xform) const;

  virtual CurveOrientation ClosedCurveOrientation(C_Vec upDirection) const;

  virtual bool ClosestPoint(C_Pnt testPoint, double &t,
                            double maximumDistance) const;

  virtual bool ClosestPoint(C_Pnt testPoint, double &t) const;

  virtual bool ClosestPoints(C_Crv otherCurve, Point3d &pointOnThisCurve,
                             Point3d &pointOnOtherCurve) const;

  virtual bool CombineShortSegments(double tolerance);

  virtual PointContainment Contains(C_Pnt testPoint, C_Pln plane,
                                    double tolerance) const;

  virtual Vector3d CurvatureAt(double t) const;

  /// @brief Evaluate the derivatives at the specified curve parameter.
  /// @param t Curve parameter to evaluate.
  /// @param derivativeCount Number of derivatives to evaluate, must be at least
  /// 0.
  /// @param side Side of parameter to evaluate. If the parameter is at a kink,
  /// it makes a big difference whether the evaluation is from below or above.
  /// @return
  Vec_<Vector3d> DerivativeAt(double t, int32_t derivativeCount,
                              CurvatureEvaluationSide side) const;

  /// @brief Evaluate the derivatives at the specified curve parameter.
  /// @param t Curve parameter to evaluate.
  /// @param derivativeCount Number of derivatives to evaluate, must be at least
  /// 0.
  /// @return An array of vectors that represents all the derivatives starting
  /// at zero.
  Vec_<Vector3d> DerivativeAt(double t, int32_t derivativeCount) const;

  virtual Vec_<Point3d> DivideAsContour(C_Pnt contourStart, C_Pnt contourEnd,
                                        double interval) const;

  virtual Vec_<double> DivideByCount(int32_t segmentCount, bool includeEnds,
                                     Vec_<Point3d> &points) const;

  virtual Vec_<double> DivideByCount(int32_t segmentCount,
                                     bool includeEnds) const;

  virtual Vec_<double> DivideByLength(int32_t segmentLength, bool includeEnds,
                                      Vec_<Point3d> &points) const;

  virtual Vec_<double> DivideByLength(int32_t segmentLength, bool includeEnds,
                                      bool reverse,
                                      Vec_<Point3d> &points) const;

  virtual Vec_<double> DivideByLength(int32_t segmentLength, bool includeEnds,
                                      bool reverse) const;

  virtual Vec_<double> DivideByLength(int32_t segmentLength,
                                      bool includeEnds) const;

  virtual Vec_<Point3d> DivideEquidistant(double distance) const;

  virtual GeometryBase *Duplicate() const override;

  virtual Curve *DuplicateCurve() const;

  virtual V_Curve DuplicateSegments() const;

  virtual GeometryBase *DuplicateShallow() const override;

  virtual H_Curve Extend(CurveEnd side, CurveExtensionStyle style,
                         Vec_<GeometryBase *> geometry) const;

  virtual H_Curve Extend(CurveEnd side, CurveExtensionStyle style,
                         C_Pnt endPoint) const;

  virtual H_Curve Extend(CurveEnd side, double length,
                         CurveExtensionStyle style) const;

  virtual H_Curve Extend(C_Intv domain) const;

  virtual H_Curve Extend(double t0, double t1) const;

  virtual H_Curve ExtendByArc(CurveEnd side,
                              Vec_<GeometryBase *> geometry) const;

  virtual H_Curve ExtendByLine(CurveEnd side,
                               Vec_<GeometryBase *> geometry) const;

  // TODO
  virtual H_Curve ExtendOnSurface() const;

  virtual Vec_<double> ExtremeParameters(C_Vec direction) const;

  virtual H_Curve Fair(double distanceTolerance, double angleTolerance,
                       int32_t clampStart, int32_t clampEnd,
                       int32_t iterations) const;

  // TODO
  virtual bool FilletSurfaceToCurve() const;

  virtual bool FilletSurfaceToRail() const;

  virtual bool FindLocalInflection(C_Vec N, C_Intv subDomain, double seed,
                                   double &curveParameter,
                                   double &angleError) const;

  virtual H_Curve Fit(int32_t degree, double fitTolerance,
                      double angleTolerance) const;

  virtual bool FrameAt(double t, Plane &plane) const;

  virtual BoundingBox GetBoundingBox(C_Pln plane, Box &worldBox) const;

  virtual BoundingBox GetBoundingBox(C_Pln plane) const override;

  virtual BoundingBox GetBoundingBox(bool accurate) const override;

  virtual BoundingBox GetBoundingBox(C_Trsf xform) const override;

  virtual ConicSectionType GetConicSectionType() const;

  virtual ConicSectionType GetConicSectionType(Point3d &focus1, Point3d &focus2,
                                               Point3d &center) const;

  virtual bool
  GetCurveParameterFromNurbsFormParameter(double nurbsParameter,
                                          double &curvePrameter) const;

  virtual double GetLength() const;

  virtual double GetLength(C_Intv subdomain) const;

  virtual double GetLength(double factorialTolerance, C_Intv subDomain) const;

  virtual double GetLength(double factorialTolerance) const;

  virtual bool GetLocalPerpPoint(C_Pnt testPoint, double seedParameter,
                                 C_Intv subDomain,
                                 double &curveParameter) const;

  virtual bool GetLocalPerpPoint(C_Pnt testPoint, double seedParameter,
                                 double &curveParameter) const;

  virtual bool GetLocalTangentPoint(C_Pnt testPoint, double seedParameter,
                                    C_Intv subDomain,
                                    double &curveParameter) const;

  virtual bool GetLocalTangentPoint(C_Pnt testPoint, double seedParameter,
                                    double &curveParameter) const;

  virtual bool GetNextDiscontinuity(Continuity continuityType, double t0,
                                    double t1, double &t) const;

  virtual bool GetNextDiscontinuity(Continuity continuityType, double t0,
                                    double t1, double consAngleTolerance,
                                    double curvatureTolerance, double &t) const;

  virtual bool
  GetNurbsFormParameterFromCurveParameter(double curveParameter,
                                          double &nurbsParameter) const;

  virtual Vec_<Plane> GetPerpendicularFrames(Vec_<double> parameters);

  virtual int32_t HasNurbsForm() const;

  virtual Vec_<Point3d> InflectionPoints() const;

  virtual bool IsArc() const;

  virtual bool IsArc(double tolerance) const;

  virtual bool IsCircle() const;

  virtual bool IsCircle(double tolerance) const;

  virtual bool IsClosable(double tolerance, double minimumAbsoluteSize,
                          double minimumRelativeSize) const;

  virtual bool IsClosable(double tolerance) const;

  virtual bool IsContinuous(Continuity continuityType, double t);

  virtual bool IsEllipse() const;

  virtual bool IsEllipse(double tolerance) const;

  virtual bool IsInPlane(C_Pln testPlane, double tolerance) const = 0;

  bool IsInPlane(C_Pln testPlane) const;

  virtual bool IsLinear() const;

  virtual bool IsLinear(double tolerance) const;

  virtual bool IsPlanar() const;

  virtual bool IsPlanar(double tolerance) const = 0;

  virtual bool IsPolyline() const;

  virtual bool IsShort(double tolerance, C_Intv subDomain) const;

  virtual bool IsShort(double tolerance) const;

  virtual bool LengthParameter(double segmentLength, double &t,
                               C_Intv subDomain) const;

  virtual bool LengthParameter(double segmentLength, double &t,
                               double fractionalTolerance,
                               C_Intv subDomain) const;

  virtual bool LengthParameter(double segmentLength, double &t,
                               double fractionalTolerance) const;

  virtual bool LengthParameter(double segmentLength, double &t) const;

  virtual bool LocalClosestPoint(C_Pnt testPoint, double seed, double &t) const;

  virtual bool MakeClosed(double tolerance);

  virtual bool MakeDeformable();

  virtual Vec_<Point3d> MaxCurvaturePoints() const;

  virtual bool NormalizedLengthParameter(double s, double &t,
                                         C_Intv subDomain) const;

  virtual bool NormalizedLengthParameter(double s, double &t,
                                         double fractionalTolerance,
                                         C_Intv subDomain) const;

  virtual bool NormalizedLengthParameter(double s, double &t,
                                         double fractionalTolerance) const;

  virtual bool NormalizedLengthParameter(double s, double &t) const;

  virtual Vec_<double> NormalizedLengthParameters(Vec_<double> s,
                                                  double absoluteTolerance,
                                                  C_Intv subDomain) const;

  virtual Vec_<double> NormalizedLengthParameters(Vec_<double> s,
                                                  double absoluteTolerance,
                                                  double fractionalTolerance,
                                                  C_Intv subDomain) const;

  virtual Vec_<double>
  NormalizedLengthParameters(Vec_<double> s, double absoluteTolerance,
                             double fractionalTolerance) const;

  virtual Vec_<double>
  NormalizedLengthParameters(Vec_<double>, double absoluteTolerance) const;

  virtual V_Curve Offset(C_Pln plane, double distance, double tolerance,
                         CurveOffsetCornerStyle cornerStyle) const;

  virtual V_Curve Offset(C_Pnt directionPoint, C_Vec normal, double distance,
                         double tolerance,
                         CurveOffsetCornerStyle cornerStyle) const;

  virtual V_Curve Offset(C_Pnt directionPoint, C_Vec normal, double distance,
                         double tolerance, double angleTolerance, bool loose,
                         CurveOffsetCornerStyle cornerStyle,
                         CurveOffsetEndStyle endStyle) const;

  virtual H_Curve OffsetNormalToSurface(C_Srf surface, double height) const;

  // TODO
  virtual V_Curve OffsetOnSurface() const;

  virtual bool PerpendicularFrameAt(double t, Plane &plane) const;

  Point3d PointAt(double t) const;

  virtual Point3d PointAtLength(double length) const;

  virtual Point3d PointAtNormalizedLength(double length) const;

  // TODO
  virtual V_Curve PullToBrepFace() const;

  virtual V_PolylineCurve PullToMesh(C_Msh mesh, double tolerance) const;

  virtual H_NurbsCurve Rebuild(int32_t pointCount, int32_t degree,
                               bool preserveTangents) const;

  virtual bool RemoveShortSegments(double tolerance);

  virtual bool Reverse();

  // TODO
  virtual H_Curve RibbonOffset() const;

  virtual bool Rotate(double angleRadians, C_Vec rotaionAxis,
                      C_Pnt rotationCenter) override;

  virtual bool Scale(double scaleFactor) override;

  virtual bool SetEndPoint(C_Pnt point);

  virtual bool SetStartPoint(C_Pnt point);

  virtual bool Simplify(CurveSimplifyOptions options, double distanceTolerance,
                        double angleToleranceRadians);

  virtual bool SimplifyEnd(CurveEnd end, CurveSimplifyOptions options,
                           double distanceTolerance,
                           double angleToleranceRadians);

  virtual H_Curve Smooth(double smoothFactor, bool bXSmooth, bool bYSmooth,
                         bool bZSmooth, bool bFixBoundaries,
                         SmoothingCoordinateSystem coordinateSystem,
                         C_Pln plane) const;

  virtual H_Curve Smooth(double smoothFactor, bool bXSmooth, bool bYSmooth,
                         bool bZSmooth, bool bFixBoundaries,
                         SmoothingCoordinateSystem coordinateSystem) const;

  virtual V_Curve Split(C_Brp cutter, double tolerance,
                        double angleToleranceRadians) const;

  virtual V_Curve Split(Vec_<double> t) const;

  virtual V_Curve Split(C_Srf cutter, double tolerance,
                        double angleToleranceRadians) const;

  virtual V_Curve Split(double t) const;

  virtual Vector3d TangentAt(double t) const;

  virtual H_PolyCurve ToArcsAndLines(double tolerance, double angleTolerance,
                                     double minimumLength,
                                     double maximumLength) const;

  virtual H_NurbsCurve ToNurbsCurve() const;

  virtual H_NurbsCurve ToNurbsCurve(C_Intv subDomain) const;

  virtual H_PolylineCurve ToPolyline(double tolerance, double angleTolerance,
                                     double minimumLength,
                                     double maximumLength) const;

  virtual H_PolylineCurve
  ToPolyline(int32_t mainSegmentCount, int32_t subSegmentCount,
             double maxAngleRadians, double maxChordLengthRatio,
             double maxAspectRatio, double tolerance, double minEdgeLength,
             double maxEdgeLength, bool keepStartPoint,
             C_Intv curveDomain) const;

  virtual H_PolylineCurve
  ToPolyline(int32_t mainSegmentCount, int32_t subSegmentCount,
             double maxAngleRadians, double maxChordLengthRatio,
             double maxAspectRatio, double tolerance, double minEdgeLength,
             double maxEdgeLength, bool keepStartPoint) const;

  virtual double TorsionAt(double t) const;

  virtual bool Transform(C_Trsf xform) override;

  virtual bool Translate(double x, double y, double z) override;

  virtual bool Translate(C_Vec translationVector) override;

  H_Curve Trim(CurveEnd side, double length) const;

  H_Curve Trim(C_Intv domain) const;

  virtual H_Curve Trim(double t0, double t1) const = 0;

  virtual bool TryGetArc(Arc &arc, double tolerance) const;

  virtual bool TryGetArc(Arc &arc) const;

  virtual bool TryGetArc(C_Pln plane, Arc &arc, double tolerance) const;

  virtual bool TryGetArc(C_Pln plane, Arc &arc) const;

  virtual bool TryGetCircle(C_Circ &circle, double tolerance) const;

  virtual bool TryGetCircle(C_Circ &circle) const;

  virtual bool TryGetEllipse(Ellipse &ellipse, double tolerance) const;

  virtual bool TryGetEllipse(Ellipse &ellipse) const;

  virtual bool TryGetEllipse(C_Pln plane, Ellipse &ellipse,
                             double tolerance) const;

  virtual bool TryGetEllipse(C_Pln plane, Ellipse &ellipse) const;

  virtual bool TryGetPlane(Plane &plane, double tolerance) const;

  virtual bool TryGetPlane(Plane &plane) const;

  virtual bool TryGetPolyline(Polyline &polyline,
                              Vec_<double> &parameters) const;

  virtual bool TryGetPolyline(Polyline &polyline) const;

public:
  virtual ~Curve() noexcept;

public:
  Arc_<Adaptor3d_Curve> Data() const;

protected:
  /// @brief Curve data.
  Arc_<Adaptor3d_Curve> m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
