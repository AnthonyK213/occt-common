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
  throw std::runtime_error("Not implemented");
}

} // namespace Geometry
} // namespace OcctCommon
