#ifndef OCCTCOMMON_GEOMETRY_CURVEUTIL_H
#define OCCTCOMMON_GEOMETRY_CURVEUTIL_H

#include <OcctCommon/Geometry/Curve.h>
#include <OcctCommon/Geometry/NurbsCurve.h>

namespace OcctCommon {
namespace Geometry {
namespace CurveUtil {

H_Curve CreateArcBlend(C_Pnt startPt, C_Vec startDir, C_Pnt endPt, C_Vec endDir,
                       double controlPointLengthRatio);

H_Curve CreateArcLineArcBlend(C_Pnt startPt, C_Vec startDir, C_Pnt endPt,
                              C_Vec endDir, double radius);

H_Curve CreateBlendCurve(const H_Curve &curve0, double t0, bool reverse0,
                         BlendContinuity continuity0, const H_Curve &curve1,
                         double t1, bool reverse1, BlendContinuity continuity1);

H_Curve CreateBlendCurve(const H_Curve &curveA, const H_Curve &curveB,
                         BlendContinuity continuity, double bulgeA,
                         double bulgeB);

H_Curve CreateBlendCurve(const H_Curve &curveA, const H_Curve &curveB,
                         BlendContinuity continuity);

V_Curve CreateBooleanDifference(const H_Curve &curveA, const H_Curve &curveB,
                                double tolerance);

V_Curve CreateBooleanIntersection(const H_Curve &curveA, const H_Curve &curveB,
                                  double tolerance);

void CreateBooleanRegions();

template <typename C, typename = IS_CONTAINER_OF(C, H_Curve)>
V_Curve CreateBooleanUnion(C &&curves, double tolerance);

template <typename C, typename = IS_CONTAINER_OF(C, Point3d)>
H_Curve CreateControlPointCurve(C &&points, int32_t degree);

template <typename C, typename = IS_CONTAINER_OF(C, Point3d)>
H_Curve CreateControlPointCurve(C &&points);

H_Curve CreateCurve2View(const H_Curve &curveA, const H_Curve &curveB,
                         C_Vec vectorA, C_Vec vectorB, double tolerance,
                         double angleTolerance);

Arc CreateFillet(const H_Curve &curve0, const H_Curve &curve1, double radius,
                 double t0Base, double t1Base);

Curve *CreateFilletCornersCurve(const H_Curve &curve, double radius,
                                double tolerance, double angleTolerance);

Vec_<Arc_<Curve>> CreateFilletCurves(const H_Curve &curve0, C_Pnt point0,
                                     const H_Curve &curve1, C_Pnt point1,
                                     double radius, bool join, bool trim,
                                     bool arcExtension, double tolerance,
                                     double angleTolerance);

template <typename C, typename = IS_CONTAINER_OF(C, Point3d)>
H_Curve CreateInterpolatedCurve(C &&points, int32_t degree,
                                CurveKnotStyle knots, C_Vec startTangent,
                                C_Vec endTangent);

template <typename C, typename = IS_CONTAINER_OF(C, Point3d)>
H_Curve CreateInterpolatedCurve(C &&points, int32_t degree);

V_Curve CreateMatchCurve(const H_Curve &curve0, bool reverse0,
                         BlendContinuity continuity, const H_Curve &curve1,
                         bool reverse1, PreserveEnd preserve, bool average);

Curve *CreateMeanCurve(const H_Curve &curveA, const H_Curve &curveB,
                       double angleToleranceRadians);

Curve *CreateMeanCurve(const H_Curve &curveA, const H_Curve &curveB);

Curve *CreatePeriodicCurve(const H_Curve &curve, bool smooth);

Curve *CreatePeriodicCurve(const H_Curve &curve);

Curve *CreateSoftEditCurve(const H_Curve &curve, double t, C_Vec delta,
                           double length, bool fixEnds);

V_Curve CreateTextOutlines();

V_Curve CreateTweenCurves(const H_Curve &curve0, const H_Curve &curve1,
                          int32_t numCurves, double tolerance);

V_Curve CreateTweenCurvesWithMatching(const H_Curve &curve0,
                                      const H_Curve &curve1, int32_t numCurves,
                                      double tolerance);

V_Curve CreateTweenCurvesWithSampling(const H_Curve &curve0,
                                      const H_Curve &curve1, int32_t numCurves,
                                      int32_t numSamples, double tolerance);

bool DoDirectionsMatch(const H_Curve &curveA, const H_Curve &curveB);

bool GetDistancesBetweenCurves(const H_Curve &curveA, const H_Curve &curveB,
                               double tolerance, double &maxDistance,
                               double &maxDistanceParameterA,
                               double &maxDistanceParameterB,
                               double &minDistance,
                               double &minDistanceParameterA,
                               double &minDistanceParameterB);

bool GetFilletPoints(const H_Curve &curve0, const H_Curve &curve1,
                     double radius, double t0Base, double t1Base, double &t0,
                     double &t1, Plane &filletPlane);

template <typename C, typename = IS_CONTAINER_OF(C, H_Curve)>
V_Curve JoinCurves(C &&curves, double joinTolerance, bool preserveDirection);

template <typename C, typename = IS_CONTAINER_OF(C, H_Curve)>
V_Curve JoinCurves(C &&curves, double joinTolerance);

template <typename C, typename = IS_CONTAINER_OF(C, H_Curve)>
V_Curve JoinCurves(C &&curves);

bool MakeEndsMeet(Curve &curveA, bool adjustStartCurveA, Curve &curveB,
                  bool adjustStartCurveB);

RegionContainment PlanarClosedCurveRelationship(const H_Curve &curveA,
                                                const H_Curve &curveB,
                                                C_Pln testPlane,
                                                double tolerance);

bool PlanarCurveCollision(const H_Curve &curveA, const H_Curve &curveB,
                          C_Pln testPlane, double tolerance);

V_Curve ProjectToBrep(const H_Curve &curve, C_Brp brep, C_Vec direction,
                      double tolerance);

template <typename T>
V_Curve ProjectToBrep(const H_Curve &curve, T _first, T _last, C_Vec direction,
                      double tolerance, Vec_<int32_t> &brepIndices);

template <typename T>
V_Curve ProjectToBrep(const H_Curve &curve, T _first, T _last, C_Vec direction,
                      double tolerance);

template <typename T1, typename T2>
V_Curve ProjectToBrep(T1 _first1, T1 _last1, T2 _first2, T2 _last2,
                      C_Vec direction, double tolerance,
                      Vec_<int32_t> &curveIndices, Vec_<int32_t> brepIndices);

template <typename T1, typename T2>
V_Curve ProjectToBrep(T1 _first1, T1 _last1, T2 _first2, T2 _last2,
                      C_Vec direction, double tolerance);

template <typename T>
V_Curve ProjectToMesh(const H_Curve &curve, T _first, T _last, C_Vec direction,
                      double tolerance);

V_Curve ProjectToMesh(const H_Curve &curve, C_Msh mesh, C_Vec direction,
                      double tolerance);

template <typename T1, typename T2>
V_Curve ProjectToMesh(const H_Curve &curve, T1 _first1, T1 _last1, T2 _first2,
                      T2 _last2, C_Vec direction, double tolerance);

H_Curve ProjectToPlane(const H_Curve &cruve, C_Pln plane);

} // namespace CurveUtil
} // namespace Geometry
} // namespace OcctCommon

#include <OcctCommon/Geometry/detail/CurveUtil.inl>

#endif
