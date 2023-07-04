#include <OcctCommon/Geometry/Plane.h>
#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Transform.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Vector3d::Vector3d(double x, double y, double z) : _gpWrapper({x, y, z}) {}

Vector3d::Vector3d(C_Pnt point) : _gpWrapper(point.Data().Coord()) {}

Vector3d::Vector3d(C_Vec vector) : _gpWrapper(vector.m_data) {}

bool Vector3d::IsUnitVector() const {
  return std::abs(m_data.Magnitude() - 1.0) <= _Math::SqrtEpsilon;
}

bool Vector3d::IsValid() const {
  if (_Math::IsValidDouble(X()) && _Math::IsValidDouble(Y()))
    return _Math::IsValidDouble(Z());
  return false;
}

bool Vector3d::IsZero() const {
  if (X() == 0.0 && Y() == 0.0)
    return Z() == 0.0;
  return false;
}

double Vector3d::Length() const { return m_data.Magnitude(); }

double Vector3d::SquareLength() const { return m_data.SquareMagnitude(); }

C_Vec Vector3d::Unset() {
  static Vector3d Vector3d_Unset(_Math::UnsetValue, _Math::UnsetValue,
                                 _Math::UnsetValue);
  return Vector3d_Unset;
}

double Vector3d::X() const { return m_data.X(); }

double Vector3d::Y() const { return m_data.Y(); }

double Vector3d::Z() const { return m_data.Z(); }

C_Vec Vector3d::XAxis() {
  static Vector3d Vector3d_XAxis(gp::DX());
  return Vector3d_XAxis;
}

C_Vec Vector3d::YAxis() {
  static Vector3d Vector3d_YAxis(gp::DY());
  return Vector3d_YAxis;
}

C_Vec Vector3d::ZAxis() {
  static Vector3d Vector3d_ZAxis(gp::DZ());
  return Vector3d_ZAxis;
}

C_Vec Vector3d::Zero() {
  static Vector3d Vector3d_Zero(gp::Origin());
  return Vector3d_Zero;
}

Vector3d Vector3d::Add(C_Vec vector1, C_Vec vector2) {
  return Vector3d(vector1.Data() + vector2.Data());
}

bool Vector3d::AreOrthogonal(C_Vec x, C_Vec y, C_Vec z) {
  if (x.IsZero() || y.IsZero() || z.IsZero())
    return false;
  return Vector3d(x.Data().CrossCrossed(y.Data(), z.Data())).IsZero();
}

bool Vector3d::AreOrithonormal(C_Vec x, C_Vec y, C_Vec z) {
  if (!Vector3d::AreOrthogonal(x, y, z))
    return false;
  return x.IsUnitVector() && y.IsUnitVector() && z.IsUnitVector();
}

bool Vector3d::AreRighthanded(C_Vec x, C_Vec y, C_Vec z) {
  if (!AreOrithonormal(x, y, z))
    return false;
  return x.Data().DotCross(y.Data(), z.Data()) > 0.0;
}

Vector3d Vector3d::CrossProduct(C_Vec a, C_Vec b) {
  return Vector3d(a.Data().Crossed(b.Data()));
}

Vector3d Vector3d::Divide(C_Vec vector, double t) {
  return Vector3d(vector.Data() / t);
}

Vector3d Vector3d::Mulitply(C_Vec vector, double t) {
  return Vector3d(vector.Data() * t);
}

Vector3d Vector3d::Mulitply(double t, C_Vec vector) {
  return Vector3d(vector.Data() * t);
}

double Vector3d::Mulitply(C_Vec vector1, C_Vec vector2) {
  return vector1.Data().Dot(vector2.Data());
}

Vector3d Vector3d::Negate(C_Vec vector) {
  return Vector3d(-vector.X(), -vector.Y(), -vector.Z());
}

Vector3d Vector3d::Subtract(C_Vec vector1, C_Vec vector2) {
  return Vector3d(vector1.Data() - vector2.Data());
}

double Vector3d::VectorAngle(C_Vec a, C_Vec b, C_Pln plane) {
  return VectorAngle(a, b, plane.Normal());
}

double Vector3d::VectorAngle(C_Vec a, C_Vec b, C_Vec vNormal) {
  return a.Data().AngleWithRef(b.Data(), vNormal.Data());
}

double Vector3d::VectorAngle(C_Vec a, C_Vec b) {
  return a.Data().Angle(b.Data());
}

