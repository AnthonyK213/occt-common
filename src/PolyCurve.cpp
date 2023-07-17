#include <OcctCommon/Geometry/Plane.h>
#include <OcctCommon/Geometry/PolyCurve.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {
  
PolyCurve::PolyCurve() {
  TopoDS_Wire wire = BRepBuilderAPI_MakeWire();
  m_data = std::make_shared<BRepAdaptor_CompCurve>(wire);
}

PolyCurve::PolyCurve(const TopoDS_Wire &wire) {
  m_data = std::make_shared<BRepAdaptor_CompCurve>(wire);
}

int32_t PolyCurve::Degree() const { return m_data->Degree(); }

int32_t PolyCurve::SpanCount() const { return m_data->NbIntervals(GeomAbs_CN); }

bool PolyCurve::IsInPlane(C_Pln testPlane, double tolerance) const { NOT_IMPL }

bool PolyCurve::IsPlanar(double tolerance) const {NOT_IMPL}

Curve *PolyCurve::Trim(double t0, double t1) const {
  auto trimmed = m_data->Trim(t0, t1, _Math::ZeroTolerance);
#ifdef OCC_ADAPTOR3D_CURVE_IS_STANDARD_TRANSIENT
  auto compCurve = Handle(BRepAdaptor_CompCurve)::DownCast(trimmed);
  if (compCurve.IsNull()) {
    return nullptr;
  }
  return new PolyCurve(compCurve->Wire());
#else
  // FIXME: WTF
  Adaptor3d_Curve adaptor = trimmed->GetCurve();
  auto compCurve = static_cast<BRepAdaptor_CompCurve*>(&adaptor);
  return new PolyCurve(compCurve->Wire());
#endif
}

PolyCurve::~PolyCurve() noexcept {}

} // namespace Geometry
} // namespace OcctCommon
