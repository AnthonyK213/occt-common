#ifndef OCCTCOMMON_GEOMETRY_TRANSFORM_H
#define OCCTCOMMON_GEOMETRY_TRANSFORM_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

/// @brief Represents the values in a 4x4 transform matrix.
class Transform final : public _gpWrapper<gp_GTrsf> {
  GP_WRAPPER

public:
  /// @brief Constructor.
  /// Initializes a new transform matrix with a specified value along the
  /// diagona.
  /// @param diagonalValue 
  Transform(double diagonalValue);

  /// @brief Copy constructor.
  /// @param transform
  Transform(__CTrsf transform);

  /// @brief Move constructor.
  /// @param transform
  Transform(Transform &&transform) noexcept = default;

  /// @brief Copy assignment.
  Transform &operator=(__CTrsf transform) = default;

  /// @brief Move assignment.
  Transform &operator=(Transform &&transform) noexcept = default;

public:
  /// @brief Gets a new identity transform matrix.
  /// An identity matrix defines no transformation.
  /// @return Identity transformation
  static __CTrsf Identity() noexcept;

  /// @brief Gets an transform filled with OcctMath::UnsetValue.
  /// @return Unset transformation
  static __CTrsf Unset() noexcept;

  /// @brief Zero transformation diagonal = (0, 0, 0, 1)
  /// @return Zero transformation
  static __CTrsf ZeroTransformation() noexcept;

  /// @brief The determinant of this 4x4 matrix. (FIXME: not really...)
  /// @return Determinant of the matrix.
  double Determinant() const;

  /// @brief Tests for an affine transformation.
  /// A transformation is affine if it is valid and its last row is [0, 0, 0,
  /// 1]. An affine transformation can be broken into a linear transformation
  /// and a translation.
  /// @return True if transformation is affine; otherwise, false.
  bool IsAffine() const;

  /// @brief Returns true if this Transform is the identity transform.
  /// @return True if this Transform is the identity transform; otherwise,
  /// false.
  bool IsIdentity() const;

  /// @brief Tests for a linear transformation.
  /// A transformation is affine if it is valid and its last row is [0, 0, 0,
  /// 1]. If in addition its last column is ( 0, 0, 0, 1)^T then it is linear.
  /// An affine transformation can be broken into a linear transformation and a
  /// translation.
  /// @return True if transformation is linear; otherwise, false.
  bool IsLinear() const;

  /// @brief Returns true if this Transform is a rotation.
  /// @return True if this Transform is a rotation; otherwise, false.
  bool IsRotation() const;

  /// @brief Gets a value indicating whether this Transform is a valid matrix.
  /// A valid transform matrix is not allowed to have any invalid numbers.
  /// @return True if transformation is valid; otherwise, false.
  bool IsValid() const;

  /// @brief True if matrix is Zero4x4, ZeroTransformation, or some other type
  /// of zero. The value xform[3][3] can be anything.
  /// @return
  bool IsZero() const;

  /// @brief True if all values are 0 (impossible for `gp_GTrsf`).
  /// @return
  bool IsZero4x4() const;

  /// @brief True if all values are 0, except for M33 which is 1.
  /// @return
  bool IsZeroTransformation() const;

  /// @brief 
  /// @return 
  double M00() const;

  /// @brief 
  /// @return 
  double M01() const;

  /// @brief 
  /// @return 
  double M02() const;

  /// @brief 
  /// @return 
  double M03() const;

  /// @brief 
  /// @return 
  double M10() const;

  /// @brief 
  /// @return 
  double M11() const;

  /// @brief 
  /// @return 
  double M12() const;

  /// @brief 
  /// @return 
  double M13() const;

  /// @brief 
  /// @return 
  double M20() const;

  /// @brief 
  /// @return 
  double M21() const;

  /// @brief 
  /// @return 
  double M22() const;

  /// @brief 
  /// @return 
  double M23() const;

  /// @brief 
  /// @return 
  double M30() const;

  /// @brief 
  /// @return 
  double M31() const;

  /// @brief 
  /// @return 
  double M32() const;

  /// @brief 
  /// @return 
  double M33() const;

  /// @brief Gets a value indicating whether or not the Transform is rigid.
  /// A rigid transformation can be broken into a proper rotation and a
  /// translation, while an isometry transformation could also include a
  /// reflection.
  /// @return
  int32_t RigidType() const;

