#include <bits/stdc++.h>

using namespace std;

class twoSAT {
public:
  int n;
  vector<vector<int>> g, gr;
  vector<char> used, ans;
  vector<int> ord, comp;

  twoSAT(int nn) {
    n = nn;
    g.resize(2 * n);
    gr.resize(2 * n);
    used.resize(2 * n);
    ans.resize(n);
    comp.resize(2 * n, -1);
  }

  void add_condition(int v, int tv, int u, int tu) {
    v *= 2;
    u *= 2;
    g[v ^ tv ^ 1].push_back(u ^ tu);
    g[u ^ tu ^ 1].push_back(v ^ tv);
    gr[u ^ tu].push_back(v ^ tv ^ 1);
    gr[v ^ tv].push_back(u ^ tu ^ 1);
  }

  void dfs1(int v) {
    used[v] = true;
    for (int to : g[v]) {
      if (!used[to]) {
        dfs1(to);
      }
    }
    ord.push_back(v);
  }

  void dfs2(int v, int id) {
    comp[v] = id;
    for (int to : gr[v]) {
      if (comp[to] == -1) {
        dfs2(to, id);
      }
    }
  }

  bool solve() {
    for (int i = 0; i < 2 * n; ++i) {
      if (!used[i]) {
        dfs1(i);
      }
    }
    reverse(ord.begin(), ord.end());
    int cnt = 0;
    for (int i : ord) {
      if (comp[i] == -1) {
        dfs2(i, cnt++);
      }
    }
    for (int i = 0; i < 2 * n; i += 2) {
      if (comp[i] == comp[i ^ 1]) {
        return false;
      }
      ans[i / 2] = comp[i] > comp[i ^ 1];
    }
    return true;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
