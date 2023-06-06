#ifndef OCCTCOMMON_GEOMETRY_GEOMETRYBASE_H
#define OCCTCOMMON_GEOMETRY_GEOMETRYBASE_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class GeometryBase {
public:
  virtual bool HasBrepForm() const = 0;
  virtual bool IsDeformable() const = 0;
  virtual bool IsValid() const = 0;
  virtual int ObjectType() const = 0;

public:
  virtual Handle(GeometryBase) Duplicate() const = 0;
  virtual Handle(GeometryBase) DuplicateShallow() const = 0;
  virtual BoundingBox GetBoundingBox(__CPln plane) const = 0;
  virtual BoundingBox GetBouddingBox(bool accurate) const = 0;
  virtual BoundingBox GetBoundingBox(__CTrsf xform) const = 0;
  virtual bool Rotate(double angleRadiance, __CVec rotationAxis,
                      __CPnt rotationCenter) = 0;
  virtual bool Scale(double scaleFactor) = 0;
  virtual bool Transform(__CTrsf xform) = 0;
  virtual bool Translate(double x, double y, double z) = 0;
  virtual bool Translate(__CVec translationVector) = 0;

protected:
  Handle(Geom_Geometry) m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
