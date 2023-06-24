#ifndef OCCTCOMMON_GEOMETRY_ELLIPSE_H
#define OCCTCOMMON_GEOMETRY_ELLIPSE_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class Ellipse final : public _gpWrapper<gp_Elips> {
  GP_WRAPPER
};

} // namespace Geometry
} // namespace OcctCommon

#endif
