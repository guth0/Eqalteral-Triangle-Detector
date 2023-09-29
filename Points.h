#include <cmath>
#include <iostream>
using namespace std;

point midpoint(const point A, const point B) {
  point mid;
  mid.x = (A.x + B.x) / 2;
  mid.y = (A.y + B.y) / 2;
  return mid;
}

point rotate(const point p) {
  point rotated;
  rotated.x = (p.x * cos(M_PI / 3)) - (p.y * sin(M_PI / 3));
  rotated.y = (p.x * sin(M_PI / 3)) + (p.y * cos(M_PI / 3));
  return rotated;
}

pair<point, point> findEqPoints(const point A, const point B) {
  point mid = midpoint(A, B);

  point AB = {B.x - A.x, B.y - A.y};
  point rotated = rotate(AB);
  point C, D;
  float dx = mid.x - rotated.x;
  float dy = mid.y - rotated.y;

  C.x = mid.x + dx;
  C.y = mid.y + dy;
  D.x = mid.x - dx;
  D.y = mid.y - dy;

  return make_pair(C, D);
}

bool comp_chords(point a, point b, double epsilon) {
  return (fabs(a.x - b.x) <= epsilon && fabs(a.y - b.y) <= epsilon);
}