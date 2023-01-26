#include <bits/stdc++.h>
using namespace std;
ifstream in("in.in");
ofstream out("out.out");
vector<int> genF(int l, int r, function<int(int)> func) {
  vector<int> rez;
  int inc = (l < r) ? 1 : -1;
  for (int i = l; i != r + inc; i += inc) rez.push_back(func(i));
  return rez;
}
template <typename T>
vector<T> genF(T l, T r) {
  vector<T> rez;
  int inc = (l < r) ? 1 : -1;
  for (int i = l; i != r + inc; i += inc) rez.push_back(i);
  return rez;
}
template <typename T>
vector<T> operator+(const vector<T>& x, const vector<T>& y) {
  vector<int> rez = x;
  rez.insert(rez.end(), y.begin(), y.end());
  return rez;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto k : v) os << k << " ";
  return os;
}
struct dsu;
class debugClass {
 public:
  template <typename T>
  void p(T x) {
    cout << x << " ";
  }
  template <typename T>
  void p(vector<T> x) {
    cout << "{";
    for (auto i = x.begin(); i != x.end() - 1; i++) cout << (*i) << ",";
    cout << *(x.end() - 1);
    cout << "} ";
  }
  template <typename T, typename P>
  void p(pair<T, P> x) {
    cout << "{" << x.first << "," << x.second << "} ";
  }
  void p(dsu x);
};
debugClass debug;
struct dsu {
  vector<int> r, s;
  dsu(int n) : r(n, 0), s(n, 1){};
  dsu(){};
  void join(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (s[x] < s[y]) swap(x, y);
      r[y] = x;
      s[x] += s[y];
    }
  }
  int root(int x) {
    if (r[x] == 0) return x;
    return r[x] = root(r[x]);
  }
  int connected(int x, int y) {
    x = root(x);
    y = root(y);
    return x == y;
  }
};
dsu dsu1, dsu2;
int n, m1, m2;
void input() {
  int u, v, i;
  cin >> n >> m1 >> m2;
  dsu1 = dsu(n + 1);
  dsu2 = dsu(n + 1);
  for (i = 0; i < m1; i++) {
    cin >> u >> v;
    dsu1.join(u, v);
  }
  for (i = 0; i < m2; i++) {
    cin >> u >> v;
    dsu2.join(u, v);
  }
}
void solve() {
  int i, j;
  vector<pair<int, int>> sol;
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      if (!dsu1.connected(i, j) && !dsu2.connected(i, j)) {
        dsu1.join(i, j);
        dsu2.join(i, j);
        sol.push_back({i, j});
      }
    }
  }
  cout << sol.size() << "\n";
  for (auto k : sol) {
    cout << k.first << " " << k.second << "\n";
  }
  cout << "\n";
}
int main() {
  input();
  solve();
}
void debugClass::p(dsu x) {
  cout << "x.r"
       << "=";
  debug.p(x.r);
  ;
  cout << "\n";
  cout << "x.s"
       << "=";
  debug.p(x.s);
  ;
  cout << "\n";
  cout << "\n";
}
