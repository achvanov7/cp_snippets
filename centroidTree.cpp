#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
int sz[N], lvl[N], par[N], dist[N][20];

// Adjust N and make sure lvl's are -1

void dfs(int v, int p = -1) {
  sz[v] = 1;
  for (int to : g[v]) {
    if (lvl[to] != -1 or to == p) {
      continue;
    }
    dfs(to, v);
    sz[v] += sz[to];
  }
}

int find_centroid(int v, int p, int n) {
  for (int to : g[v]) {
    if (lvl[to] != -1 or to == p) {
      continue;
    }
    if (sz[to] > n / 2) {
      return find_centroid(to, v, n);
    }
  }
  return v;
}

void calc(int v, int depth, int p) {
  for (int to : g[v]) {
    if (to == p or lvl[to] != -1) {
      continue;
    }
    dist[to][depth] = dist[v][depth] + 1;
    calc(to, depth, v);
  }
}

void build(int v, int p = -1) {
  dfs(v, p);
  v = find_centroid(v, p, sz[v]);
  if (p == -1) {
    lvl[v] = 0, par[v] = v;
  } else {
    lvl[v] = lvl[p] + 1, par[v] = p;
  }
  calc(v, lvl[v], p);
  for (int to : g[v]) {
    if (lvl[to] != -1) {
      continue;
    }
    build(to, v);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
