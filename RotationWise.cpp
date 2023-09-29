// Compares points A and B and creates 4 lines from A and B to C and D
// Finds where they meet, that is where C/D are.
// Looks for points in a vector that are within epsilon of C or D

#include "Head.h"
#include "Points.h"
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  double epsilon = .0005; // how close it has to be

  if (argc > 1) {
    epsilon = stof(argv[2]);
  }

  vector<point> points = collect_points();

  for (int i = 0; i < points.size(); i++) {
    cout << "(" << points[i].x << ", " << points[i].y << "), ";
  }
  cout << endl;

  vector<triplet> eqTris;
  int pointc = points.size(); // number of points

  for (int i = 0; i < pointc - 2; i++) { // don't do last 2 bc tri = 3

    for (int j = i + 1; j < pointc; j++) {

      pair<point, point> pts = findEqPoints(points[i], points[j]);
      point pt1 = pts.first;
      point pt2 = pts.second;

      for (int k = j + 1; k < pointc; k++) {

        if ((comp_chords(points[k], pt1, epsilon)) ||
            (comp_chords(points[k], pt2, epsilon))) {
          triplet eqTriangle = {i, j, k};
          eqTris.push_back(eqTriangle);
        }
      }
    }
  }
  printTriangles(eqTris, points);

  return 0;
}
