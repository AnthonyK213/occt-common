#include <OcctCommon/Geometry/Transform.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Transform::Transform(__CTrsf transform) : _gpWrapper(transform.m_data) {}

__CTrsf Transform::Identity() noexcept {
  static Transform Transform_Identity{gp_GTrsf()};
  return Transform_Identity;
}

__CTrsf Transform::Unset() noexcept {
  static Transform Transform_Unset{gp_GTrsf(
      gp_Mat(__Math::UnsetValue, __Math::UnsetValue, __Math::UnsetValue,
             __Math::UnsetValue, __Math::UnsetValue, __Math::UnsetValue,
             __Math::UnsetValue, __Math::UnsetValue, __Math::UnsetValue),
      gp_XYZ(__Math::UnsetValue, __Math::UnsetValue, __Math::UnsetValue))};
  return Transform_Unset;
}

__CTrsf Transform::ZeroTransformation() noexcept {
  static Transform Transform_Zero{
      gp_GTrsf(gp_Mat(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0),
               gp_XYZ(0.0, 0.0, 0.0))};
  return Transform_Zero;
}

double Transform::Determinant() const {
  return m_data.VectorialPart().Determinant();
}

double Transform::M00() const { return m_data.Value(1, 1); }

double Transform::M01() const { return m_data.Value(1, 2); }

double Transform::M02() const { return m_data.Value(1, 3); }

double Transform::M03() const { return m_data.Value(1, 4); }

double Transform::M10() const { return m_data.Value(2, 1); }

double Transform::M11() const { return m_data.Value(2, 2); }

double Transform::M12() const { return m_data.Value(2, 3); }

double Transform::M13() const { return m_data.Value(2, 4); }

double Transform::M20() const { return m_data.Value(3, 1); }

double Transform::M21() const { return m_data.Value(3, 2); }

double Transform::M22() const { return m_data.Value(3, 3); }

double Transform::M23() const { return m_data.Value(3, 4); }

double Transform::M30() const { return 0.0; }

double Transform::M31() const { return 0.0; }

double Transform::M32() const { return 0.0; }

double Transform::M33() const { return 1.0; }

} // namespace Geometry
} // namespace OcctCommon
