#ifndef OCCTCOMMON_GEOMETRY_ARC_H
#define OCCTCOMMON_GEOMETRY_ARC_H

#include <OcctCommon/Geometry/Circle.h>
#include <OcctCommon/pch.h>

namespace OcctCommon {
namespace Geometry {

class Arc final {
private:
  Circle m_circ;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
