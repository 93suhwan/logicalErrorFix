#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
void setIO() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
}
const long long nax = 2e5 + 10;
long long n;
vector<long long> a;
bool ok(long long x) {
  vector<long long> v = a;
  for (long long i = n - 1; i > 1; i--) {
    if (v[i] < x) {
      return false;
    }
    long long have = min(v[i] - x, a[i]);
    have /= 3;
    v[i] -= 3 * have;
    v[i - 1] += have;
    v[i - 2] += have * 2;
  }
  return (v[0] >= x && v[1] >= x);
}
void solve() {
  cin >> n;
  a.resize(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long l = 1, r = *max_element(a.begin(), a.end());
  while (l < r) {
    long long mid = l + (r - l + 1) / 2;
    if (ok(mid)) {
      l = mid;
    } else
      r = mid - 1;
  }
  cout << l << '\n';
}
int32_t main() {
  setIO();
  long long T;
  cin >> T;
  for (long long i = 1; i <= T; i++) {
    solve();
  }
}
