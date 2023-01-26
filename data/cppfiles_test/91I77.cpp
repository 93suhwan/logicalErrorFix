#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
const long long mod = 998244353;
int a[maxn], Dp[2][maxn];
vector<int> Save[2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = n; i; i--) {
      bool bit = i & 1;
      Save[bit].push_back(a[i]);
      Dp[bit][a[i]] = 1;
      int endo = a[i];
      for (int j = 0; j < Save[bit ^ 1].size(); j++) {
        int x = Save[bit ^ 1][j];
        int segNum = (a[i] + x - 1) / x;
        int segSize = a[i] / segNum;
        ans = (ans + 1ll * (segNum - 1) * Dp[bit ^ 1][x] * i) % mod;
        Dp[bit][segSize] += Dp[bit ^ 1][x];
        if (endo != segSize) {
          Save[bit].push_back(segSize);
          endo = segSize;
        }
      }
      for (int j = 0; j < Save[bit ^ 1].size(); j++) {
        int x = Save[bit ^ 1][j];
        Dp[bit ^ 1][x] = 0;
      }
      Save[bit ^ 1].clear();
    }
    for (int j = 0; j < Save[0].size(); j++) {
      int x = Save[0][j];
      Dp[0][x] = 0;
    }
    for (int j = 0; j < Save[1].size(); j++) {
      int x = Save[1][j];
      Dp[1][x] = 0;
    }
    cout << ans << '\n';
  }
  return 0;
}
