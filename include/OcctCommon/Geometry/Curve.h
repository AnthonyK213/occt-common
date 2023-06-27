#ifndef OCCTCOMMON_GEOMETRY_CURVE_H
#define OCCTCOMMON_GEOMETRY_CURVE_H

#include <OcctCommon/Geometry/GeometryBase.h>

namespace OcctCommon {
namespace Geometry {

class Curve : public GeometryBase {
public:
  virtual int32_t Degree() const;

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

  virtual int32_t SpanCount() const;

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

  static Curve CreateArcBlend(C_Pnt startPt, C_Vec startDir, C_Pnt endPt,
                              C_Vec endDir, double controlPointLengthRatio);

  static Curve CreateArcLineArcBlend(C_Pnt startPt, C_Vec startDir, C_Pnt endPt,
                                     C_Vec endDir, double radius);

  static Curve CreateBlendCurve(C_Crv curve0, double t0, bool reverse0,
                                BlendContinuity continuity0, C_Crv curve1,
                                double t1, bool reverse1,
                                BlendContinuity continuity1);

  static Curve CreateBlendCurve(C_Crv curveA, C_Crv curveB,
                                BlendContinuity continuity, double bulgeA,
                                double bulgeB);

  static Curve CreateBlendCurve(C_Crv curveA, C_Crv curveB,
                                BlendContinuity continuity);

  static Vec_<Curve> CreateBooleanDifference(C_Crv curveA, C_Crv curveB,
                                             double tolerance);

  static Vec_<Curve> CreateBooleanIntersection(C_Crv curveA, C_Crv curveB,
                                               double tolerance);

  static void CreateBooleanRegions();

  template <typename T>
  static Vec_<Curve> CreateBooleanUnion(T _first, T _last, double tolerance);

  template <typename T>
  static Curve CreateControlPointCurve(T _first, T _last, int32_t degree);

  template <typename T> static Curve CreateControlPointCurve(T _first, T _last);

  static Curve CreateCurve2View(C_Crv curveA, C_Crv curveB, C_Vec vectorA,
                                C_Vec vectorB, double tolerance,
                                double angleTolerance);

  static Arc CreateFillet(C_Crv curve0, C_Crv curve1, double radius,
                          double t0Base, double t1Base);

  static Curve CreateFilletCornersCurve(C_Crv curve, double radius,
                                        double tolerance,
                                        double angleTolerance);

  static Vec_<Curve> CreateFilletCurves(C_Crv curve0, C_Pnt point0,
                                        C_Crv curve1, C_Pnt point1,
                                        double radius, bool join, bool trim,
                                        bool arcExtension, double tolerance,
                                        double angleTolerance);

  template <typename T>
  static Curve CreateInterpolatedCurve(T _first, T _last, int32_t degree,
                                       CurveKnotStyle knots, C_Vec startTangent,
                                       C_Vec endTangent);

  template <typename T>
  static Curve CreateInterpolatedCurve(T _first, T _last, int32_t degree);

  static Vec_<Curve> CreateMatchCurve(C_Crv curve0, bool reverse0,
                                      BlendContinuity continuity, C_Crv curve1,
                                      bool reverse1, PreserveEnd preserve,
                                      bool average);

  static Curve CreateMeanCurve(C_Crv curveA, C_Crv curveB,
                               double angleToleranceRadians);

  static Curve CreateMeanCurve(C_Crv curveA, C_Crv curveB);

  static Curve CreatePeriodicCurve(C_Crv curve, bool smooth);

  static Curve CreatePeriodicCurve(C_Crv curve);

  static Curve CreateSoftEditCurve(C_Crv curve, double t, C_Vec delta,
                                   double length, bool fixEnds);

  static Vec_<Curve> CreateTextOutlines();

  static Vec_<Curve> CreateTweenCurves(C_Crv curve0, C_Crv curve1,
                                       int32_t numCurves, double tolerance);

  static Vec_<Curve> CreateTweenCurvesWithMatching(C_Crv curve0, C_Crv curve1,
                                                   int32_t numCurves,
                                                   double tolerance);

  static Vec_<Curve> CreateTweenCurvesWithSampling(C_Crv curve0, C_Crv curve1,
                                                   int32_t numCurves,
                                                   int32_t numSamples,
                                                   double tolerance);

  virtual Vector3d CurvatureAt(double t) const;

  virtual Vec_<Vector3d> DerivativeAt(double t, uint32_t derivativeCount,
                                      CurvatureEvaluationSide side) const;

  virtual Vec_<Vector3d> DerivativeAt(double t, uint32_t derivativeCount) const;

