#include <bits/stdc++.h>

using namespace std;

using u64 = unsigned long long;

u64 mul(u64 a, u64 b, u64 m) {
  return (a * b - (u64)((long double) a * b / m) * m + m) % m;
}

u64 power(u64 a, u64 b, u64 m) {
  return (b ? mul(power(mul(a, a, m), b >> 1, m), (b & 1 ? a : 1), m) : 1);
}

bool check(u64 n, u64 a, u64 d, int s) {
  u64 x = power(a, d, n);
  if (x == 1 or x == n - 1) {
    return false;
  }
  for (int r = 1; r < s; ++r) {
    x = mul(x, x, n);
    if (x == n - 1) {
      return false;
    }
  }
  return true;
}

bool MillerRabin(u64 n) {
  if (n < 2) {
    return false;
  }
  int r = 0;
  u64 d = n - 1;
  while ((d & 1) == 0) {
    ++r;
    d >>= 1;
  }
  for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a) {
      return true;
    } else if (n % a == 0) {
      return false;
    } else if (check(n, a, d, r)) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
