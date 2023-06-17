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
  virtual int ObjectType() const = 0;

public:
  /// @brief
  /// @return
  virtual Rc(GeometryBase) Duplicate() const = 0;

  /// @brief
  /// @return
  virtual Rc(GeometryBase) DuplicateShallow() const = 0;

  /// @brief
  /// @param plane
  /// @return
  virtual BoundingBox GetBoundingBox(__CPln plane) const = 0;

  /// @brief
  /// @param accurate
  /// @return
  virtual BoundingBox GetBouddingBox(bool accurate) const = 0;

  /// @brief
  /// @param xform
  /// @return
  virtual BoundingBox GetBoundingBox(__CTrsf xform) const = 0;

  /// @brief
  /// @param angleRadians
  /// @param rotationAxis
  /// @param rotationCenter
  /// @return
  virtual bool Rotate(double angleRadians, __CVec rotationAxis,
                      __CPnt rotationCenter) = 0;

  /// @brief
  /// @param scaleFactor
  /// @return
  virtual bool Scale(double scaleFactor) = 0;

  /// @brief
  /// @param xform
  /// @return
  virtual bool Transform(__CTrsf xform) = 0;

  /// @brief
  /// @param x
  /// @param y
  /// @param z
  /// @return
  virtual bool Translate(double x, double y, double z) = 0;

  /// @brief
  /// @param translationVector
  /// @return
  virtual bool Translate(__CVec translationVector) = 0;

protected:
  Handle(Geom_Geometry) m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
