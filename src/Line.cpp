#include <OcctCommon/Geometry/Line.h>
#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Transform.h>
#include <OcctCommon/Geometry/Vector3d.h>
#include <OcctCommon/OcctMath.h>

namespace OcctCommon {
namespace Geometry {

Line::Line(double x0, double y0, double z0, double x1, double y1, double z1)
    : _gpWrapper(gp_Lin(gp_Pnt(x0, y0, z0), gp_Vec(x1 - x0, y1 - y0, z1 - z0))),
      m_end(x1, y1, z1) {}

Line::Line(__CPnt from, __CPnt to)
    : _gpWrapper(gp_Lin(from.Data(), (to - from).Data())), m_end(to.Data()) {}

} // namespace Geometry
} // namespace OcctCommon
