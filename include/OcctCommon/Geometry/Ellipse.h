#ifndef OCCTCOMMON_GEOMETRY_ELLIPSE_H
#define OCCTCOMMON_GEOMETRY_ELLIPSE_H

#include <OcctCommon/pch.h>

namespace OcctCommon {
namespace Geometry {

class Ellipse final : public GpWrapper<gp_Elips> {
  GP_WRAPPER
};

} // namespace Geometry
} // namespace OcctCommon

#endif
