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
void solve(long long tc) {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long sum = accumulate(a.begin(), a.end(), 0LL);
  multiset<long long> ms;
  for (long long i = 0; i < n; i++) ms.insert(a[i]);
  long long q;
  cin >> q;
  while (q--) {
    long long x, y;
    cin >> x >> y;
    auto it = ms.lower_bound(x);
    long long ans = 2e18;
    if (it != ms.end()) {
      long long z = *it;
      if (sum - z >= y) {
        ans = 0;
      } else {
        umin(ans, y - (sum - z));
      }
    }
    it = ms.upper_bound(x);
    if (it != ms.begin()) {
      it--;
      long long cur = x - *it;
      if (sum - *it <= y) cur += (y - sum + *it);
      umin(ans, cur);
    }
    cout << ans << '\n';
  }
}
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
