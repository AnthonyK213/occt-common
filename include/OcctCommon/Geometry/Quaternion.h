#ifndef OCCTCOMMON_GEOMETRY_QUATERNION_H
#define OCCTCOMMON_GEOMETRY_QUATERNION_H

#include <OcctCommon/pch.h>

namespace OcctCommon {
namespace Geometry {

class Quaternion : public GpWrapper<gp_Quaternion> {
  GP_WRAPPER
};

} // namespace Geometry
} // namespace OcctCommon

#endif
