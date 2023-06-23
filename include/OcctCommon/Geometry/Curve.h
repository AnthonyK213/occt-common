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

  virtual uint32_t ClosedCurveOrientation() const;

  virtual uint32_t ClosedCurveOrientation(__CPln plane) const;

  virtual uint32_t ClosedCurveOrientation(__CTrsf xform) const;

  virtual uint32_t ClosedCurveOrientation(__CVec upDirection) const;

  virtual bool ClosestPoint(__CPnt testPoint, double &t,
                            double maximumDistance) const;

  virtual bool ClosestPoint(__CPnt testPoint, double &t) const;

  virtual bool ClosestPoints(__CCrv otherCurve, Point3d &pointOnThisCurve,
                             Point3d &pointOnOtherCurve) const;

  virtual bool CombineShortSegments(double tolerance);

  virtual ComponentIndex GetComponentIndex() const override;

  virtual PointContainment Contains(__CPnt testPoint, __CPln plane,
                                    double tolerance) const;

  static Curve CreateArcBlend(__CPnt startPt, __CVec startDir, __CPnt endPt,
                              __CVec endDir, double controlPointLengthRatio);

  static Curve CreateArcLineArcBlend(__CPnt startPt, __CVec startDir,
                                     __CPnt endPt, __CVec endDir,
                                     double radius);

  static Curve CreateBlendCurve(__CCrv curve0, double t0, bool reverse0,
                                BlendContinuity continuity0, __CCrv curve1,
                                double t1, bool reverse1,
                                BlendContinuity continuity1);

  static Curve CreateBlendCurve(__CCrv curveA, __CCrv curveB,
                                BlendContinuity continuity, double bulgeA,
                                double bulgeB);

  static Curve CreateBlendCurve(__CCrv curveA, __CCrv curveB,
                                BlendContinuity continuity);

  static Vec(Curve)
      CreateBooleanDifference(__CCrv curveA, __CCrv curveB, double tolerance);

  static Vec(Curve)
      CreateBooleanIntersection(__CCrv curveA, __CCrv curveB, double tolerance);

  static void CreateBooleanRegions();

  template <typename T>
  static Vec(Curve) CreateBooleanUnion(T _first, T _last, double tolerance);

  template <typename T>
  static Curve CreateControlPointCurve(T _first, T _last, int32_t degree);

  template <typename T> static Curve CreateControlPointCurve(T _first, T _last);

  static Curve CreateCurve2View(__CCrv curveA, __CCrv curveB, __CVec vectorA,
                                __CVec vectorB, double tolerance,
                                double angleTolerance);

  static Arc CreateFillet(__CCrv curve0, __CCrv curve1, double radius,
                          double t0Base, double t1Base);

  static Curve CreateFilletCornersCurve(__CCrv curve, double radius,
                                        double tolerance,
                                        double angleTolerance);

  static Vec(Curve)
      CreateFilletCurves(__CCrv curve0, __CPnt point0, __CCrv curve1,
                         __CPnt point1, double radius, bool join, bool trim,
                         bool arcExtension, double tolerance,
                         double angleTolerance);

  template <typename T>
  static Curve CreateInterpolatedCurve(T _first, T _last, int32_t degree,
                                       CurveKnotStyle knots,
                                       __CVec startTangent, __CVec endTangent);

  template <typename T>
  static Curve CreateInterpolatedCurve(T _first, T _last, int32_t degree);

  static Vec(Curve)
      CreateMatchCurve(__CCrv curve0, bool reverse0, BlendContinuity continuity,
                       __CCrv curve1, bool reverse1, PreserveEnd preserve,
                       bool average);

  static Curve CreateMeanCurve(__CCrv curveA, __CCrv curveB,
                               double angleToleranceRadians);

  static Curve CreateMeanCurve(__CCrv curveA, __CCrv curveB);

  static Curve CreatePeriodicCurve(__CCrv curve, bool smooth);

  static Curve CreatePeriodicCurve(__CCrv curve);

  static Curve CreateSoftEditCurve(__CCrv curve, double t, __CVec delta,
                                   double length, bool fixEnds);

  static Vec(Curve) CreateTextOutlines();

  static Vec(Curve) CreateTweenCurves(__CCrv curve0, __CCrv curve1,
                                      int32_t numCurves, double tolerance);

  static Vec(Curve)
      CreateTweenCurvesWithMatching(__CCrv curve0, __CCrv curve1,
                                    int32_t numCurves, double tolerance);

  static Vec(Curve)
      CreateTweenCurvesWithSampling(__CCrv curve0, __CCrv curve1,
                                    int32_t numCurves, int32_t numSamples,
                                    double tolerance);

  virtual Vector3d CurvatureAt(double t) const;

  virtual Vec(Vector3d) DerivativeAt(double t, uint32_t derivativeCount,
                                     CurvatureEvaluationSide side) const;

  virtual Vec(Vector3d) DerivativeAt(double t, uint32_t derivativeCount) const;

  virtual Vec(Point3d) DivedeAsContour(__CPnt contourStart, __CPnt contourEnd,
                                       double interval) const;

  virtual Vec(double) DivideByCount(int32_t segmentCount, bool includeEnds,
                                    Vec(Point3d) & points) const;

  virtual Vec(double)
      DivideByCount(int32_t segmentCount, bool includeEnds) const;

  virtual Vec(double) DivideByLength(int32_t segmentLength, bool includeEnds,
                                     Vec(Point3d) & points) const;

  virtual Vec(double) DivideByLength(int32_t segmentLength, bool includeEnds,
                                     bool reverse, Vec(Point3d) & points) const;

  virtual Vec(double) DivideByLength(int32_t segmentLength, bool includeEnds,
                                     bool reverse) const;

  virtual Vec(double)
      DivideByLength(int32_t segmentLength, bool includeEnds) const;

  virtual Vec(Point3d) DivideEquidistant(double distance) const;

  static bool DoDirectionsMatch(__CCrv curveA, __CCrv curveB);

  virtual GeometryBase Duplicate() const override;

  virtual Curve DuplicateCurve() const;

  virtual Vec(Curve) DuplicateSegments() const;

  virtual GeometryBase DuplicateShallow() const override;

  virtual Curve Extend(CurveEnd side, CurveExtensionStyle style,
                       Vec(GeometryBase) geometry) const;

  virtual Curve Extend(CurveEnd side, CurveExtensionStyle style,
                       __CPnt endPoint) const;

  virtual Curve Extend(CurveEnd side, double length,
                       CurveExtensionStyle style) const;

  virtual Curve Extend(__CIntv domain) const;

  virtual Curve Extend(double t0, double t1) const;

  virtual Curve ExtendByArc(CurveEnd side, Vec(GeometryBase) geometry) const;

  virtual Curve ExtendByLine(CurveEnd side, Vec(GeometryBase) geometry) const;

  // TODO
  virtual Curve ExtendOnSurface() const;

  virtual Vec(double) ExtremeParameters(__CVec direction) const;

  virtual Curve Fair(double distanceTolerance, double angleTolerance,
                     int32_t clampStart, int32_t clampEnd,
                     int32_t iterations) const;

  // TODO
  virtual bool FilletSurfaceToCurve() const;

  virtual bool FilletSurfaceToRail() const;

  virtual bool FindLocalInflection(__CVec N, __CIntv subDomain, double seed,
                                   double &curveParameter,
                                   double &angleError) const;

  virtual Curve Fit(int32_t degree, double fitTolerance,
                    double angleTolerance) const;

  virtual bool FrameAt(double t, Plane &plane) const;

  virtual BoundingBox GetBoundingBox(__CPln plane, Box &worldBox) const;

  virtual BoundingBox GetBoundingBox(__CPln plane) const override;

  virtual BoundingBox GetBoundingBox(bool accurate) const override;

  virtual BoundingBox GetBoundingBox(__CTrsf xform) const override;

  virtual ConicSectionType GetConicSectionType() const;

  virtual ConicSectionType GetConicSectionType(Point3d &focus1, Point3d &focus2,
                                               Point3d &center) const;

  virtual bool
  GetCurveParameterFromNurbsFormParameter(double nurbsParameter,
                                          double &curvePrameter) const;

  static bool GetDistancesBetweenCurves(__CCrv curveA, __CCrv curveB,
                                        double tolerance, double &maxDistance,
                                        double &maxDistanceParameterA,
                                        double &maxDistanceParameterB,
                                        double &minDistance,
                                        double &minDistanceParameterA,
                                        double &minDistanceParameterB);

  static bool GetFilletPoints(__CCrv curve0, __CCrv curve1, double radius,
                              double t0Base, double t1Base, double &t0,
                              double &t1, Plane &filletPlane);

  virtual double GetLength() const;

  virtual double GetLength(__CIntv subdomain) const;

  virtual double GetLength(double factorialTolerance, __CIntv subDomain) const;

  virtual double GetLength(double factorialTolerance) const;

  virtual bool GetLocalPerpPoint(__CPnt testPoint, double seedParameter,
                                 __CIntv subDomain,
                                 double &curveParameter) const;

  virtual bool GetLocalPerpPoint(__CPnt testPoint, double seedParameter,
                                 double &curveParameter) const;

  virtual bool GetLocalTangentPoint(__CPnt testPoint, double seedParameter,
                                    __CIntv subDomain,
                                    double &curveParameter) const;

  virtual bool GetLocalTangentPoint(__CPnt testPoint, double seedParameter,
                                    double &curveParameter) const;

  virtual bool GetNextDiscontinuity(Continuity continuityType, double t0,
                                    double t1, double &t) const;

  virtual bool GetNextDiscontinuity(Continuity continuityType, double t0,
                                    double t1, double consAngleTolerance,
                                    double curvatureTolerance, double &t) const;

  virtual bool
  GetNurbsFormParameterFromCurveParameter(double curveParameter,
                                          double &nurbsParameter) const;

  virtual Vec(Plane) GetPerpendicularFrames(Vec(double) parameters);

  virtual int32_t HasNurbsForm() const;

  virtual Vec(Point3d) InflectionPoints() const;

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

  virtual bool IsInPlane(__CPln testPlane, double tolerance) const;

  virtual bool IsInPlane(__CPln testPlane) const;

  virtual bool IsLinear() const;

  virtual bool IsLinear(double tolerance) const;

  virtual bool IsPlanar() const;

  virtual bool IsPlanar(double tolerance) const;

  virtual bool IsPolyline() const;

  virtual bool IsShort(double tolerance, __CIntv subDomain) const;

  virtual bool IsShort(double tolerance) const;

  template <typename T>
  static Vec(Curve) JoinCurves(T _fist, T _last, double joinTolerance,
                               bool preserveDirection);

  template <typename T>
  static Vec(Curve) JoinCurves(T _fist, T _last, double joinTolerance);

  template <typename T> static Vec(Curve) JoinCurves(T _fist, T _last);

  virtual bool LengthParameter(double segmentLength, double &t,
                               __CIntv subDomain) const;

  virtual bool LengthParameter(double segmentLength, double &t,
                               double fractionalTolerance,
                               __CIntv subDomain) const;

  virtual bool LengthParameter(double segmentLength, double &t,
                               double fractionalTolerance) const;

  virtual bool LengthParameter(double segmentLength, double &t) const;

  virtual bool LocalClosestPoint(__CPnt testPoint, double seed,
                                 double &t) const;

  virtual bool MakeClosed(double tolerance);

  virtual bool MakeDeformable();

  static bool MakeEndsMeet(Curve &curveA, bool adjustStartCurveA, Curve &curveB,
                           bool adjustStartCurveB);

  virtual Vec(Point3d) MaxCurvaturePoints() const;

  virtual bool NormalizedLengthParameter(double s, double &t,
                                         __CIntv subDomain) const;

  virtual bool NormalizedLengthParameter(double s, double &t,
                                         double fractionalTolerance,
                                         __CIntv subDomain) const;

  virtual bool NormalizedLengthParameter(double s, double &t,
                                         double fractionalTolerance) const;

  virtual bool NormalizedLengthParameter(Vec(double) s, double &t) const;

  virtual Vec(double)
      NormalizedLengthParameters(Vec(double) s, double absoluteTolerance,
                                 __CIntv subDomain) const;

  virtual Vec(double)
      NormalizedLengthParameters(Vec(double) s, double absoluteTolerance,
                                 double fractionalTolerance,
                                 __CIntv subDomain) const;

  virtual Vec(double)
      NormalizedLengthParameters(Vec(double) s, double absoluteTolerance,
                                 double fractionalTolerance) const;

  virtual Vec(double)
      NormalizedLengthParameters(Vec(double), double absoluteTolerance) const;

  virtual Vec(Curve) Offset(__CPln plane, double distance, double tolerance,
                            CurveOffsetCornerStyle cornerStyle) const;

  virtual Vec(Curve)
      Offset(__CPnt directionPoint, __CVec normal, double distance,
             double tolerance, CurveOffsetCornerStyle cornerStyle) const;

  virtual Vec(Curve)
      Offset(__CPnt directionPoint, __CVec normal, double distance,
             double tolerance, double angleTolerance, bool loose,
             CurveOffsetCornerStyle cornerStyle,
             CurveOffsetEndStyle endStyle) const;

private:
  Handle(ShapeExtend_ComplexCurve) m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
