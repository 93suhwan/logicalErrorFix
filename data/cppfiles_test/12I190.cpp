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
bool umin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
void stugs() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool cmp(string s, string t) { return s.length() < t.length(); }
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int v = 0, h = 0;
  h = n * (m / 2);
  v = m * (n / 2);
  if (k > h || ((m * n) / 2) - k > v) {
    cout << "NO" << endl;
    return;
  }
  if (k == 0 || k == ((n * m) / 2)) {
    cout << "YES" << endl;
    return;
  }
  bool ok1 = false, ok2 = false;
  for (long long int i = 1; i <= k; i++) {
    long long int x = (k + i - 1) / i;
    if (m >= (2 * x)) {
      long long int y = n - i;
      long long int z = k % i;
      z = n - z;
      if (y % 2 == 0 && z % 2 == 0) {
        ok1 = true;
        break;
      }
    }
  }
  k = ((n * m) / 2) - k;
  for (long long int i = 1; i <= k; i++) {
    long long int x = (k + i - 1) / i;
    if (n >= (2 * x)) {
      long long int y = m - i;
      long long int z = k % i;
      z = m - z;
      if (y % 2 == 0 && z % 2 == 0) {
        ok2 = true;
        break;
      }
    }
  }
  if (ok1 or ok2) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}
int32_t main() {
  stugs();
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
