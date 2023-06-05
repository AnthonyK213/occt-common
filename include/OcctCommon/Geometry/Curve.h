#ifndef OCCTCOMMON_GEOMETRY_CURVE_H
#define OCCTCOMMON_GEOMETRY_CURVE_H

#include <OcctCommon/Geometry/GeometryBase.h>
#include <OcctCommon/OcctCommon.h>

namespace OcctCommon {
namespace Geometry {

class Curve : public GeometryBase {
private:
  Handle(Geom_Curve) m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
