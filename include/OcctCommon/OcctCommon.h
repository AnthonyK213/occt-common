#ifndef OCCTCOMMON_GEOMETRY_H
#define OCCTCOMMON_GEOMETRY_H

#define NotImplemented() throw std::runtime_error("Not implemented");

#include <gp_Pln.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_XYZ.hxx>
#include <string>
#include <vector>

namespace OcctCommon {
namespace Geometry {

struct Arc;
struct Box;
struct Circle;
class Curve;
struct Line;
class Mesh;
class NurbsCurve;
struct Plane;
struct Point3d;
class PolyCurve;
class Polyline;
class PolylineCurve;
class Surface;
struct Transform;
struct Vector3d;

} // namespace Geometry

class OcctMath;

} // namespace OcctCommon

using __CPnt = const OcctCommon::Geometry::Point3d &;
using __CVec = const OcctCommon::Geometry::Vector3d &;
using __CPln = const OcctCommon::Geometry::Plane &;
using __CTrsf = const OcctCommon::Geometry::Transform &;
using __Math = OcctCommon::OcctMath;

const double OCCTCOMMON_UNSET_VALUE = -1.23432101234321e+308;

#endif
