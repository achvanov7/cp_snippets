#include <bits/stdc++.h>

using namespace std;

vector<int> suffix_array(string& s) {
  s += '$';
  int n = s.size();
  vector<int> sa(n), cl(n), cnt(max(256, n));
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i]];
  }
  for (int i = 1; i < 256; ++i) {
    cnt[i] += cnt[i - 1];
  }
  for (int i = 0; i < n; ++i) {
    sa[--cnt[s[i]]] = i;
  }
  int classes = 0;
  for (int i = 1; i < n; ++i) {
    if (s[sa[i]] != s[sa[i - 1]]) {
      ++classes;
    }
    cl[sa[i]] = classes;
  }
  for (int h = 0; (1 << h) < n; ++h) {
    vector<int> nsa(n), ncl(n);
    for (int i = 0; i < n; ++i) {
      nsa[i] = (sa[i] - (1 << h) + n) % n;
    }
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < n; ++i) {
      ++cnt[cl[nsa[i]]];
    }
    for (int i = 1; i <= classes; ++i) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
      sa[--cnt[cl[nsa[i]]]] = nsa[i];
    }
    classes = 0;
    for (int i = 1; i < n; ++i) {
      if (cl[sa[i]] != cl[sa[i - 1]] or cl[(sa[i] + (1 << h)) % n] != cl[(sa[i - 1] + (1 << h) % n)]) {
        ++classes;
      }
      ncl[sa[i]] = classes;
    }
    cl = ncl;
  }
  sa.erase(sa.begin());
  s.pop_back();
  return sa;
}

vector<int> lcp_construction(string_view s, const vector<int>& sa) {
  int n = size(s);
  vector<int> rank(n);
  for (int i = 0; i < n; ++i) {
    rank[sa[i]] = i;
  }
  vector<int> lcp(n - 1);
  for (int i = 0, k = 0; i < n; ++i) {
    if (rank[i] == n - 1) {
      k = 0;
      continue;
    }
    int j = sa[rank[i] + 1];
    while (i + k < n and j + k < n and s[i + k] == s[j + k]) {
      k++;
    }
    lcp[rank[i]] = k;
    if (k) {
      k--;
    }
  }
  return lcp;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
