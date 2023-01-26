#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (auto &i : v) cin >> i;
  vector<long long> diff(n - 1);
  for (long long i = 0; i < n - 1; i++) diff[i] = abs(v[i] - v[i + 1]);
  long long mx = 1;
  long long hcf = diff[0];
  long long cnt = 1;
  for (long long i = 1; i < n - 1; i++) {
    hcf = gcd(hcf, diff[i]);
    if (hcf > 1) {
      cnt++;
    } else {
      hcf = diff[i];
      cnt = 1;
    }
    mx = max(mx, cnt);
  }
  cout << mx + 1 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc;
  tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
