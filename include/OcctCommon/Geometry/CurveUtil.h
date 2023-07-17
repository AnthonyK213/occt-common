#ifndef OCCTCOMMON_GEOMETRY_CURVEUTIL_H
#define OCCTCOMMON_GEOMETRY_CURVEUTIL_H

#include <OcctCommon/Geometry/Curve.h>
#include <OcctCommon/Geometry/NurbsCurve.h>

namespace OcctCommon {
namespace Geometry {
namespace CurveUtil {

Curve *CreateArcBlend(C_Pnt startPt, C_Vec startDir, C_Pnt endPt, C_Vec endDir,
                      double controlPointLengthRatio);

Curve *CreateArcLineArcBlend(C_Pnt startPt, C_Vec startDir, C_Pnt endPt,
                             C_Vec endDir, double radius);

Curve *CreateBlendCurve(C_Crv curve0, double t0, bool reverse0,
                        BlendContinuity continuity0, C_Crv curve1, double t1,
                        bool reverse1, BlendContinuity continuity1);

Curve *CreateBlendCurve(C_Crv curveA, C_Crv curveB, BlendContinuity continuity,
                        double bulgeA, double bulgeB);

Curve *CreateBlendCurve(C_Crv curveA, C_Crv curveB, BlendContinuity continuity);

Vec_<Arc_<Curve>> CreateBooleanDifference(C_Crv curveA, C_Crv curveB,
                                          double tolerance);

Vec_<Arc_<Curve>> CreateBooleanIntersection(C_Crv curveA, C_Crv curveB,
                                            double tolerance);

void CreateBooleanRegions();

template <typename C, typename = IS_CONTAINER_OF(C, Curve *)>
Vec_<Arc_<Curve>> CreateBooleanUnion(C &&curves, double tolerance);

template <typename C, typename = IS_CONTAINER_OF(C, Point3d)>
Curve *CreateControlPointCurve(C &&points, int32_t degree);

template <typename C, typename = IS_CONTAINER_OF(C, Point3d)>
Curve *CreateControlPointCurve(C &&points);

Curve *CreateCurve2View(C_Crv curveA, C_Crv curveB, C_Vec vectorA,
                        C_Vec vectorB, double tolerance, double angleTolerance);

Arc CreateFillet(C_Crv curve0, C_Crv curve1, double radius, double t0Base,
                 double t1Base);

Curve *CreateFilletCornersCurve(C_Crv curve, double radius, double tolerance,
                                double angleTolerance);

Vec_<Arc_<Curve>> CreateFilletCurves(C_Crv curve0, C_Pnt point0, C_Crv curve1,
                                     C_Pnt point1, double radius, bool join,
                                     bool trim, bool arcExtension,
                                     double tolerance, double angleTolerance);

template <typename C, typename = IS_CONTAINER_OF(C, Point3d)>
Curve *CreateInterpolatedCurve(C &&points, int32_t degree, CurveKnotStyle knots,
                               C_Vec startTangent, C_Vec endTangent);

template <typename C, typename = IS_CONTAINER_OF(C, Point3d)>
Curve *CreateInterpolatedCurve(C &&points, int32_t degree);

Vec_<Arc_<Curve>> CreateMatchCurve(C_Crv curve0, bool reverse0,
                                   BlendContinuity continuity, C_Crv curve1,
                                   bool reverse1, PreserveEnd preserve,
                                   bool average);

Curve *CreateMeanCurve(C_Crv curveA, C_Crv curveB,
                       double angleToleranceRadians);

Curve *CreateMeanCurve(C_Crv curveA, C_Crv curveB);

Curve *CreatePeriodicCurve(C_Crv curve, bool smooth);

Curve *CreatePeriodicCurve(C_Crv curve);

Curve *CreateSoftEditCurve(C_Crv curve, double t, C_Vec delta, double length,
                           bool fixEnds);

Vec_<Arc_<Curve>> CreateTextOutlines();

Vec_<Arc_<Curve>> CreateTweenCurves(C_Crv curve0, C_Crv curve1,
                                    int32_t numCurves, double tolerance);

Vec_<Arc_<Curve>> CreateTweenCurvesWithMatching(C_Crv curve0, C_Crv curve1,
                                                int32_t numCurves,
                                                double tolerance);

Vec_<Arc_<Curve>> CreateTweenCurvesWithSampling(C_Crv curve0, C_Crv curve1,
                                                int32_t numCurves,
                                                int32_t numSamples,
                                                double tolerance);

bool DoDirectionsMatch(C_Crv curveA, C_Crv curveB);

bool GetDistancesBetweenCurves(C_Crv curveA, C_Crv curveB, double tolerance,
                               double &maxDistance,
                               double &maxDistanceParameterA,
                               double &maxDistanceParameterB,
                               double &minDistance,
                               double &minDistanceParameterA,
                               double &minDistanceParameterB);

bool GetFilletPoints(C_Crv curve0, C_Crv curve1, double radius, double t0Base,
                     double t1Base, double &t0, double &t1, Plane &filletPlane);

template <typename C, typename = IS_CONTAINER_OF(C, Curve *)>
Vec_<Arc_<Curve>> JoinCurves(C &&curves, double joinTolerance,
                             bool preserveDirection);

template <typename C, typename = IS_CONTAINER_OF(C, Curve *)>
Vec_<Arc_<Curve>> JoinCurves(C &&curves, double joinTolerance);

template <typename C, typename = IS_CONTAINER_OF(C, Curve *)>
Vec_<Curve> JoinCurves(C &&curves);

bool MakeEndsMeet(Curve &curveA, bool adjustStartCurveA, Curve &curveB,
                  bool adjustStartCurveB);

RegionContainment PlanarClosedCurveRelationship(C_Crv curveA, C_Crv curveB,
                                                C_Pln testPlane,
                                                double tolerance);

bool PlanarCurveCollision(C_Crv curveA, C_Crv curveB, C_Pln testPlane,
                          double tolerance);

Vec_<Arc_<Curve>> ProjectToBrep(C_Crv curve, C_Brp brep, C_Vec direction,
                                double tolerance);

template <typename T>
Vec_<Arc_<Curve>> ProjectToBrep(C_Crv curve, T _first, T _last, C_Vec direction,
                                double tolerance, Vec_<int32_t> &brepIndices);

template <typename T>
Vec_<Arc_<Curve>> ProjectToBrep(C_Crv curve, T _first, T _last, C_Vec direction,
                                double tolerance);

template <typename T1, typename T2>
Vec_<Arc_<Curve>> ProjectToBrep(T1 _first1, T1 _last1, T2 _first2, T2 _last2,
                                C_Vec direction, double tolerance,
                                Vec_<int32_t> &curveIndices,
                                Vec_<int32_t> brepIndices);

template <typename T1, typename T2>
Vec_<Arc_<Curve>> ProjectToBrep(T1 _first1, T1 _last1, T2 _first2, T2 _last2,
                                C_Vec direction, double tolerance);

template <typename T>
Vec_<Arc_<Curve>> ProjectToMesh(C_Crv curve, T _first, T _last, C_Vec direction,
                                double tolerance);

Vec_<Arc_<Curve>> ProjectToMesh(C_Crv curve, C_Msh mesh, C_Vec direction,
                                double tolerance);

template <typename T1, typename T2>
Vec_<Arc_<Curve>> ProjectToMesh(C_Crv curve, T1 _first1, T1 _last1, T2 _first2,
                                T2 _last2, C_Vec direction, double tolerance);

Curve *ProjectToPlane(C_Crv cruve, C_Pln plane);

} // namespace CurveUtil
} // namespace Geometry
} // namespace OcctCommon

#include <OcctCommon/Geometry/detail/CurveUtil.inl>

#endif
