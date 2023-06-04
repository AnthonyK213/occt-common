#include <OcctCommon/Geometry/Point3d.h>
#include <gtest/gtest.h>

using namespace OcctCommon::Geometry;

TEST(GeometryTests, point3d_add) {
  Point3d pt1(1, 2, 3);
  Point3d pt2(-1, -2, -3);
  Point3d sum = Point3d::Add(pt1, pt2);
  // ASSERT_EQ(sum, Point3d::Origin());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
