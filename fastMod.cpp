#include <bits/stdc++.h>

using namespace std;

static unsigned fast_mod(uint64_t x) {
  unsigned x_high = x >> 32, x_low = (unsigned) x;
  unsigned quot, rem;
  asm("divl %4\n"
  : "=a" (quot), "=d" (rem)
  : "d" (x_high), "a" (x_low), "r" (mod));
  return rem;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
