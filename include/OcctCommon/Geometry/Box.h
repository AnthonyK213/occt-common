#ifndef OCCTCOMMON_GEOMETRY_BOX_H
#define OCCTCOMMON_GEOMETRY_BOX_H

#include <OcctCommon/Geometry/Interval.h>
#include <OcctCommon/Geometry/Plane.h>

namespace OcctCommon {
namespace Geometry {

class Box {
private:
  Interval m_dx;
  Interval m_dy;
  Interval m_dz;
  Plane m_plane;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
