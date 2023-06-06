#ifndef OCCTCOMMON_GEOMETRY_QUATERNION_H
#define OCCTCOMMON_GEOMETRY_QUATERNION_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class Quaternion : public _gpWrapper<gp_Quaternion> {
  GP_BASE
};

} // namespace Geometry
} // namespace OcctCommon

#endif
