#ifndef OCCTCOMMON_GEOMETRY_TRANSFORM_H
#define OCCTCOMMON_GEOMETRY_TRANSFORM_H

#include <OcctCommon/OcctCommon.h>

namespace OcctCommon {
namespace Geometry {

class Transform {
public:
  const gp_Trsf &Data() const;
  gp_Trsf &Data();

private:
  gp_Trsf m_data;
};

} // namespace Geometry
} // namespace OcctCommon

#endif
