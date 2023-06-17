#include <OcctCommon/Geometry/Circle.h>
#include <OcctCommon/Geometry/Plane.h>
#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Vector3d.h>

namespace OcctCommon {
namespace Geometry {

// TODO
Circle::Circle(__CArc arc) {}

Circle::Circle(double radius) {
  m_data = gp_Circ(gp_Ax2(gp::Origin(), gp::DZ(), gp::DX()), radius);
}

Circle::Circle(__CPln plane, double radius) {
  gp_Ax2 ax2{plane.Data().Location(), plane.Data().Axis().Direction(),
             plane.Data().XAxis().Direction()};
  m_data = gp_Circ(ax2, radius);
}

Circle::Circle(__CPln plane, __CPnt center, double radius) {
  gp_Ax2 ax2{center.Data(), plane.Data().Axis().Direction(),
             plane.Data().XAxis().Direction()};
  m_data = gp_Circ(ax2, radius);
}

Circle::Circle(__CPnt center, double radius) {
  gp_Ax2 ax2{center.Data(), gp::DZ(), gp::DX()};
  m_data = gp_Circ(ax2, radius);
}

Circle::Circle(__CPnt point1, __CPnt point2, __CPnt point3) {
  m_data = GC_MakeCircle(point1.Data(), point2.Data(), point3.Data())
               .Value()
               ->Circ();
}

// TODO
Circle::Circle(__CPnt startPoint, __CVec tangentAtP, __CPnt pointOnCircle) {}

} // namespace Geometry
} // namespace OcctCommon
