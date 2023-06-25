#ifndef OCCTCOMMON_GEOMETRY_BOUNDINGBOX_H
#define OCCTCOMMON_GEOMETRY_BOUNDINGBOX_H

#include <OcctCommon/Geometry/Point3d.h>

namespace OcctCommon {
namespace Geometry {

class BoundingBox {
private:
  Point3d m_max;
  Point3d m_min;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
