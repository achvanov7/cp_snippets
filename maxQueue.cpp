#include <bits/stdc++.h>

using namespace std;

template<class T> class max_stack {
public:
  stack<pair<T, T>> st;

  void pop() {
    st.pop();
  }
  T get() {
    return (st.empty() ? numeric_limits<T>::min() : st.top().second);
  }
  T top() {
    if (empty()) {
      throw 1;
    }
    return st.top().first;
  }
  void push(T x) {
    st.emplace(x, max(x, get()));
  }
  bool empty() {
    return st.empty();
  }
  int size() {
    return st.size();
  }
};

template<class T> class max_queue {
public:
  max_stack<T> st1, st2;

  void reorder() {
    if (st1.empty()) {
      while (st2.size()) {
        st1.push(st2.top());
        st2.pop();
      }
    }
  }
  void push(T x) {
    st2.push(x);
  }
  void pop() {
    reorder();
    st1.pop();
  }
  T front() {
    reorder();
    return st1.top();
  }
  T get() {
    return max(st1.get(), st2.get());
  }
  int size() {
    return st1.size() + st2.size();
  }
  bool empty() {
    return st1.empty() and st2.empty();
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
