#include <bits/stdc++.h>
using namespace std;
enum { maxn = 200010, inf = 0x3f3f3f3f };
int n;
long long a[maxn];
long long dp[2][100010];
vector<int> ve[maxn];
void solve() {
  cin >> n;
  ve[n + 1].clear();
  for (int i = 1; i <= n; ++i) cin >> a[i], ve[i].clear();
  long long ans = 0;
  for (int i = n; i > 0; --i) {
    int inv = i & 1;
    dp[inv][a[i]] = 1;
    ve[i].push_back(a[i]);
    int las = a[i];
    for (int x : ve[i + 1]) {
      int sp = (a[i] + x - 1) / x;
      int newx = a[i] / sp;
      if (newx != las) {
        dp[inv][newx] = 0;
        ve[i].push_back(newx);
        las = newx;
      }
      ans += dp[inv ^ 1][x] * (sp - 1) * i;
      dp[inv][newx] += dp[inv ^ 1][x];
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
