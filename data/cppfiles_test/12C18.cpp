#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c x, c y) {
  return rge<c>{x, y};
}
template <class c>
auto ptb(c* x) -> decltype(cerr << *x, 0);
template <class c>
char ptb(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const int N = 2e3 + 5, MAX = 8e6, INF = 1e9;
int n, m;
bool a[N][N];
long long nearest[N][N];
void read() {
  cin >> n >> m;
  n++, m++;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(m); j++) {
      char x;
      cin >> x;
      a[i][j] = x == '1';
    }
}
void init() {
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(m); j++) nearest[i][j] = INF;
  for (int i = 0; i < (int)(n); i++) {
    long long nw = INF;
    for (int j = 0; j < (int)(m); j++) {
      if (a[i][j])
        nw = 0;
      else if (nw != (int)1e9)
        nw++;
      nearest[i][j] = min(nw, nearest[i][j]);
    }
    nw = 1e9;
    for (int j = (int)(m)-1; j >= 0; j--) {
      if (a[i][j])
        nw = 0;
      else if (nw != (int)1e9)
        nw++;
      nearest[i][j] = min(nw, nearest[i][j]);
    }
  }
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(m); j++) {
      if (nearest[i][j] != INF) nearest[i][j] *= nearest[i][j];
    }
}
struct Curve {
  long long a, c;
  Curve() {}
  Curve(long long _a, long long _c) : a(_a), c(_c) {}
  bool operator<(const Curve& ot) {
    if (a < ot.a) return 1;
    return c < ot.c;
  }
  long long eval(long long x) { return (x - a) * (x - a) + c; }
};
ostream& operator<<(ostream& os, const Curve x) {
  os << "(x - " << x.a << ")^2 + " << x.c << ')';
  return os;
}
long double intersect(Curve f, Curve g) {
  long double x = g.c - f.c;
  x /= g.a - f.a;
  x += f.a + g.a;
  x /= 2;
  return x;
}
template <typename T>
struct ConvexHullTrick {
  vector<T> v;
  void clear() { v.clear(); }
  void add(Curve nw) {
    while (v.size() >= 2 &&
           intersect(v[v.size() - 2], v.back()) >= intersect(v.back(), nw))
      v.pop_back();
    v.push_back(nw);
  }
  long long query(int x) {
    int l = 0, r = (int)v.size() - 2, ans = (int)v.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (intersect(v[mid], v[mid + 1]) < x)
        l = mid + 1;
      else
        r = mid - 1, ans = mid;
    }
    return v[ans].eval(x);
  }
};
ConvexHullTrick<Curve> cht;
void solve() {
  long long ans = 0;
  for (int j = 0; j < (int)(m); j++) {
    cht.clear();
    for (int i = 0; i < (int)(n); i++) {
      Curve curve = {i, nearest[i][j]};
      cht.add({i, nearest[i][j]});
    }
    for (int i = 0; i < (int)(n); i++) {
      long long cur = cht.query(i);
      ans += cur;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  read();
  init();
  solve();
  return 0;
}
