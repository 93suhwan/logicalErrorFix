#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto &x : v) cout << x << ' ';
  return os;
}
long long n;
bool simulate(vector<long long> v, long long x) {
  for (long long i = 2; i < n; i++) {
    long long a = max(long long(0), x - v[i - 2]),
              b = max(long long(0), x - v[i - 1]);
    long long d = min(max((a + 1) / 2, b), v[i] / 3);
    v[i - 2] += 2 * d;
    v[i - 1] += d;
    v[i] -= 3 * d;
  }
  return *min_element(v.begin(), v.end()) >= x;
}
void solve() {
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long l = *min_element(v.begin(), v.end()),
            r = *max_element(v.begin(), v.end()), ans = l;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (simulate(v, mid)) {
      l = mid + 1;
      ans = max(ans, mid);
    } else
      r = mid - 1;
  }
  cout << ans << '\n';
}
int32_t main() {
  long long t;
  cin >> t;
  for (long long $i = 0; $i < t; $i++) solve();
}
