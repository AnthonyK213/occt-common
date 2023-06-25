#include <OcctCommon/Geometry/Circle.h>
#include <OcctCommon/Geometry/Plane.h>
#include <OcctCommon/Geometry/Point3d.h>
#include <OcctCommon/Geometry/Vector3d.h>

namespace OcctCommon {
namespace Geometry {

// TODO
Circle::Circle(C_Arc arc) {}

Circle::Circle(double radius) {
  m_data = gp_Circ(gp_Ax2(gp::Origin(), gp::DZ(), gp::DX()), radius);
}

Circle::Circle(C_Pln plane, double radius) {
  gp_Ax2 ax2{plane.Data().Location(), plane.Data().Axis().Direction(),
             plane.Data().XAxis().Direction()};
  m_data = gp_Circ(ax2, radius);
}

Circle::Circle(C_Pln plane, C_Pnt center, double radius) {
  gp_Ax2 ax2{center.Data(), plane.Data().Axis().Direction(),
             plane.Data().XAxis().Direction()};
  m_data = gp_Circ(ax2, radius);
}

Circle::Circle(C_Pnt center, double radius) {
  gp_Ax2 ax2{center.Data(), gp::DZ(), gp::DX()};
  m_data = gp_Circ(ax2, radius);
}

Circle::Circle(C_Pnt point1, C_Pnt point2, C_Pnt point3) {
  m_data = GC_MakeCircle(point1.Data(), point2.Data(), point3.Data())
               .Value()
               ->Circ();
}

// TODO
Circle::Circle(C_Pnt startPoint, C_Vec tangentAtP, C_Pnt pointOnCircle) {}

} // namespace Geometry
} // namespace OcctCommon