  /// @brief Gets a value indicating whether the Transform maintains similarity.
  /// The easiest way to think of Similarity is that any circle,
  /// when transformed, remains a circle. Whereas a non-similarity Transform
  /// deforms circles into ellipses.
  /// @return
  int32_t SimilarityType() const;

public:
  /// @brief Computes a change of basis transformation.
  /// A basis change is essentially a remapping of geometry from one coordinate
  /// system to another.
  /// @param plane0 Coordinate system in which the geometry
  /// is currently described.
  /// @param plane1 Target coordinate system in which we want the geometry to be
  /// described.
  /// @return A transformation matrix which orients geometry from one coordinate
  /// system to another on success. Transform::Unset() on failure.
  static Transform ChangeBasis(__CPln plane0, __CPln plane1);

  /// @brief Computes a change of basis transformation.
  /// A basis change is essentially a remapping of geometry from one coordinate
  /// system to another.
  /// @param initialBasisX Can be any 3d basis.
  /// @param initialBasisY Can be any 3d basis.
  /// @param initialBasisZ Can be any 3d basis.
  /// @param finalBasisX Can be any 3d basis.
  /// @param finalBasisY Can be any 3d basis.
  /// @param finalBasisZ Can be any 3d basis.
  /// @return A transformation matrix which orients geometry from one coordinate
  /// system to another on success. Transform::Unset() on failure.
  static Transform ChangeBasis(__CVec initialBasisX, __CVec initialBasisY,
                               __CVec initialBasisZ, __CVec finalBasisX,
                               __CVec finalBasisY, __CVec finalBasisZ);

  /// @brief Constructs a new transformation with diagonal (d0, d1, d2, 1.0).
  /// @param d0 Transform::M00 value.
  /// @param d1 Transform::M00 value.
  /// @param d2 Transform::M00 value.
  /// @return A transformation with diagonal (d0, d1, d2, 1.0).
  static Transform Diagonal(double d0, double d1, double d2);

  /// @brief Constructs a new transformation with diagonal (d0, d1, d2, 1.0).
  /// @param diagonal The diagonal values.
  /// @return A transformation with diagonal (d0, d1, d2, 1.0).
  static Transform Diagonal(__CVec diagonal);

  /// @brief Constructs a new Mirror transformation.
  /// @param mirrorPlane Plane that defines the mirror orientation and position.
  /// @return A transformation matrix which mirrors geometry in a specified
  /// plane.
  static Transform Mirror(__CPln mirrorPlane);

  /// @brief
  /// @param pointOnMirrorPlane
  /// @param normalToMirrorPlane
  /// @return
  static Transform Mirror(__CPnt pointOnMirrorPlane,
                          __CVec normalToMirrorPlane);

  /// @brief
  /// @param a
  /// @param b
  /// @return
  static Transform Multiply(__CTrsf a, __CTrsf b);

  /// @brief
  /// @param plane
  /// @return
  static Transform PlanarProjection(__CPln plane);

  /// @brief
  /// @param plane0
  /// @param plane1
  /// @return
  static Transform PlaneToPlane(__CPln plane0, __CPln plane1);

  /// @brief
  /// @param plane
  /// @param direction
  /// @return
  static Transform ProjectAlong(__CPln plane, __CVec direction);

  /// @brief
  /// @param angleRadians
  /// @param rotationCenter
  /// @return
  static Transform Rotation(double angleRadians, __CPnt rotationCenter);

  /// @brief
  /// @param sinAngle
  /// @param cosAngle
  /// @param rotationAxis
  /// @param rotationCenter
  /// @return
  static Transform Rotation(double sinAngle, double cosAngle,
                            __CVec rotationAxis, __CPnt rotationCenter);

  /// @brief
  /// @param angleRadians
  /// @param rotationAxis
  /// @param rotationCenter
  /// @return
  static Transform Rotation(double angleRadians, __CVec rotationAxis,
                            __CPnt rotationCenter);

  /// @brief
  /// @param startDirection
  /// @param endDirection
  /// @param rotationCenter
  /// @return
  static Transform Rotation(__CVec startDirection, __CVec endDirection,
                            __CPnt rotationCenter);

  /// @brief
  /// @param x0
  /// @param y0
  /// @param z0
  /// @param x1
  /// @param y1
  /// @param z1
  /// @return
  static Transform Rotation(__CVec x0, __CVec y0, __CVec z0, __CVec x1,
                            __CVec y1, __CVec z1);

  /// @brief
  /// @param yaw
  /// @param pitch
  /// @param roll
  /// @return
  static Transform RotationZYX(double yaw, double pitch, double roll);

  /// @brief
  /// @param alpha
  /// @param beta
  /// @param gamma
  /// @return
  static Transform RotationZYZ(double alpha, double beta, double gamma);

