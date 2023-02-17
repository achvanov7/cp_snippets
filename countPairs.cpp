#include <bits/stdc++.h>

using namespace std;

template<typename T, typename F>
long long count_pairs(T array, F &&comp) {
  if (array.empty()) return 0;
  T buffer(array.size());
  function<long long(int, int)> calc = [&](int l, int r) -> long long {
    if (l == r) return 0;
    int m = l + r >> 1;
    long long ans = calc(l, m) + calc(m + 1, r);
    int L = l, R = m + 1, n = 0;
    while (L <= m or R <= r) {
      if (L <= m and (R > r or comp(array[L], array[R]))) {
        buffer[n++] = array[L++];
      } else {
        ans += L - l;
        buffer[n++] = array[R++];
      }
    }
    copy(buffer.begin(), buffer.begin() + n, array.begin() + l);
    return ans;
  };
  return calc(0, (int)array.size() - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
