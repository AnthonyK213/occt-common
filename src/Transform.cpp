#include <OcctCommon/Geometry/Plane.h>
#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Transform.h>
#include <OcctCommon/Geometry/Vector3d.h>
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

bool Transform::IsAffine() const { return IsValid(); }

bool Transform::IsIdentity() const { return *this == Identity(); }

bool Transform::IsLinear() const {
  if (IsAffine() && M03() == 0.0)
    return M13() == 0.0 && M23() == 0.0;
  return false;
}

// TODO
bool Transform::IsRotation() const {
  return IsLinear() && Determinant() == 1.0;
}

bool Transform::IsValid() const {
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 4; ++j) {
      if (!__Math::IsValidDouble(m_data.Value(i, j))) {
        return false;
      }
    }
  }
  return true;
}

bool Transform::IsZero() const { return IsZeroTransformation(); }

bool Transform::IsZero4x4() const { return false; }

bool Transform::IsZeroTransformation() const {
  return *this == ZeroTransformation();
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

// TODO
int32_t Transform::RigidType() const { return 0; }

// TODO
int32_t Transform::SimilarityType() const { return 0; }

Transform Transform::ChangeBasis(__CPln plane0, __CPln plane1) {
  gp_Trsf result{};
  result.SetTransformation(plane0.Data().Position(), plane1.Data().Position());
  return Transform{result};
}

// TODO
Transform Transform::ChangeBasis(__CVec initialBasisX, __CVec initialBasisY,
                                 __CVec initialBasisZ, __CVec finalBasisX,
                                 __CVec finalBasisY, __CVec finalBasisZ) {
  return Transform::Identity();
}

Transform Transform::Diagonal(double d0, double d1, double d2) {
  Transform result{gp_GTrsf(gp_Mat(d0, 0.0, 0.0, 0.0, d1, 0.0, 0.0, 0.0, d2),
                            gp_XYZ(0.0, 0.0, 0.0))};
  return result;
}

Transform Transform::Diagonal(__CVec diagonal) {
  return Transform::Diagonal(diagonal.X(), diagonal.Y(), diagonal.Z());
}

Transform Transform::Mirror(__CPln mirrorPlane) {
  gp_Trsf mirror{};
  mirror.SetMirror(gp_Ax2(mirrorPlane.Data().Location(),
                          mirrorPlane.Data().Axis().Direction()));
  return Transform{mirror};
}

Transform Transform::Mirror(__CPnt pointOnMirrorPlane,
                            __CVec normalToMirrorPlane) {
  gp_Trsf mirror{};
  mirror.SetMirror(
      gp_Ax2(pointOnMirrorPlane.Data(), normalToMirrorPlane.Data()));
  return Transform{mirror};
}

Transform Transform::Multiply(__CTrsf a, __CTrsf b) {
  return Transform(a.Data() * b.Data());
}

Transform Transform::PlaneToPlane(__CPln plane0, __CPln plane1) {
  gp_Trsf result{};
  result.SetDisplacement(plane0.Data().Position(), plane1.Data().Position());
  return Transform{result};
}

Transform Transform::Rotation(double angleRadians, __CPnt rotationCenter) {
  return Transform::Rotation(angleRadians, Vector3d::ZAxis(), rotationCenter);
}

Transform Transform::Rotation(double angleRadians, __CVec rotationAxis,
                              __CPnt rotationCenter) {
  gp_Trsf rotation{};
  rotation.SetRotation(gp_Ax1(rotationCenter.Data(), rotationAxis.Data()),
                       angleRadians);
  return Transform{rotation};
}

Transform Transform::Scale(__CPnt anchor, double scaleFactor) {
  gp_Trsf scale{};
  scale.SetScale(anchor.Data(), scaleFactor);
  return Transform{scale};
}

Transform Transform::Translation(double x, double y, double z) {
  gp_Trsf translation{};
  translation.SetTranslation(gp_Vec(x, y, z));
  return Transform{translation};
}

Transform Transform::Translation(__CVec motion) {
  gp_Trsf translation{};
  translation.SetTranslation(motion.Data());
  return Transform{translation};
}

bool Transform::operator==(__CTrsf other) const {
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 4; ++j) {
      if (m_data.Value(i, j) != other.m_data.Value(i, j)) {
        return false;
      }
    }
  }
  return true;
}

} // namespace Geometry
} // namespace OcctCommon