int Vector3d::CompareTo(C_Vec other) const {
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

bool Vector3d::EpsilonEquals(C_Vec other, double epsilon) const {
  if (_Math::EpsilonEquals(X(), other.X(), epsilon) &&
      _Math::EpsilonEquals(Y(), other.Y(), epsilon))
    return _Math::EpsilonEquals(Z(), other.Z(), epsilon);
  return false;
}

bool Vector3d::Equals(C_Vec vector) const { return *this == vector; }

// FIXME: VectorWithNullMagnitude exception
int Vector3d::IsParallelTo(C_Vec other, double angleTolerance) const {
  if (!m_data.IsParallel(other.m_data, angleTolerance))
    return 0;
  if (m_data * other.m_data > 0)
    return 1;
  return -1;
}

int Vector3d::IsParallelTo(C_Vec other) const {
  return IsParallelTo(other, _Math::DefaultAngleTolerance);
}

bool Vector3d::IsPerpendicularTo(C_Vec other, double angleTolerance) const {
  return m_data.IsNormal(other.m_data, angleTolerance);
}

bool Vector3d::IsPerpendicularTo(C_Vec other) const {
  return IsPerpendicularTo(other, _Math::DefaultAngleTolerance);
}

bool Vector3d::IsTiny(double tolerance) const {
  if (std::abs(X()) <= tolerance && std::abs(Y()) <= tolerance)
    return std::abs(Z()) <= tolerance;
  return false;
}

bool Vector3d::IsTiny() const { return Vector3d::IsTiny(_Math::ZeroTolerance); }

bool Vector3d::PerpendicularTo(C_Vec other) {
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

bool Vector3d::Rotate(double angleRadians, C_Vec rotationAxis) {
  if (_Math::IsValidDouble(angleRadians) && rotationAxis.IsValid()) {
    gp_Ax1 axis(gp::Origin(), rotationAxis.Data().XYZ());
    m_data.Rotate(axis, angleRadians);
    return true;
  }
  return false;
}

void Vector3d::Transform(C_Trsf transformation) {
  m_data.Transform(transformation.Data().Trsf());
}

bool Vector3d::Unitize() {
  if (IsValid() && !IsZero()) {
    m_data.Normalize();
    return true;
  }
  return false;
}

bool Vector3d::operator!=(C_Vec other) const {
  if (X() == other.X() && Y() == other.Y())
    return Z() != other.Z();
  return true;
}

bool Vector3d::operator<(C_Vec other) const { return CompareTo(other) < 0; }

bool Vector3d::operator<=(C_Vec other) const { return CompareTo(other) <= 0; }

bool Vector3d::operator==(C_Vec other) const {
  if (X() == other.X() && Y() == other.Y())
    return Z() == other.Z();
  return false;
}

bool Vector3d::operator>(C_Vec other) const { return CompareTo(other) > 0; }

bool Vector3d::operator>=(C_Vec other) const { return CompareTo(other) >= 0; }

const double Vector3d::operator*(C_Vec vector) const {
  return Vector3d::Mulitply(*this, vector);
}

const Vector3d Vector3d::operator*(double t) const {
  return Vector3d::Mulitply(*this, t);
}

const Vector3d Vector3d::operator-() const { return Vector3d::Negate(*this); }

const Vector3d Vector3d::operator-(C_Vec vector) const {
  return Vector3d::Subtract(*this, vector);
}

const Vector3d Vector3d::operator/(double t) const {
  return Vector3d::Divide(*this, t);
}

const Vector3d Vector3d::operator+(C_Vec vector) const {
  return Vector3d::Add(*this, vector);
}

Vector3d &Vector3d::operator+=(C_Vec vector) {
  m_data += vector.Data();
  return *this;
}

Vector3d &Vector3d::operator*=(double t) {
  m_data *= t;
  return *this;
}

Vector3d &Vector3d::operator-=(C_Vec vector) {
  m_data -= vector.Data();
  return *this;
}

Vector3d &Vector3d::operator/=(double t) {
  m_data /= t;
  return *this;
}

double Vector3d::operator[](int index) { return m_data.Coord(index + 1); }

const Vector3d operator*(double t, C_Vec vector) {
  return Vector3d::Mulitply(t, vector);
}

} // namespace Geometry
} // namespace OcctCommon
