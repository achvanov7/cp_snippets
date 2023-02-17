#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int add() { return 0; }

template<typename... M>
int add(int a, M... b) {
  int x = add(b...);
  return a + x - mod * (a + x >= mod);
}

int mul() { return 1; }

template<typename... M>
int mul(int a, M... b) {
  return int(1ll * a * mul(b...) % mod);
}

int pwr(int a, long long x) {
  return (x ? mul(pwr(mul(a, a), x >> 1), (x & 1 ? a : 1)) : 1);
}

int inv(int a) {
  return pwr(a, mod - 2);
}

int sub(int a, int b) {
  return a - b + mod * (a < b);
}

void inc(int &a, int b) {
  a = add(a, b);
}

void dec(int &a, int b) {
  a = sub(a, b);
}

vector<int> fact = {1}, invf = {1};

int C(int n, int k) {
  if (n < k or 0 > k) return 0;
  while (fact.size() <= n) {
    fact.push_back(mul(fact.back(), fact.size()));
    invf.push_back(inv(fact.back()));
  }
  return mul(fact[n], invf[k], invf[n - k]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
