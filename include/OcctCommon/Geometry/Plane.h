#ifndef OCCTCOMMON_GEOMETRY_PLANE_H
#define OCCTCOMMON_GEOMETRY_PLANE_H

#include <OcctCommon/OcctCommon.h>

namespace OcctCommon {
namespace Geometry {

struct Plane {
private:
  gp_Pln m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
