#ifndef OCCTCOMMON_GEOMETRY_GEOMETRYBASE_H
#define OCCTCOMMON_GEOMETRY_GEOMETRYBASE_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class GeometryBase {
public:
  /// @brief
  /// @return
  virtual bool HasBrepForm() const = 0;

  /// @brief
  /// @return
  virtual bool IsDeformable() const = 0;

  /// @brief
  /// @return
  virtual bool IsValid() const = 0;

  /// @brief
  /// @return
  virtual uint32_t ObjectType() const = 0;

public:
  /// @brief
  /// @return
  virtual GeometryBase *Duplicate() const = 0;

  /// @brief
  /// @return
  virtual GeometryBase *DuplicateShallow() const = 0;

  /// @brief
  /// @param plane
  /// @return
  virtual BoundingBox GetBoundingBox(C_Pln plane) const = 0;

  /// @brief
  /// @param accurate
  /// @return
  virtual BoundingBox GetBoundingBox(bool accurate) const = 0;

  /// @brief
  /// @param xform
  /// @return
  virtual BoundingBox GetBoundingBox(C_Trsf xform) const = 0;

  /// @brief
  /// @param angleRadians
  /// @param rotationAxis
  /// @param rotationCenter
  /// @return
  virtual bool Rotate(double angleRadians, C_Vec rotationAxis,
                      C_Pnt rotationCenter) = 0;

  /// @brief
  /// @param scaleFactor
  /// @return
  virtual bool Scale(double scaleFactor) = 0;

  /// @brief
  /// @param xform
  /// @return
  virtual bool Transform(C_Trsf xform) = 0;

  /// @brief
  /// @param x
  /// @param y
  /// @param z
  /// @return
  virtual bool Translate(double x, double y, double z) = 0;

  /// @brief
  /// @param translationVector
  /// @return
  virtual bool Translate(C_Vec translationVector) = 0;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
