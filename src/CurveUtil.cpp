#include <OcctCommon/Geometry/CurveUtil.h>

namespace OcctCommon {
namespace Geometry {
namespace CurveUtil {

Curve *CreateArcBlend(C_Pnt startPt, C_Vec startDir, C_Pnt endPt, C_Vec endDir,
                      double controlPointLengthRatio){NOT_IMPL}

Curve *CreateArcLineArcBlend(C_Pnt startPt, C_Vec startDir, C_Pnt endPt,
                             C_Vec endDir, double radius){NOT_IMPL}

Curve *CreateBlendCurve(C_Crv curve0, double t0, bool reverse0,
                        BlendContinuity continuity0, C_Crv curve1, double t1,
                        bool reverse1, BlendContinuity continuity1){NOT_IMPL}

Curve *CreateBlendCurve(C_Crv curveA, C_Crv curveB, BlendContinuity continuity,
                        double bulgeA, double bulgeB){NOT_IMPL}

Curve *CreateBlendCurve(C_Crv curveA, C_Crv curveB,
                        BlendContinuity continuity){NOT_IMPL}

Vec_<Arc_<Curve>> CreateBooleanDifference(C_Crv curveA, C_Crv curveB,
                                          double tolerance){NOT_IMPL}

Vec_<Arc_<Curve>> CreateBooleanIntersection(C_Crv curveA, C_Crv curveB,
                                            double tolerance) {
  NOT_IMPL
}

void CreateBooleanRegions();

} // namespace CurveUtil
} // namespace Geometry
} // namespace OcctCommon
