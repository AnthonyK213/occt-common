#include <OcctCommon/Geometry/Plane.h>
#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Transform.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Transform::Transform(C_Trsf transform) : _gpWrapper(transform.m_data) {}

C_Trsf Transform::Identity() noexcept {
  static Transform Transform_Identity{gp_GTrsf()};
  return Transform_Identity;
}

C_Trsf Transform::Unset() noexcept {
  static Transform Transform_Unset{gp_GTrsf(
      gp_Mat(_Math::UnsetValue, _Math::UnsetValue, _Math::UnsetValue,
             _Math::UnsetValue, _Math::UnsetValue, _Math::UnsetValue,
             _Math::UnsetValue, _Math::UnsetValue, _Math::UnsetValue),
      gp_XYZ(_Math::UnsetValue, _Math::UnsetValue, _Math::UnsetValue))};
  return Transform_Unset;
}

C_Trsf Transform::ZeroTransformation() noexcept {
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
      if (!_Math::IsValidDouble(m_data.Value(i, j))) {
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

Transform Transform::ChangeBasis(C_Pln plane0, C_Pln plane1) {
  gp_Trsf result{};
  result.SetTransformation(plane0.Data().Position(), plane1.Data().Position());
  return Transform{result};
}

// TODO
Transform Transform::ChangeBasis(C_Vec initialBasisX, C_Vec initialBasisY,
                                 C_Vec initialBasisZ, C_Vec finalBasisX,
                                 C_Vec finalBasisY, C_Vec finalBasisZ) {
  return Transform::Identity();
}

Transform Transform::Diagonal(double d0, double d1, double d2) {
  Transform result{gp_GTrsf(gp_Mat(d0, 0.0, 0.0, 0.0, d1, 0.0, 0.0, 0.0, d2),
                            gp_XYZ(0.0, 0.0, 0.0))};
  return result;
}

Transform Transform::Diagonal(C_Vec diagonal) {
  return Transform::Diagonal(diagonal.X(), diagonal.Y(), diagonal.Z());
}

Transform Transform::Mirror(C_Pln mirrorPlane) {
  gp_Trsf mirror{};
  mirror.SetMirror(gp_Ax2(mirrorPlane.Data().Location(),
                          mirrorPlane.Data().Axis().Direction()));
  return Transform{mirror};
}

Transform Transform::Mirror(C_Pnt pointOnMirrorPlane,
                            C_Vec normalToMirrorPlane) {
  gp_Trsf mirror{};
  mirror.SetMirror(
      gp_Ax2(pointOnMirrorPlane.Data(), normalToMirrorPlane.Data()));
  return Transform{mirror};
}

Transform Transform::Multiply(C_Trsf a, C_Trsf b) {
  return Transform(a.Data() * b.Data());
}

Transform Transform::PlaneToPlane(C_Pln plane0, C_Pln plane1) {
  gp_Trsf result{};
  result.SetDisplacement(plane0.Data().Position(), plane1.Data().Position());
  return Transform{result};
}

Transform Transform::Rotation(double angleRadians, C_Pnt rotationCenter) {
  return Transform::Rotation(angleRadians, Vector3d::ZAxis(), rotationCenter);
}

Transform Transform::Rotation(double angleRadians, C_Vec rotationAxis,
                              C_Pnt rotationCenter) {
  gp_Trsf rotation{};
  rotation.SetRotation(gp_Ax1(rotationCenter.Data(), rotationAxis.Data()),
                       angleRadians);
  return Transform{rotation};
}

Transform Transform::Scale(C_Pnt anchor, double scaleFactor) {
  gp_Trsf scale{};
  scale.SetScale(anchor.Data(), scaleFactor);
  return Transform{scale};
}

Transform Transform::Translation(double x, double y, double z) {
  gp_Trsf translation{};
  translation.SetTranslation(gp_Vec(x, y, z));
  return Transform{translation};
}

Transform Transform::Translation(C_Vec motion) {
  gp_Trsf translation{};
  translation.SetTranslation(motion.Data());
  return Transform{translation};
}

bool Transform::TryGetInverse(Transform &inverseTransform) const {
  try {
    inverseTransform = m_data.Inverted();
    return true;
  } catch (...) {
    return false;
  }
}

bool Transform::operator!=(C_Trsf other) const {
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 4; ++j) {
      if (m_data.Value(i, j) != other.m_data.Value(i, j)) {
        return true;
      }
    }
  }
  return false;
}

bool Transform::operator==(C_Trsf other) const {
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 4; ++j) {
      if (m_data.Value(i, j) != other.m_data.Value(i, j)) {
        return false;
      }
    }
  }
  return true;
}

const Transform Transform::operator*(C_Trsf transform) const {
  return Transform(m_data.Multiplied(transform.m_data));
}

const Point3d Transform::operator*(C_Pnt point) const {
  double x = point.X();
  double y = point.Y();
  double z = point.Z();
  double rx = M00() * x + M01() * y + M02() * z + M03();
  double ry = M10() * x + M11() * y + M12() * z + M13();
  double rz = M20() * x + M21() * y + M22() * z + M23();
  // FIXME: emm...
  double rw = M30() * x + M31() * y + M32() * z + M33();
  if (rw != 0.0) {
    rw = 1.0 / rw;
    rx *= rw;
    ry *= rw;
    rz *= rw;
  }
  return Point3d(rx, ry, rz);
}

const Vector3d Transform::operator*(C_Vec vector) const {
  double x = vector.X();
  double y = vector.Y();
  double z = vector.Z();
  double rx = M00() * x + M01() * y + M02() * z + M03();
  double ry = M10() * x + M11() * y + M12() * z + M13();
  double rz = M20() * x + M21() * y + M22() * z + M23();
  return Vector3d(rx, ry, rz);
}

Transform &Transform::operator*=(C_Trsf transform) {
  m_data.Multiply(transform.m_data);
  return *this;
}

} // namespace Geometry
} // namespace OcctCommon
