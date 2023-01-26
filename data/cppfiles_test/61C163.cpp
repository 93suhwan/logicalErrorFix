#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;
pair<long long, long long> a[maxn];
long long n;
long long cnt[maxn][2];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++)
    cnt[i][0] = cnt[i][1] = 0, cin >> a[i].first >> a[i].second;
  long long ans = n * (n - 1) * (n - 2) / 6;
  for (long long i = 1; i <= n; i++) {
    cnt[a[i].first][0]++;
    cnt[a[i].second][1]++;
  }
  for (long long i = 1; i <= n; i++) {
    ans -= (cnt[a[i].first][0] - 1) * (cnt[a[i].second][1] - 1);
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
