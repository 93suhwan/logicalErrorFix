#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const long long INF = 1e9 + 10;
long long MOD = 998244353;
long double EPS = 1e-12;
void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long t, n, a[MAXN];
long long dp1[MAXN], cnt[MAXN], pw[MAXN];
int sum(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}
int mul(int x, int y) { return x * 1ll * y % MOD; }
int main() {
  fastIO();
  cin >> t;
  pw[0] = 1;
  for (int i = 1; i < MAXN; i++) pw[i] = sum(pw[i - 1], pw[i - 1]);
  while (t--) {
    cin >> n;
    fill(cnt, cnt + n + 1, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    fill(dp1, dp1 + n + 10, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int val = a[i];
      cnt[val]--;
      dp1[val] = sum(dp1[val], dp1[val]);
      if (val > 0) {
        dp1[val] = sum(dp1[val], dp1[val - 1]);
      } else {
        dp1[val] = sum(dp1[val], 1);
      }
      if (val > 1) {
        ans = sum(ans, mul(dp1[val - 2], pw[cnt[val - 2] + cnt[val]]));
      }
      if (val == 1) {
        ans = sum(ans, pw[cnt[val]]);
      }
    }
    for (int i = 0; i <= n; i++) {
      ans = sum(ans, dp1[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
