#include <bits/stdc++.h>

using namespace std;

class aho_corasick {
  struct node {
    int link = -1, p = -1, cnt = 0;
    char c;
    map<char, int> next;
  };

  int ptr = 0;
  vector<node> trie;

  int get(int v) {
    if (trie[v].link == -1) {
      if (v == 0 or trie[v].p == 0) {
        trie[v].link = 0;
      } else {
        trie[v].link = go(get(trie[v].p), trie[v].c);
        get(trie[v].link);
        trie[v].cnt += trie[trie[v].link].cnt;
      }
    }
    return trie[v].link;
  }

  int go(int v, char c) {
    if (!trie[v].next.count(c)) {
      trie[v].next[c] = (v ? go(get(v), c) : 0);
    }
    return trie[v].next[c];
  }
public:
  aho_corasick() {
    ++ptr;
    trie.push_back(node());
  }

  void add_word(const string& s) {
    int v = 0;
    for (char c : s) {
      if (!trie[v].next.count(c)) {
        trie.push_back(node());
        trie[ptr].p = v;
        trie[ptr].c = c;
        trie[v].next[c] = ptr++;
      }
      v = trie[v].next[c];
    }
    ++trie[v].cnt;
  }

  void build() {
    for (int i = 0; i < ptr; ++i) {
      get(i);
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
