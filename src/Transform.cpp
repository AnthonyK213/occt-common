#include <OcctCommon/Geometry/Transform.h>

namespace OcctCommon {
namespace Geometry {

const gp_Trsf &Transform::Data() const { return m_data; }

gp_Trsf &Transform::DataMut() { return m_data; }

} // namespace Geometry
} // namespace OcctCommon
