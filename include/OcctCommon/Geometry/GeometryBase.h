#ifndef OCCTCOMMON_GEOMETRY_GEOMETRYBASE_H
#define OCCTCOMMON_GEOMETRY_GEOMETRYBASE_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class GeometryBase {
public:
  virtual bool HasBrepForm() = 0;
  virtual bool IsDeformable() = 0;
  virtual bool IsValid() = 0;
  virtual int ObjectType() = 0;

public:
  virtual Handle(GeometryBase) Duplicate() = 0;
  virtual Handle(GeometryBase) DuplicateShallow() = 0;
  virtual BoundingBox GetBoundingBox(__CPln plane) = 0;
  virtual BoundingBox GetBouddingBox(bool accurate) = 0;
  virtual BoundingBox GetBoundingBox(__CTrsf xform) = 0;
  virtual bool Rotate(double angleRadiance, __CVec rotationAxis,
                      __CPnt rotationCenter) = 0;
  virtual bool Scale(double scaleFactor) = 0;
  virtual bool Transform(__CTrsf xform) = 0;
  virtual bool Translate(double x, double y, double z) = 0;
  virtual bool Translate(__CVec translationVector) = 0;

private:
  Handle(Geom_Geometry) m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
