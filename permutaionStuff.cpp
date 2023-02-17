#include <bits/stdc++.h>

using namespace std;

long long getId(const vector<int>& p) {
  int n = p.size();
  long long f = 1, ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    int l = 0;
    for (int j = i + 1; j < n; ++j) l += p[i] > p[j];
    ans += l * f;
    f *= (n - i);
  }
  return ans;
}

vector<int> getPerm(long long id, int n) {
  vector<int> p(n);
  long long f = 1;
  for (int i = 2; i < n; ++i) f *= i;
  vector<int> r(n);
  iota(r.begin(), r.end(), 0);
  for (int i = 0; i < n; ++i) {
    p[i] = id / f;
    id -= p[i] * f;
    if (i != n - 1) f /= n - i - 1;
    int t = p[i];
    p[i] = r[t];
    r.erase(r.begin() + t);
  }
  return p;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
