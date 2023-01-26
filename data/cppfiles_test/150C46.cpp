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
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ans = 1e12;
  for (long long one = 0; one < 3; one++) {
    for (long long two = 0; two < 3; two++) {
      long long cur = 0;
      for (long long i = 0; i < n; i++) {
        long long need = 1e12;
        for (long long j = 0; j <= one; j++) {
          for (long long k = 0; k <= two; k++) {
            if (a[i] - j - k * 2 >= 0 && (a[i] - j - k * 2) % 3 == 0) {
              umin(need, (a[i] - j - k * 2) / 3);
            }
          }
        }
        umax(cur, need);
      }
      umin(ans, cur + one + two);
    }
  }
  {
    cout << ans << '\n';
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
