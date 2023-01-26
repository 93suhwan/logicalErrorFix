#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto &x : v) cout << x << ' ';
  return os;
}
long long n;
vector<long long> v;
bool simulate(long long x) {
  vector<long long> temp = v;
  for (long long i = n - 1; i >= 2; i--) {
    long long d = max(min((temp[i] - x) / 3, v[i] / 3), long long(0));
    temp[i - 2] += 2 * d;
    temp[i - 1] += d;
    temp[i] -= 3 * d;
  }
  return *min_element(temp.begin(), temp.end()) >= x;
}
void solve() {
  cin >> n;
  v.resize(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long l = *min_element(v.begin(), v.end()),
            r = *max_element(v.begin(), v.end()), ans = l;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (simulate(mid)) {
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
