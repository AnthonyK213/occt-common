#include <OcctCommon/Geometry/NurbsCurve.h>

namespace OcctCommon {
namespace Geometry {

NurbsCurve::NurbsCurve(int32_t degree, int32_t pointCount) {}

NurbsCurve::NurbsCurve(const Handle(Geom_BSplineCurve) & curve) {
  m_data = std::make_shared<GeomAdaptor_Curve>(curve);
}

int32_t NurbsCurve::Degree() const {NOT_IMPL}

int32_t NurbsCurve::SpanCount() const {
  NOT_IMPL
}

bool NurbsCurve::IsInPlane(C_Pln testPlane, double tolerance) const {NOT_IMPL}

Curve *NurbsCurve::Trim(double t0, double t1) const {NOT_IMPL}

NurbsCurve::~NurbsCurve() noexcept {
  std::cout << "NurbsCurve: AWSL" << std::endl;
}

} // namespace Geometry
} // namespace OcctCommon
