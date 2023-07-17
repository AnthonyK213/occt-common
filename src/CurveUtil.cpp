#include <OcctCommon/Geometry/CurveUtil.h>

namespace OcctCommon {
namespace Geometry {
namespace CurveUtil {

H_Curve CreateArcBlend(C_Pnt startPt, C_Vec startDir, C_Pnt endPt, C_Vec endDir,
                       double controlPointLengthRatio){NOT_IMPL}

H_Curve CreateArcLineArcBlend(C_Pnt startPt, C_Vec startDir, C_Pnt endPt,
                              C_Vec endDir, double radius){NOT_IMPL}

H_Curve CreateBlendCurve(const H_Curve &curve0, double t0, bool reverse0,
                         BlendContinuity continuity0, const H_Curve &curve1,
                         double t1, bool reverse1,
                         BlendContinuity continuity1){NOT_IMPL}

H_Curve CreateBlendCurve(const H_Curve &curveA, const H_Curve &curveB,
                         BlendContinuity continuity, double bulgeA,
                         double bulgeB){NOT_IMPL}

H_Curve CreateBlendCurve(const H_Curve &curveA, const H_Curve &curveB,
                         BlendContinuity continuity){NOT_IMPL}

V_Curve CreateBooleanDifference(const H_Curve &curveA, const H_Curve &curveB,
                                double tolerance){NOT_IMPL}

V_Curve CreateBooleanIntersection(const H_Curve &curveA, const H_Curve &curveB,
                                  double tolerance) {
  NOT_IMPL
}

void CreateBooleanRegions();

} // namespace CurveUtil
} // namespace Geometry
} // namespace OcctCommon
