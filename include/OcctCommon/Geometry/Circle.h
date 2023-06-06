#ifndef OCCTCOMMON_GEOMETRY_CIRCLE_H
#define OCCTCOMMON_GEOMETRY_CIRCLE_H

#include <OcctCommon/_decl.h>

namespace OcctCommon {
namespace Geometry {

class Circle final : public _gpWrapper<gp_Circ> {
  GP_BASE
};

} // namespace Geometry
} // namespace OcctCommon

#endif