  /// @brief
  /// @param plane
  /// @param xScaleFactor
  /// @param yScaleFactor
  /// @param zScaleFactor
  /// @return
  static Transform Scale(__CPln plane, double xScaleFactor, double yScaleFactor,
                         double zScaleFactor);

  /// @brief
  /// @param anchor
  /// @param scaleFactor
  /// @return
  static Transform Scale(__CPnt anchor, double scaleFactor);

  /// @brief
  /// @param plane
  /// @param x
  /// @param y
  /// @param z
  /// @return
  static Transform Shear(__CPln plane, __CVec x, __CVec y, __CVec z);

  /// @brief
  /// @param x
  /// @param y
  /// @param z
  /// @return
  static Transform Translation(double x, double y, double z);

  /// @brief
  /// @param motion
  /// @return
  static Transform Translation(__CVec motion);

  /// @brief
  void Affineize();

  /// @brief
  /// @return
  Transform Clone() const;

  /// @brief
  /// @param other
  /// @return
  int32_t CompareTo(__CTrsf other) const;

  /// @brief
  /// @param linear
  /// @param translation
  /// @return
  bool DecomposeAffine(Transform &linear, Vector3d &translation) const;

  /// @brief
  /// @param translation
  /// @param linear
  /// @return
  bool DecomposeAffine(Vector3d &translation, Transform &linear) const;

  /// @brief
  /// @param translation
  /// @param rotation
  /// @param orthogonal
  /// @param diagonal
  /// @return
  bool DecomposeAffine(Vector3d &translation, Transform &rotation,
                       Transform &orthogonal, Vector3d &diagonal) const;

  /// @brief
  /// @param translation
  /// @param rotation
  /// @param tolerance
  /// @return
  int32_t DecomposeRigid(Vector3d &translation, Transform &rotation,
                         double tolerance) const;

  /// @brief
  /// @param translation
  /// @param dilation
  /// @param rotation
  /// @param tolerance
  /// @return
  int32_t DecomposeSimilarity(Vector3d &translation, double &dilation,
                              Transform &rotation, double tolerance) const;

  /// @brief
  /// @param matrix
  /// @param diagonal
  /// @return
  bool DecomposeSymmetric(Transform &matrix, Vector3d &diagonal) const;

  /// @brief
  /// @param other
  /// @return
  bool Equals(__CTrsf other) const;

  /// @brief
  /// @param alpha
  /// @param beta
  /// @param gamma
  /// @return
  bool GetEulerZYZ(double &alpha, double &beta, double &gamma) const;

  /// @brief
  /// @param quaternion
  /// @return
  bool GetQuaternion(Quaternion &quaternion) const;

  /// @brief
  /// @param yaw
  /// @param pitch
  /// @param roll
  /// @return
  bool GetYawPitchRoll(double &yaw, double &pitch, double &roll) const;

  /// @brief
  /// @param tolerance
  /// @return
  bool IsRigid(double tolerance) const;

  /// @brief
  /// @param tolerance
  /// @return
  bool IsSimilarity(double tolerance) const;

  /// @brief
  /// @param zeroTolerance
  /// @return
  bool IsZeroTransformation(double zeroTolerance) const;

  /// @brief
  void Linearize();

  /// @brief
  /// @param tolerance
  void Orthogonalize(double tolerance);

  /// @brief
  /// @param rowDominant
  /// @return
  std::array<double, 16> ToDoubleArray(bool rowDominant) const;

  /// @brief
  /// @param rowDominant
  /// @return
  std::array<float, 16> ToFloatArray(bool rowDominant) const;

  /// @brief
  /// @return
  std::string ToString() const;

  /// @brief
  /// @param bbox
  /// @return
  BoundingBox TransformBoundingBox(__CBB bbox) const;

  /// @brief
  template <typename T> std::vector<Point3d> TransformList(T first, T last);

  /// @brief
  /// @return
  Transform Transpose() const;

  /// @brief
  /// @param inverseTransform
  /// @return
  bool TryGetInverse(Transform &inverseTransform) const;

public:
  /// @brief
  /// @param other
  /// @return
  bool operator!=(__CTrsf other) const;

  /// @brief
  /// @param other
  /// @return
  bool operator==(__CTrsf other) const;

  /// @brief
  /// @param transform
  /// @return
  const Transform operator*(__CTrsf transform) const;

  /// @brief
  /// @param point
  /// @return
  const Point3d operator*(__CPnt point) const;

  /// @brief
  /// @param vector
  /// @return
  const Vector3d operator*(__CVec vector) const;

  /// @brief
  /// @param transform
  /// @return
  Transform &operator*=(__CTrsf transform);
};

} // namespace Geometry
} // namespace OcctCommon

#endif
