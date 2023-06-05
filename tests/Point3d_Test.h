#pragma once

#include <OcctCommon/Geometry/Point3d.h>
#include <gtest/gtest.h>

using namespace OcctCommon::Geometry;

TEST(GeometryTests, point3d_eq) {
  Point3d pt1(1, 2, 3);
  Point3d pt2(1, 2, 3);
  EXPECT_TRUE(pt1 == pt2);
}

TEST(GeometryTests, point3d_mut) {
  Point3d pt(1, 2, 3);
  gp_Pnt &pnt = pt.DataMut();
  pnt.SetX(10);
  EXPECT_EQ(pt.X(), 10);
}

TEST(GeometryTests, point3d_add) {
  Point3d pt1(1, 2, 3);
  Point3d pt2(-1, -2, -3);
  EXPECT_TRUE(Point3d::Add(pt1, pt2) == Point3d::Origin());
  EXPECT_TRUE(pt1 + pt2 == Point3d::Origin());
}