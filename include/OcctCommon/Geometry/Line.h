#ifndef OCCTCOMMON_GEOMETRY_LINE_H
#define OCCTCOMMON_GEOMETRY_LINE_H

#include <OcctCommon/OcctCommon.h>

namespace OcctCommon {
namespace Geometry {

struct Line {
private:
  gp_Lin m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
