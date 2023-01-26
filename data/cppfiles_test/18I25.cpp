#include <bits/stdc++.h>
using namespace std;
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, 1, 0, -1};
long long a[205], u[205], b[205];
long long helper(long long x, long long y, long long z, long long w) {
  if (x > y) {
    swap(x, y);
  }
  if (z > w) {
    swap(z, w);
  }
  if (x < z and z < y and x < w and w < y) return 0;
  if ((z > y or z < x) and (w > y or w < x)) return 0;
  return 1;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v;
  for (long long i = 0; i < 200; i++) u[i] = 0;
  for (long long i = 0; i < k; i++) {
    cin >> a[i + 1] >> b[i + 1];
    u[a[i + 1]] = 1, u[b[i + 1]] = 1;
  }
  long long cnt = 0;
  for (long long i = 0; i < 2 * n; i++) {
    if (u[i + 1] == 0) {
      cnt++;
      v.push_back(i + 1);
    }
  }
  for (long long i = 1; i <= cnt / 2; i++) {
    a[i + k] = v[i - 1];
    b[i + k] = v[i + cnt / 2 - 1];
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      ans += helper(a[i + 1], b[i + 1], a[j + 1], b[j + 1]);
    }
  }
  cout << ans << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
