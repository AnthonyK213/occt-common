#ifndef OCCTCOMMON_GEOMETRY_TRANSFORM_H
#define OCCTCOMMON_GEOMETRY_TRANSFORM_H

#include <OcctCommon/OcctCommon.h>

namespace OcctCommon {
namespace Geometry {

struct Transform {
private:
  gp_Trsf m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
