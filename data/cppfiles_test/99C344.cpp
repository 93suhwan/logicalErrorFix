#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 * 1e3 + 10;
const long double eps = 1e-9;
const int inf = 1.01e9;
const long long llinf = (long long)1.01e18;
const long long MOD = 1e9 + 7;
const string Y = "YES";
const string N = "NO";
template <typename T>
inline int sz(T structure) {
  return (int)(structure.size());
}
template <typename T>
inline void chkmax(T& max, T a) {
  if (max < a) max = a;
}
template <typename T>
inline void chkmin(T& min, T a) {
  if (min > a) min = a;
}
template <class T>
inline istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v) is >> x;
  return is;
}
template <class T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < sz(v); ++i) os << ' ' << v[i];
  }
  return os;
}
inline int Bit(int mask, int b) { return (mask >> b) & 1; }
void precalc() {}
void solve() {
  long long x0, n;
  cin >> x0 >> n;
  long long d = -llinf;
  if (n == 0) {
    cout << x0 << endl;
    return;
  }
  if (x0 & 1) {
    if (n == 1)
      d = 1;
    else {
      long long ost = (n - 2) % 4;
      if (ost == 0)
        d = -1;
      else if (ost == 1)
        d = -1 - n;
      else if (ost == 2)
        d = 0;
      else if (ost == 3)
        d = n;
    }
  } else {
    if (n == 1)
      d = -1;
    else {
      long long ost = (n - 2) % 4;
      if (ost == 0)
        d = 1;
      else if (ost == 1)
        d = n + 1;
      else if (ost == 2)
        d = 0;
      else if (ost == 3)
        d = -n;
    }
  }
  cout << x0 + d << endl;
}
int main() {
  precalc();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
