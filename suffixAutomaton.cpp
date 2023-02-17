#include <bits/stdc++.h>

using namespace std;

class suf_automaton {
  struct node {
    map<char, int> next;
    int link, len;
  };

  vector<node> sa;
  int ptr = 0, last = 0;
public:
  suf_automaton() {
    node root;
    root.link = -1;
    root.len = 0;
    ++ptr;
    sa.push_back(root);
  }

  void add_char(char c) {
    int cur = ptr++;
    sa.push_back(node());
    sa[cur].len = sa[last].len + 1;
    int p = last;
    while (p != -1 and !sa[p].next.count(c)) {
      sa[p].next[c] = cur;
      p = sa[p].link;
    }
    last = cur;
    if (p == -1) {
      sa[cur].link = 0;
      return;
    }
    int q = sa[p].next[c];
    if (sa[p].len + 1 == sa[q].len) {
      sa[cur].link = q;
    } else {
      int clone = ptr++;
      sa.push_back(node());
      sa[clone].len = sa[p].len + 1;
      sa[clone].next = sa[q].next;
      sa[clone].link = sa[q].link;
      while (p != -1 and sa[p].next[c] == q) {
        sa[p].next[c] = clone;
        p = sa[p].link;
      }
      sa[q].link = sa[cur].link = clone;
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
