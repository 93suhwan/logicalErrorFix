#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\t";
  err(++it, args...);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& c, pair<T1, T2>& v) {
  c << "(" << v.first << "," << v.second << ")";
  return c;
}
template <template <class...> class TT, class... T>
ostream& operator<<(ostream& out, TT<T...>& c) {
  out << "{ ";
  for (auto& x : c) out << x << " ";
  out << "}";
  return out;
}
const int LIM = 50000 + 5, MOD = 1e9 + 7;
const long double EPS = 1e-9;
int read() {
  int xx = 0, ff = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    xx = (xx << 3) + (xx << 1) + ch - '0';
    ch = getchar();
  }
  return xx * ff;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int r[LIM][5];
int comp(int a, int b) {
  int num = 0;
  for (int i = 0; i < 5; ++i) {
    if (r[a][i] < r[b][i]) num++;
  }
  if (num > 2)
    return a;
  else
    return b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    int n;
    cin >> n;
    int sup = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        cin >> r[i][j];
      }
    }
    for (int i = 1; i < n; ++i) {
      sup = comp(sup, i);
    }
    bool p = 1;
    for (int i = 0; i < n; ++i) {
      if (comp(sup, i) != sup) p = 0;
    }
    if (p) {
      cout << 1 + sup << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}
