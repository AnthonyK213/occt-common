#include <OcctCommon/Geometry/Curve.h>
#include <OcctCommon/Geometry/Interval.h>
#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Vector3d.h>

namespace OcctCommon {
namespace Geometry {

Interval Curve::Domain() const {
  return Interval(m_data->FirstParameter(), m_data->LastParameter());
}

// TODO
bool Curve::HasBrepForm() const { return true; }

bool Curve::IsClosed() const { return m_data->IsClosed(); }

// TODO
bool Curve::IsDeformable() const { return true; }

bool Curve::IsPeriodic() const { return m_data->IsPeriodic(); }

// TODO
bool Curve::IsValid() const { return true; }

// TODO
uint32_t Curve::ObjectType() const { return 0; }

Point3d Curve::PointAtEnd() const {
  return Point3d{m_data->Value(m_data->LastParameter())};
}

Point3d Curve::PointAtStart() const {
  return Point3d{m_data->Value(m_data->FirstParameter())};
}

int32_t Curve::SpanCount() const { return m_data->NbCurves(); }

Vector3d Curve::TangentAtEnd() const {
  gp_Vec v1 = m_data->DN(m_data->LastParameter(), 1);
  return Vector3d{v1};
}

Vector3d Curve::TangentAtStart() const {
  gp_Vec v1 = m_data->DN(m_data->FirstParameter(), 1);
  return Vector3d{v1};
}

// TODO
PointContainment Curve::Contains(__CPnt testPoint, __CPln plane,
                                 double tolerance) const {
  return PointContainment::Unset;
}

} // namespace Geometry
} // namespace OcctCommon
