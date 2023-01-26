#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
namespace debug {
void __print(int x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto z : x) cerr << (f++ ? "," : ""), __print(z);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
}  // namespace debug
using namespace debug;
const char nl = '\n';
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int mxN = 1005;
bool marked[mxN][mxN];
long long dole[mxN][mxN];
long long desno[mxN][mxN];
void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    desno[n - 1][i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    dole[i][m - 1] = 1;
  }
  desno[n - 1][m - 1] = dole[n - 1][m - 1] = 0;
  for (int i = n - 2; i >= 0; --i) {
    for (int j = m - 2; j >= 0; --j) {
      dole[i][j] = desno[i + 1][j] + 1;
    }
    for (int j = m - 2; j >= 0; --j) {
      desno[i][j] = dole[i][j + 1] + 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans += (desno[i][j] + dole[i][j]);
    }
  }
  ans += n * m;
  auto update = [&](int x, int y, bool flag = false) {
    for (;; flag ^= 1) {
      if (flag) {
        --x;
        if (x < 0 || y < 0) break;
        if (marked[x][y]) break;
        ans -= dole[x][y];
        dole[x][y] = desno[x + 1][y] + 1;
        ans += dole[x][y];
      } else {
        --y;
        if (x < 0 || y < 0) break;
        if (marked[x][y]) break;
        ans -= desno[x][y];
        desno[x][y] = dole[x][y + 1] + 1;
        ans += desno[x][y];
      }
    }
  };
  while (q--) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    if (!marked[x][y]) {
      marked[x][y] = true;
      --ans;
      if (x - 1 >= 0) {
        ans -= dole[x - 1][y];
        dole[x - 1][y] = 0;
      }
      if (y - 1 >= 0) {
        ans -= desno[x][y - 1];
        desno[x][y - 1] = 0;
      }
      ans -= dole[x][y];
      ans -= desno[x][y];
      dole[x][y] = desno[x][y] = 0;
      if (x - 1 >= 0 && !marked[x - 1][y]) {
        update(x - 1, y, false);
      }
      if (y - 1 >= 0 && !marked[x][y - 1]) {
        update(x, y - 1, true);
      }
    } else {
      marked[x][y] = false;
      ++ans;
      if (x + 1 < n && !marked[x + 1][y]) {
        dole[x][y] = desno[x + 1][y] + 1;
      } else {
        dole[x][y] = 0;
      }
      if (y + 1 < m && !marked[x][y + 1]) {
        desno[x][y] = dole[x][y + 1] + 1;
      } else {
        desno[x][y] = 0;
      }
      ans += dole[x][y];
      ans += desno[x][y];
      update(x, y, true);
      update(x, y, false);
    }
    cout << ans << nl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testCases = 1;
  while (testCases--) solve();
}
