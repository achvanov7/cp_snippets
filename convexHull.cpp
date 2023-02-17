#include <bits/stdc++.h>

using namespace std;

vector<point> convex_hull(vector<point> a) {
  sort(a.begin(), a.end());
  point A = a.front(), B = a.back();
  if (A == B) {
    return {A};
  }
  vector<point> up, down;
  up.push_back(A), down.push_back(A);
  for (int i = 1; i < a.size(); ++i) {
    if (i == a.size() - 1 or (B - A) * (a[i] - A) > 0) {
      while (up.size() >= 2 and (a[i] - up[up.size() - 2]) * (up[up.size() - 1] - up[up.size() - 2]) <= 0) {
        up.pop_back();
      }
      up.push_back(a[i]);
    }
    if (i == a.size() - 1 or (B - A) * (a[i] - A) < 0) {
      while (down.size() >= 2 and (a[i] - down[down.size() - 2]) * (down[down.size() - 1] - down[down.size() - 2]) >= 0) {
        down.pop_back();
      }
      down.push_back(a[i]);
    }
  }
  for (int i = down.size() - 2; i > 0; --i) {
    up.push_back(down[i]);
  }
  return up;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
