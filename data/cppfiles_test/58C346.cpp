#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p) {
  os << "[";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "(" << p.first << "," << p.second << ")";
}
template <class T>
inline T Bit(T x, long long i) {
  return (x >> i) & 1;
}
template <class T>
bool umin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const long long N = 2e5 + 3;
void solve(long long tc) {
  long long n;
  cin >> n;
  string s[2];
  for (long long i = 0; i < 2; i++) cin >> s[i];
  long long a[2][n];
  memset(a, 0, sizeof(a));
  a[0][0] = 1;
  if (s[1][0] == '0') a[1][0] = 1;
  for (long long i = 1; i < n; i++) {
    if (a[0][i - 1] || a[1][i - 1]) {
      if (s[0][i] == '0') a[0][i] = 1;
      if (s[1][i] == '0') a[1][i] = 1;
    }
  }
  if (a[1][n - 1]) {
    cout << "YES" << '\n';
    return;
  };
  {
    cout << "NO" << '\n';
    return;
  };
}
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
