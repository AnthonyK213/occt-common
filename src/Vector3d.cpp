#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Transform.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Vector3d::Vector3d(double x, double y, double z) : _gpWrapper({x, y, z}) {}

Vector3d::Vector3d(__CPnt point) : _gpWrapper(point.Data().Coord()) {}

Vector3d::Vector3d(__CVec vector) : _gpWrapper(vector.m_data) {}

inline bool Vector3d::IsUnitVector() const {
  return std::abs(m_data.Magnitude() - 1.0) <= __Math::SqrtEpsilon;
}

inline bool Vector3d::IsValid() const {
  if (__Math::IsValidDouble(X()) && __Math::IsValidDouble(Y()))
    return __Math::IsValidDouble(Z());
  return false;
}

inline bool Vector3d::IsZero() const {
  if (X() == 0.0 && Y() == 0.0)
    return Z() == 0.0;
  return false;
}

inline double Vector3d::Length() const { return m_data.Magnitude(); }

inline double Vector3d::SquareLength() const {
  return m_data.SquareMagnitude();
}

__CVec Vector3d::Unset() {
  static Vector3d Vector3d_Unset(__Math::UnsetValue, __Math::UnsetValue,
                                 __Math::UnsetValue);
  return Vector3d_Unset;
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
  if (X() < other.X())
    return -1;
  if (X() > other.X())
    return 1;
  if (Y() < other.Y())
    return -1;
  if (Y() > other.Y())
    return 1;
  if (Z() < other.Z())
    return -1;
  if (Z() > other.Z())
    return 1;
  return 0;
}

bool Vector3d::EpsilonEquals(__CVec other, double epsilon) const {
  if (__Math::EpsilonEquals(X(), other.X(), epsilon) &&
      __Math::EpsilonEquals(Y(), other.Y(), epsilon))
    return __Math::EpsilonEquals(Z(), other.Z(), epsilon);
  return false;
}

bool Vector3d::Equals(__CVec vector) const { return *this == vector; }

// FIXME: VectorWithNullMagnitude exception
int Vector3d::IsParallelTo(__CVec other, double angleTolerance) const {
  if (!m_data.IsParallel(other.m_data, angleTolerance))
    return 0;
  if (m_data * other.m_data > 0)
    return 1;
  return -1;
}

int Vector3d::IsParallelTo(__CVec other) const {
  return IsParallelTo(other, __Math::DefaultAngleTolerance);
}

bool Vector3d::IsPerpendicularTo(__CVec other, double angleTolerance) const {
  return m_data.IsNormal(other.m_data, angleTolerance);
}

bool Vector3d::IsPerpendicularTo(__CVec other) const {
  return IsPerpendicularTo(other, __Math::DefaultAngleTolerance);
}

bool Vector3d::IsTiny(double tolerance) const {
  if (std::abs(X()) <= tolerance && std::abs(Y()) <= tolerance)
    return std::abs(Z()) <= tolerance;
  return false;
}

bool Vector3d::IsTiny() const {
  return Vector3d::IsTiny(__Math::ZeroTolerance);
}

bool Vector3d::PerpendicularTo(__CVec other) {
  if (IsValid() && other.IsValid()) {
    gp_Vec a = other.m_data.Normalized();
    m_data.Subtract(m_data.Dot(a) * a);
    return true;
  }
  return false;
}

bool Vector3d::Reverse() {
  if (!IsValid())
    return false;
  m_data.Reverse();
  return true;
}

bool Vector3d::Rotate(double angleRadians, __CVec rotationAxis) {
  if (__Math::IsValidDouble(angleRadians) && rotationAxis.IsValid()) {
    gp_Ax1 axis(gp::Origin(), rotationAxis.Data().XYZ());
    m_data.Rotate(axis, angleRadians);
    return true;
  }
  return false;
}

void Vector3d::Transform(__CTrsf transformation) {
  m_data.Transform(transformation.Data().Trsf());
}

bool Vector3d::Unitize() {
  if (IsValid() && !IsZero()) {
    m_data.Normalize();
    return true;
  }
  return false;
}

bool Vector3d::operator!=(__CVec other) const {
  if (X() == other.X() && Y() == other.Y())
    return Z() != other.Z();
  return true;
}

bool Vector3d::operator==(__CVec other) const {
  if (X() == other.X() && Y() == other.Y())
    return Z() == other.Z();
  return false;
}

const double Vector3d::operator*(__CVec vector) const {
  return Vector3d::Mulitply(*this, vector);
}

const Vector3d Vector3d::operator*(double t) const {
  return Vector3d::Mulitply(*this, t);
}

const Vector3d Vector3d::operator-() const {
  return Vector3d::Negate(*this);
}

const Vector3d Vector3d::operator-(__CVec vector) const {
  return Vector3d::Subtract(*this, vector);
}

const Vector3d Vector3d::operator/(double t) const {
  return Vector3d::Divide(*this, t);
}

const Vector3d Vector3d::operator+(__CVec vector) const {
  return Vector3d::Add(*this, vector);
}

double Vector3d::operator[](int index) { return m_data.Coord(index + 1); }

const Vector3d operator*(double t, __CVec vector) {
  return Vector3d::Mulitply(t, vector);
}

} // namespace Geometry
} // namespace OcctCommon
