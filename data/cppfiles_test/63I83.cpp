#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
const int MAXN = (1 << 20);
int dp[MAXN], sum[MAXN], p[20], mn[20][400000], ss[20];
vector<vector<int>> pos[20];
int shift = 4e5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < (1 << n); i++) dp[i] = -1;
  for (int i = 0; i < n; i++) {
    int cur = 0;
    pos[i].resize(shift * 2);
    for (int j = 0; j < (int)(s[i].size()); j++) {
      cur += s[i][j] == '(' ? 1 : -1;
      pos[i][cur + shift].push_back(j);
      mn[i][j] = cur;
      if (j) mn[i][j] = min(mn[i][j], mn[i][j - 1]);
    }
    ss[i] = cur;
  }
  int ans = 0;
  dp[0] = 0;
  sum[0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    if (dp[i] == -1) continue;
    for (int j = 0; j < n; j++) {
      if (!(i & (1 << j))) {
        int need = -sum[i] + shift;
        int l = 0, r = (int)(s[j].size()) - 1;
        while (r >= l) {
          int mid = (l + r) / 2;
          if (mn[j][mid] >= -sum[i])
            l = mid + 1;
          else
            r = mid - 1;
        }
        int add = lower_bound(pos[j][need].begin(), pos[j][need].end(), l) -
                  pos[j][need].begin();
        ans = max(ans, dp[i] + add);
        sum[i + (1 << j)] = sum[i] + ss[j];
        if (l == (int)(s[j].size()))
          dp[i + (1 << j)] = max(dp[i + (1 << j)], dp[i] + add);
        else
          dp[i + (1 << j)] = -1;
      }
    }
  }
  cout << ans;
}
