#include <OcctCommon/OcctCommon.h>
#include <gtest/gtest.h>

using namespace OcctCommon::Geometry;

TEST(GeometryTests, coord_eq) {
  Point3d pt1(1, 2, 3);
  Point3d pt2(1, 2, 3);
  EXPECT_TRUE(pt1 == pt2);
}

TEST(GeometryTests, coord_add) {
  Point3d pt1(1, 2, 3);
  Point3d pt2(-1, -2, -3);
  Vector3d vec1(-1, -2, -3);
  EXPECT_TRUE(Point3d::Add(pt1, pt2) == Point3d::Origin());
  EXPECT_TRUE(pt1 + pt2 == Point3d::Origin());
  EXPECT_TRUE(pt1 + vec1 == Point3d::Origin());
}

TEST(GeometryTests, vector_calc) {
  Vector3d vec1(-2, 1, 3);
  Vector3d vec2(0, 1, 4);
  EXPECT_TRUE(Vector3d::CrossProduct(vec1, vec2) == Vector3d(1, 8, -2));
  EXPECT_EQ(Vector3d::Mulitply(vec1, vec2), 13);
  Vector3d vec3 = vec2;
  vec3.Unitize();
  EXPECT_FALSE(vec2.IsUnitVector());
  EXPECT_TRUE(vec3.IsUnitVector());
}

TEST(GeometryTests, vector_relation) {
  Vector3d vec1(-2, 1, 3);
  Vector3d vec2(0, 1, 4);
  EXPECT_TRUE(vec1.PerpendicularTo(vec2));
  EXPECT_TRUE(vec1.IsPerpendicularTo(vec2));
}

TEST(GeometryTests, plane_validation) {
  Vector3d vec1(0, 0, 1);
  Vector3d vec2(0, 0, 10);
  Vector3d vec3(0, 7, 0);
  Plane plane1(Point3d::Origin(), vec1, vec2);
  Plane plane2(Point3d::Origin(), vec1, vec3);
  EXPECT_FALSE(plane1.IsValid());
  EXPECT_TRUE(plane2.IsValid());
}

TEST(GeometryTests, transform_test) {
  auto tf1 = Transform::Unset();
  auto tf2 = Transform::Unset();
}

TEST(GeometryTests, transform_plane2plane) {
  Plane pln1{Point3d(3, 1, 4), Vector3d(1, 5, 9), Vector3d(2, 6, 5)};
  Plane pln2{Point3d(3, 5, 8), Vector3d(9, 7, 9), Vector3d(3, 2, 3)};
  Transform tf = Transform::PlaneToPlane(pln1, pln2);
}

TEST(GeometryTests, line_closestpoint) {
  Line line{0, 0, 0, 1, 1, 0};
  EXPECT_FLOAT_EQ(line.ClosestParameter({0, 0, 0}), 0);
  EXPECT_FLOAT_EQ(line.ClosestParameter({0, 1, 0}), 0.5);
  EXPECT_FLOAT_EQ(line.ClosestParameter({0, -1, 0}), -0.5);
  EXPECT_FLOAT_EQ(line.ClosestParameter({0, 3, 0}), 1.5);
}

TEST(GeometryTests, interval_test) {
  Interval a{0, 1};
  Interval b{-10, 0.5};
  Interval c = a;
  c.Reverse();
  EXPECT_TRUE(Interval::FromIntersection(a, b) == Interval(0, 0.5));
  EXPECT_TRUE(Interval::FromUnion(a, b) == Interval(-10, 1));
  EXPECT_TRUE(c == Interval(-1, 0));
}

TEST(GeometryTests, curve_interpolate_test) {
  Vec_<Point3d> points = {
      {0, 0, 0},
      {1, 1, 0},
      {2, 0, 0},
      {3, 3, 0},
  };
  Curve *curve = CurveUtil::CreateInterpolatedCurve(points, 3);
  if (curve) {
    EXPECT_TRUE(curve->PointAtStart() == Point3d(0, 0, 0));
    EXPECT_TRUE(curve->PointAtEnd() == Point3d(3, 3, 0));
    EXPECT_EQ(curve->SpanCount(), 3);
    EXPECT_TRUE(curve->IsPlanar());
    EXPECT_TRUE(curve->IsInPlane(Plane::WorldXY()));
    delete curve;
  }
}

TEST(GeometryTests, curve_join_test) {
  Vec_<Point3d> points1 = {
      {0, 0, 0},
      {1, 1, 0},
      {2, 0, 0},
      {3, 3, 0},
  };
  Curve *curve1 = CurveUtil::CreateInterpolatedCurve(points1, 3);
  Vec_<Point3d> points2 = {
      {3, 3, 0},
      {4, 6, 0},
      {5, 3, 0},
      {0, 1, 0},
  };
  Curve *curve2 = CurveUtil::CreateInterpolatedCurve(points2, 3);
  Vec_<Curve*> curves{curve1, curve2};
  auto result = CurveUtil::JoinCurves(curves, 0.001, true);
  EXPECT_EQ(result.size(), 1);
  EXPECT_TRUE(result[0]->PointAtStart() == Point3d(0, 0, 0));
  EXPECT_TRUE(result[0]->PointAtEnd() == Point3d(0, 1, 0));
  EXPECT_EQ(result[0]->SpanCount(), 6);
  EXPECT_EQ(result[0]->Degree(), 3);
  delete curve1;
  delete curve2;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
