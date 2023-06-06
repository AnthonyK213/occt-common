#ifndef OCCTCOMMON_GEOMETRY_QUATERNION_H
#define OCCTCOMMON_GEOMETRY_QUATERNION_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class Quaternion {
private:
  gp_Quaternion m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
