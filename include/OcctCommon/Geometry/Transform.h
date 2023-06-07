#ifndef OCCTCOMMON_GEOMETRY_TRANSFORM_H
#define OCCTCOMMON_GEOMETRY_TRANSFORM_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class Transform final : public _gpWrapper<gp_GTrsf> {
  GP_WRAPPER

public:
  Transform(double diagonalValue);
  Transform(__CTrsf transform);
  Transform(Transform &&transform) noexcept = default;
  Transform &operator=(__CTrsf transform) = default;
  Transform &operator=(Transform &&transform) noexcept = default;

public:
  static __CTrsf Identity() noexcept;
  static __CTrsf Unset() noexcept;
  static __CTrsf ZeroTransformation() noexcept;
  double Determinant() const;
  bool IsAffine() const;
  bool IsIdentity() const;
  bool IsLinear() const;
  bool IsRotation() const;
  bool IsValid() const;
  bool IsZero() const;
  bool IsZero4x4() const;
  bool IsZeroTransformation() const;
  double M00() const;
  double M01() const;
  double M02() const;
  double M03() const;
  double M10() const;
  double M11() const;
  double M12() const;
  double M13() const;
  double M20() const;
  double M21() const;
  double M22() const;
  double M23() const;
  double M30() const;
  double M31() const;
  double M32() const;
  double M33() const;
  int32_t RigidType() const;
  int32_t SimilarityType() const;

public:
  static Transform ChangeBasis(__CPln plane0, __CPln plane1);
  static Transform ChangeBasis(__CVec initialBasisX, __CVec initialBasisY,
                               __CVec initialBasisZ, __CVec finalBasisX,
                               __CVec finalBasisY, __CVec finalBasisZ);
  static Transform Diagonal(double d0, double d1, double d2);
  static Transform Diagonal(__CVec diagonal);
  static Transform Mirror(__CPln mirrorPlane);
  static Transform Mirror(__CPnt pointOnMirrorPlane,
                          __CVec normalToMirrorPlane);
  static Transform Multiply(__CTrsf a, __CTrsf b);
  static Transform PlanarProjection(__CPln plane);
  static Transform PlaneToPlane(__CPln plane0, __CPln plane1);
  static Transform ProjectAlong(__CPln plane, __CVec direction);
  static Transform Rotation(double angleRadians, __CPnt rotationCenter);
  static Transform Rotation(double sinAngle, double cosAngle,
                            __CVec rotationAxis, __CPnt rotationCenter);
  static Transform Rotation(double angleRadians, __CVec rotationAxis,
                            __CPnt rotationCenter);
  static Transform Rotation(__CVec startDirection, __CVec endDirection,
                            __CPnt rotationCenter);
  static Transform Rotation(__CVec x0, __CVec y0, __CVec z0, __CVec x1,
                            __CVec y1, __CVec z1);
  static Transform RotationZYX(double yaw, double pitch, double roll);
  static Transform RotationZYZ(double alpha, double beta, double gamma);
  static Transform Scale(__CPln plane, double xScaleFactor, double yScaleFactor,
                         double zScaleFactor);
  static Transform Scale(__CPnt anchor, double scaleFactor);
  static Transform Shear(__CPln plane, __CVec x, __CVec y, __CVec z);
  static Transform Translation(double x, double y, double z);
  static Transform Translation(__CVec motion);
  void Affineize();
  Transform Clone() const;
  int32_t CompareTo(__CTrsf other) const;
  bool DecomposeAffine(Transform &linear, Vector3d &translation) const;
  bool DecomposeAffine(Vector3d &translation, Transform &linear) const;
  bool DecomposeAffine(Vector3d &translation, Transform &rotation,
                       Transform &orthogonal, Vector3d &diagonal) const;
  int32_t DecomposeRigid(Vector3d &translation, Transform &rotation,
                         double tolerance) const;
  int32_t DecomposeSimilarity(Vector3d &translation, double &dilation,
                              Transform &rotation, double tolerance) const;
  bool DecomposeSymmetric(Transform &matrix, Vector3d &diagonal) const;
  bool Equals(__CTrsf other) const;
  bool GetEulerZYZ(double &alpha, double &beta, double &gamma) const;
  bool GetQuaternion(Quaternion &quaternion) const;
  bool GetYawPitchRoll(double &yaw, double &pitch, double &roll) const;
  bool IsRigid(double tolerance) const;
  bool IsSimilarity(double tolerance) const;
  bool IsZeroTransformation(double zeroTolerance) const;
  void Linearize();
  void Orthogonalize(double tolerance);
  std::array<double, 16> ToDoubleArray(bool rowDominant) const;
  std::array<float, 16> ToFloatArray(bool rowDominant) const;
  std::string ToString() const;
  BoundingBox TransformBoundingBox(__CBB bbox) const;
  template <typename T> std::vector<Point3d> TransformList(T first, T last);
  Transform Transpose() const;
  bool TryGetInverse(Transform &inverseTransform) const;

public:
  bool operator!=(__CTrsf other) const;
  bool operator==(__CTrsf other) const;
  Transform operator*(__CTrsf transform) const;
  Point3d operator*(__CPnt point) const;
  Vector3d operator*(__CVec vector) const;
  Transform &operator*=(__CTrsf transform);
};

} // namespace Geometry
} // namespace OcctCommon

#endif
