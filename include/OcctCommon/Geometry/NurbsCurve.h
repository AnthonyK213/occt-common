#ifndef OCCTCOMMON_GEOMETRY_NURBSCURVE_H
#define OCCTCOMMON_GEOMETRY_NURBSCURVE_H

#include <OcctCommon/Geometry/Curve.h>

namespace OcctCommon {
namespace Geometry {

class NurbsCurve final : public Curve {
public:
  NurbsCurve(int dimension, bool rational, int32_t order, int32_t pointCount);

  NurbsCurve(int32_t degree, int32_t pointCount);

  NurbsCurve(const Handle(Geom_BSplineCurve) & curve);

  NurbsCurve(C_NCrv nurbsCurve) = default;

  virtual int32_t Degree() const override;

  virtual int32_t SpanCount() const override;

  virtual bool IsInPlane(C_Pln testPlane, double tolerance) const override;

  virtual bool IsPlanar(double tolerance) const override;

  virtual Curve *Trim(double t0, double t1) const override;

  virtual ~NurbsCurve() noexcept override;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
