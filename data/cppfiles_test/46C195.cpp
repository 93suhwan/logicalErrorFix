#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long MAXN = 2e5 + 100;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i + 1 < n; i += 2) {
    long long bal = 0, mb = 0;
    for (int j = i + 1; j < n; j += 2) {
      long long r = min(a[j] - bal, a[i]);
      long long l = max(1LL, -mb);
      ans += max(0LL, r - l + 1);
      bal -= a[j];
      mb = min(mb, bal);
      if (j + 1 < n) bal += a[j + 1];
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
}
