#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(const string& s) {
  int n = s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; ++i) {
    pi[i] = pi[i - 1];
    while (pi[i] and s[i] != s[pi[i]]) {
      pi[i] = pi[pi[i] - 1];
    }
    pi[i] += s[i] == s[pi[i]];
  }
  return pi;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
