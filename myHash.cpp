#include <bits/stdc++.h>

using namespace std;

const int mods[] = {(int)1e9 + 7, (int)1e9 + 9}, K = 2;

struct mhash {
  array<int, K> val;

  mhash(int x = 0) {
    for (int i = 0; i < K; ++i) {
      val[i] = x;
      if (x < 0) val[i] += mods[i];
    }
  }
  mhash(array<int, K> x) {
    val = x;
  }
  mhash(long long x) {
    for (int i = 0; i < K; ++i) {
      val[i] = x % mods[i];
    }
  }
};

bool operator==(mhash a, mhash b) {
  return a.val == b.val;
}

bool operator<(mhash a, mhash b) {
  return a.val < b.val;
}

mhash operator+(mhash a, mhash b) {
  for (int i = 0; i < K; ++i) {
    a.val[i] += b.val[i];
    if (a.val[i] >= mods[i]) a.val[i] -= mods[i];
  }
  return a;
}

mhash operator+=(mhash& a, mhash b) {
  for (int i = 0; i < K; ++i) {
    a.val[i] += b.val[i];
    if (a.val[i] >= mods[i]) a.val[i] -= mods[i];
  }
  return a;
}

mhash operator-(mhash a, mhash b) {
  for (int i = 0; i < K; ++i) {
    a.val[i] -= b.val[i];
    if (a.val[i] < 0) a.val[i] += mods[i];
  }
  return a;
}

mhash operator-=(mhash& a, mhash b) {
  for (int i = 0; i < K; ++i) {
    a.val[i] -= b.val[i];
    if (a.val[i] < 0) a.val[i] += mods[i];
  }
  return a;
}

mhash operator*(mhash a, mhash b) {
  for (int i = 0; i < K; ++i) {
    a.val[i] = 1ll * a.val[i] * b.val[i] % mods[i];
  }
  return a;
}

mhash operator*=(mhash& a, mhash b) {
  for (int i = 0; i < K; ++i) {
    a.val[i] = 1ll * a.val[i] * b.val[i] % mods[i];
  }
  return a;
}

template<typename T>
mhash operator^(mhash a, T k) {
  mhash b = 1;
  for (int i = sizeof(k) * 4 - 1; i >= 0; --i) {
    b *= b;
    if (k >> i & 1) b *= a; 
  }
  return b;
}

template<typename T>
mhash operator^=(mhash& a, T k) {
  mhash b = 1;
  for (int i = sizeof(k) * 4 - 1; i >= 0; --i) {
    b *= b;
    if (k >> i & 1) b *= a; 
  }
  return b;
}

mhash inv(mhash a) {
  for (int j = 0; j < K; ++j) {
    int b = 1;
    int k = mods[j] - 2;
    for (int i = 31; i >= 0; --i) {
      b = 1ll * b * b % mods[j];
      if (k >> i & 1) b = 1ll * b * a.val[j] % mods[j];
    }
    a.val[j] = b;
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
