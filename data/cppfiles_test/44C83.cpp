#include <bits/stdc++.h>
using namespace std;
template <class C>
struct rge {
  C b, e;
};
template <class C>
rge<C> range(C x, C y) {
  return rge<C>{x, y};
}
template <class C>
auto dud(C *x) -> decltype(cerr << *x, 0);
template <class C>
char dud(...);
struct debug {
  ~debug() { cerr << "\n"; }
  template <class C>
  typename enable_if<sizeof dud<C>(0) != 1, debug &>::type operator<<(C i) {
    cerr << boolalpha << i;
    return *this;
  }
  template <class C>
  typename enable_if<sizeof dud<C>(0) == 1, debug &>::type operator<<(C i) {
    return *this << range(begin(i), end(i));
  }
  template <class C1, class C2>
  debug &operator<<(pair<C1, C2> p) {
    return *this << "(" << p.first << ", " << p.second << ")";
  }
  template <class C>
  debug &operator<<(rge<C> r) {
    *this << "[";
    for (auto it = r.b; it != r.e; ++it) *this << ", " + 2 * (it == r.b) << *it;
    return *this << "]";
  }
};
long long c, d;
void test_case() {
  cin >> c >> d;
  if (c == 0 && d == 0) {
    cout << "0\n";
    return;
  }
  if (abs(c - d) & 1) {
    cout << "-1\n";
    return;
  }
  cout << ((c - d == 0) ? 1 : 2) << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    test_case();
  }
  return 0;
}
