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
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int x = ((n * m) / 2) - k;
  if (m & 1) {
    x -= n / 2;
    if (x < 0) {
      cout << "NO" << endl;
      return;
    }
  } else if (n & 1) {
    k -= m / 2;
    if (k < 0) {
      cout << "NO" << endl;
      return;
    }
  }
  if (k & 1 or x & 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}
int32_t main() {
  stugs();
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
