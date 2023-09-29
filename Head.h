#include <cmath>
#include <iostream>
using namespace std;

struct point {
  float x, y;
};

struct triplet {
  int first, second, third;
};

float distance(point point1, point point2) {
  float a = point1.x - point2.x;
  float b = point1.y - point2.y;
  float c = {sqrt(pow(a, 2) + pow(b, 2))};
  c = ceil(c * 1000) / 1000; // round to the thousandth's place
  return c;
}

vector<point> collect_points() {
  vector<point> vctr;

  cout << "Enter two numbers to add a point\n"
       << "Enter '999' to end \n"
       << "Ex: '3 8' " << endl;
  float x, y;
  while (true) {
    x = 0;
    y = 0;
    cin >> x >> y;

    cout << "X: " << x << " ---- Y: " << y << endl;
    if (x == 999) {
      break;
    } else {
      point xy = {x, y};
      vctr.push_back(xy);
    }
  }
  return vctr;
}

void printTriangles(vector<triplet> triangles, vector<point> points) {

  int triC = triangles.size();

  if (triC == 0) {
    cout << "\nThere are no equlateral triangles in this set" << endl;
    return;
  }

  cout << "\nHere are all of the equalateral trianlges";
  for (int i = 0; i < triC; i++) {
    triplet triangle = triangles[i];
    cout << "\n#" << i + 1 << " [" << triangle.first << " -> ("
         << points[triangle.first].x << ", " << points[triangle.first].y
         << "), " << triangle.second << " -> (" << points[triangle.second].x
         << ", " << points[triangle.second].y << "), " << triangle.third
         << " -> (" << points[triangle.third].x << ", "
         << points[triangle.third].y << ")]";
  }
  cout << endl;
}