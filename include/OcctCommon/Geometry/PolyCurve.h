#ifndef OCCTCOMMON_GEOMETRY_POLYCURVE_H
#define OCCTCOMMON_GEOMETRY_POLYCURVE_H

#include <OcctCommon/Geometry/Curve.h>

namespace OcctCommon {
namespace Geometry {

class PolyCurve final : public Curve {
public:
  PolyCurve();

  PolyCurve(const TopoDS_Wire &wire);

  PolyCurve(C_PCrv polyCurve) = default;

  virtual int32_t Degree() const override;

  virtual int32_t SpanCount() const override;

  virtual bool IsInPlane(C_Pln testPlane, double tolerance) const override;

  virtual bool IsPlanar(double tolerance) const override;

  virtual H_Curve Trim(double t0, double t1) const override;

  virtual ~PolyCurve() noexcept override;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
