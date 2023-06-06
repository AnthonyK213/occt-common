#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Transform.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Vector3d::Vector3d(double x, double y, double z) : _gpWrapper({x, y, z}) {}

Vector3d::Vector3d(__CPnt point) : _gpWrapper(point.Data().Coord()) {}

Vector3d::Vector3d(__CVec vector) : _gpWrapper(vector.m_data) {}

// Tolerance?
inline bool Vector3d::IsUnitVector() const { return Length() == 1.0; }

inline bool Vector3d::IsValid() const {
  return __Math::IsValidDouble(X()) && __Math::IsValidDouble(Y()) &&
         __Math::IsValidDouble(Z());
}

inline bool Vector3d::IsZero() const {
  return X() == 0.0 && Y() == 0.0 && Z() == 0.0;
}

inline double Vector3d::Length() const { return m_data.Magnitude(); }

inline double Vector3d::SquareLength() const {
  return m_data.SquareMagnitude();
}

Vector3d Vector3d::Unset() {
  return Vector3d(OcctMath::UnsetValue(), OcctMath::UnsetValue(),
                  OcctMath::UnsetValue());
}

inline double Vector3d::X() const { return m_data.X(); }

inline double Vector3d::Y() const { return m_data.Y(); }

inline double Vector3d::Z() const { return m_data.Z(); }

__CVec Vector3d::XAxis() {
  static Vector3d Vector3d_XAxis(gp::DX());
  return Vector3d_XAxis;
}

__CVec Vector3d::YAxis() {
  static Vector3d Vector3d_YAxis(gp::DY());
  return Vector3d_YAxis;
}

__CVec Vector3d::ZAxis() {
  static Vector3d Vector3d_ZAxis(gp::DZ());
  return Vector3d_ZAxis;
}

__CVec Vector3d::Zero() {
  static Vector3d Vector3d_Zero(gp::Origin());
  return Vector3d_Zero;
}

Vector3d Vector3d::Add(__CVec vector1, __CVec vector2) {
  return Vector3d(vector1.Data() + vector2.Data());
}

bool Vector3d::AreOrthogonal(__CVec x, __CVec y, __CVec z) {
  if (x.IsZero() || y.IsZero() || z.IsZero())
    return false;
  return Vector3d(x.Data().CrossCrossed(y.Data(), z.Data())).IsZero();
}

bool Vector3d::AreOrithonormal(__CVec x, __CVec y, __CVec z) {
  if (!Vector3d::AreOrthogonal(x, y, z))
    return false;
  return x.IsUnitVector() && y.IsUnitVector() && z.IsUnitVector();
}

bool Vector3d::AreRighthanded(__CVec x, __CVec y, __CVec z) {
  if (!AreOrithonormal(x, y, z))
    return false;
  return x.Data().DotCross(y.Data(), z.Data()) > 0.0;
}

Vector3d Vector3d::CrossProduct(__CVec a, __CVec b) {
  return Vector3d(a.Data().Crossed(b.Data()));
}

Vector3d Vector3d::Divide(__CVec vector, double t) {
  return Vector3d(vector.Data() / t);
}

Vector3d Vector3d::Mulitply(__CVec vector, double t) {
  return Vector3d(vector.Data() * t);
}

Vector3d Vector3d::Mulitply(double t, __CVec vector) {
  return Vector3d(vector.Data() * t);
}

double Vector3d::Mulitply(__CVec vector1, __CVec vector2) {
  return vector1.Data().Dot(vector2.Data());
}

Vector3d Vector3d::Negate(__CVec vector) {
  return Vector3d(-vector.X(), -vector.Y(), -vector.Z());
}

Vector3d Vector3d::Subtract(__CVec vector1, __CVec vector2) {
  return Vector3d(vector1.Data() - vector2.Data());
}

int Vector3d::CompareTo(__CVec other) const {
  if (X() < other.X()) {
    return -1;
  } else if (X() == other.X()) {
    if (Y() < other.Y()) {
      return -1;
    } else if (Y() == other.Y()) {
      if (Z() < other.Z()) {
        return -1;
      } else if (Z() == other.Z()) {
        return 0;
      } else {
        return 1;
      }
    } else {
      return 1;
    }
  } else {
    return 1;
  }
}

bool Vector3d::Reverse() {
  if (!IsValid() || IsZero())
    return false;
  m_data.Reverse();
  return true;
}

bool Vector3d::Rotate(double angleRadiance, __CVec rotationAxis) {
  if (!rotationAxis.IsValid() || rotationAxis.IsZero())
    return false;
  gp_Ax1 axis(gp::Origin(), rotationAxis.Data().XYZ());
  m_data.Rotate(axis, angleRadiance);
  return true;
}

void Vector3d::Transform(__CTrsf transformation) {
  m_data.Transform(transformation.Data());
}

bool Vector3d::Unitize() {
  if (!IsValid() || IsZero())
    return false;
  m_data.Normalize();
  return true;
}

bool Vector3d::operator!=(__CVec other) const {
  return X() != other.X() || Y() != other.Y() || Z() != other.Z();
}

bool Vector3d::operator==(__CVec other) const {
  return X() == other.X() && Y() == other.Y() && Z() == other.Z();
}

} // namespace Geometry
} // namespace OcctCommon
