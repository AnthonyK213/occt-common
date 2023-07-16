#include <OcctCommon/Geometry/NurbsCurve.h>
#include <OcctCommon/Geometry/Plane.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

NurbsCurve::NurbsCurve(int32_t degree, int32_t pointCount) {}

NurbsCurve::NurbsCurve(const Handle(Geom_BSplineCurve) & curve) {
  m_data = std::make_shared<GeomAdaptor_Curve>(curve);
}

int32_t NurbsCurve::Degree() const { return m_data->Degree(); }

int32_t NurbsCurve::SpanCount() const {
  return m_data->NbIntervals(GeomAbs_CN);
}

bool NurbsCurve::IsPlanar(double tolerance) const {
  GProp_PEquation prop(m_data->BSpline()->Poles(), tolerance);
  return prop.IsPlanar() || prop.IsLinear();
}

bool NurbsCurve::IsInPlane(C_Pln testPlane, double tolerance) const {
  GProp_PEquation prop(m_data->BSpline()->Poles(), tolerance);
  if (prop.IsLinear()) {
    Vector3d dir(prop.Line().Direction());
    return dir.IsPerpendicularTo(testPlane.ZAxis(), tolerance);
  }
  if (prop.IsPlanar()) {
    return testPlane.IsCoplanar(prop.Plane(), tolerance);
  }
  return false;
}

Curve *NurbsCurve::Trim(double t0, double t1) const {
  auto result = m_data->Trim(t0, t1, _Math::ZeroTolerance);
  return new NurbsCurve(result->BSpline());
}

NurbsCurve::~NurbsCurve() noexcept {}

} // namespace Geometry
} // namespace OcctCommon