  virtual Vec_<Point3d> DivedeAsContour(C_Pnt contourStart, C_Pnt contourEnd,
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

  static bool DoDirectionsMatch(C_Crv curveA, C_Crv curveB);

  virtual GeometryBase *Duplicate() const override;

  virtual Curve DuplicateCurve() const;

  virtual Vec_<Curve> DuplicateSegments() const;

  virtual GeometryBase *DuplicateShallow() const override;

  virtual Curve Extend(CurveEnd side, CurveExtensionStyle style,
                       Vec_<GeometryBase> geometry) const;

  virtual Curve Extend(CurveEnd side, CurveExtensionStyle style,
                       C_Pnt endPoint) const;

  virtual Curve Extend(CurveEnd side, double length,
                       CurveExtensionStyle style) const;

  virtual Curve Extend(C_Intv domain) const;

  virtual Curve Extend(double t0, double t1) const;

  virtual Curve ExtendByArc(CurveEnd side, Vec_<GeometryBase> geometry) const;

  virtual Curve ExtendByLine(CurveEnd side, Vec_<GeometryBase> geometry) const;

  // TODO
  virtual Curve ExtendOnSurface() const;

  virtual Vec_<double> ExtremeParameters(C_Vec direction) const;

  virtual Curve Fair(double distanceTolerance, double angleTolerance,
                     int32_t clampStart, int32_t clampEnd,
                     int32_t iterations) const;

  // TODO
  virtual bool FilletSurfaceToCurve() const;

  virtual bool FilletSurfaceToRail() const;

  virtual bool FindLocalInflection(C_Vec N, C_Intv subDomain, double seed,
                                   double &curveParameter,
                                   double &angleError) const;

  virtual Curve Fit(int32_t degree, double fitTolerance,
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

  static bool GetDistancesBetweenCurves(C_Crv curveA, C_Crv curveB,
                                        double tolerance, double &maxDistance,
                                        double &maxDistanceParameterA,
                                        double &maxDistanceParameterB,
                                        double &minDistance,
                                        double &minDistanceParameterA,
                                        double &minDistanceParameterB);

  static bool GetFilletPoints(C_Crv curve0, C_Crv curve1, double radius,
                              double t0Base, double t1Base, double &t0,
                              double &t1, Plane &filletPlane);

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

  virtual bool IsInPlane(C_Pln testPlane, double tolerance) const;

  virtual bool IsInPlane(C_Pln testPlane) const;

  virtual bool IsLinear() const;

  virtual bool IsLinear(double tolerance) const;

  virtual bool IsPlanar() const;

  virtual bool IsPlanar(double tolerance) const;

  virtual bool IsPolyline() const;

  virtual bool IsShort(double tolerance, C_Intv subDomain) const;

  virtual bool IsShort(double tolerance) const;

  template <typename T>
  static Vec_<Curve> JoinCurves(T _fist, T _last, double joinTolerance,
                                bool preserveDirection);

  template <typename T>
  static Vec_<Curve> JoinCurves(T _fist, T _last, double joinTolerance);

  template <typename T> static Vec_<Curve> JoinCurves(T _fist, T _last);

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

  static bool MakeEndsMeet(Curve &curveA, bool adjustStartCurveA, Curve &curveB,
                           bool adjustStartCurveB);

  virtual Vec_<Point3d> MaxCurvaturePoints() const;

  virtual bool NormalizedLengthParameter(double s, double &t,
                                         C_Intv subDomain) const;

  virtual bool NormalizedLengthParameter(double s, double &t,
                                         double fractionalTolerance,
                                         C_Intv subDomain) const;

  virtual bool NormalizedLengthParameter(double s, double &t,
                                         double fractionalTolerance) const;

  virtual bool NormalizedLengthParameter(Vec_<double> s, double &t) const;

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

  virtual Vec_<Curve> Offset(C_Pln plane, double distance, double tolerance,
                             CurveOffsetCornerStyle cornerStyle) const;

  virtual Vec_<Curve> Offset(C_Pnt directionPoint, C_Vec normal,
                             double distance, double tolerance,
                             CurveOffsetCornerStyle cornerStyle) const;

  virtual Vec_<Curve> Offset(C_Pnt directionPoint, C_Vec normal,
                             double distance, double tolerance,
                             double angleTolerance, bool loose,
                             CurveOffsetCornerStyle cornerStyle,
                             CurveOffsetEndStyle endStyle) const;

  virtual Curve OffsetNormalToSurface(C_Srf surface, double height) const;

  // TODO
  virtual Vec_<Curve> OffsetOnSurface() const;

  virtual bool PerpendicularFrameAt(double t, Plane &plane) const;

  static RegionContainment PlanarClosedCurveRelationship(C_Crv curveA,
                                                         C_Crv curveB,
                                                         C_Pln testPlane,
                                                         double tolerance);

  static bool PlanarCurveCollision(C_Crv curveA, C_Crv curveB, C_Pln testPlane,
                                   double tolerance);

  virtual Point3d PointAt(double t) const;

  virtual Point3d PointAtLength(double length) const;

  virtual Point3d PointAtNormalizedLength(double length) const;

  static Vec_<Curve> ProjectToBrep(C_Crv curve, C_Brp brep, C_Vec direction,
                                   double tolerance);

  template <typename T>
  static Vec_<Curve> ProjectToBrep(C_Crv curve, T _first, T _last,
                                   C_Vec direction, double tolerance,
                                   Vec_<int32_t> &brepIndices);

  template <typename T>
  static Vec_<Curve> ProjectToBrep(C_Crv curve, T _first, T _last,
                                   C_Vec direction, double tolerance);

  template <typename T1, typename T2>
  static Vec_<Curve> ProjectToBrep(T1 _first1, T1 _last1, T2 _first2, T2 _last2,
                                   C_Vec direction, double tolerance,
                                   Vec_<int32_t> &curveIndices,
                                   Vec_<int32_t> brepIndices);

  template <typename T1, typename T2>
  static Vec_<Curve> ProjectToBrep(T1 _first1, T1 _last1, T2 _first2, T2 _last2,
                                   C_Vec direction, double tolerance);

  template <typename T>
  static Vec_<Curve> ProjectToMesh(C_Crv curve, T _first, T _last,
                                   C_Vec direction, double tolerance);

  static Vec_<Curve> ProjectToMesh(C_Crv curve, C_Msh mesh, C_Vec direction,
                                   double tolerance);

  template <typename T1, typename T2>
  static Vec_<Curve> ProjectToMesh(C_Crv curve, T1 _first1, T1 _last1,
                                   T2 _first2, T2 _last2, C_Vec direction,
                                   double tolerance);

  static Curve ProjectToPlane(C_Crv cruve, C_Pln plane);

  // TODO
  virtual Vec_<Curve> PullToBrepFace() const;

  virtual Vec_<PolylineCurve> PullToMesh(C_Msh mesh, double tolerance) const;

  virtual NurbsCurve Rebuild(int32_t pointCount, int32_t degree,
                             bool preserveTangents) const;

  virtual bool RemoveShortSegments(double tolerance);

  virtual bool Reverse();

  // TODO
  virtual Curve RibbonOffset() const;

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

  virtual Curve Smooth(double smoothFactor, bool bXSmooth, bool bYSmooth,
                       bool bZSmooth, bool bFixBoundaries,
                       SmoothingCoordinateSystem coordinateSystem,
                       C_Pln plane) const;

  virtual Curve Smooth(double smoothFactor, bool bXSmooth, bool bYSmooth,
                       bool bZSmooth, bool bFixBoundaries,
                       SmoothingCoordinateSystem coordinateSystem) const;

  virtual Vec_<Curve> Split(C_Brp cutter, double tolerance,
                            double angleToleranceRadians) const;

  virtual Vec_<Curve> Split(Vec_<double> t) const;

  virtual Vec_<Curve> Split(C_Srf cutter, double tolerance,
                            double angleToleranceRadians) const;

  virtual Vec_<Curve> Split(double t) const;

  virtual Vector3d TangentAt(double t) const;

  virtual PolyCurve ToArcsAndLines(double tolerance, double angleTolerance,
                                   double minimumLength,
                                   double maximumLength) const;

  virtual NurbsCurve ToNurbsCurve() const;

  virtual NurbsCurve ToNurbsCurve(C_Intv subDomain) const;

  virtual PolylineCurve ToPolyline(double tolerance, double angleTolerance,
                                   double minimumLength,
                                   double maximumLength) const;

  virtual PolylineCurve
  ToPolyline(int32_t mainSegmentCount, int32_t subSegmentCount,
             double maxAngleRadians, double maxChordLengthRatio,
             double maxAspectRatio, double tolerance, double minEdgeLength,
             double maxEdgeLength, bool keepStartPoint,
             C_Intv curveDomain) const;

  virtual PolylineCurve
  ToPolyline(int32_t mainSegmentCount, int32_t subSegmentCount,
             double maxAngleRadians, double maxChordLengthRatio,
             double maxAspectRatio, double tolerance, double minEdgeLength,
             double maxEdgeLength, bool keepStartPoint) const;

  virtual double TorsionAt(double t) const;

  virtual bool Transform(C_Trsf xform) override;

  virtual bool Translate(double x, double y, double z) override;

  virtual bool Translate(C_Vec translationVector) override;

  virtual Curve Trim(CurveEnd side, double length) const;

  virtual Curve Trim(C_Intv domain) const;

  virtual Curve Trim(double t0, double t1) const;

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

private:
  BRepAdaptor_CompCurve m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
