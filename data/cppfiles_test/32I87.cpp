#include <bits/stdc++.h>
using namespace std;
const double esp = 1e-10;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
const double PI = acos(-1);
const int mod = 998244353;
int a[maxn];
long long pre[maxn];
int dp[maxn][500];
long long sum(int l, int r) { return pre[r] - pre[l - 1]; }
bool check(int a, int b) { return b * (b + 1) / 2 <= a; }
int main() {
  dp[0][0] = INF - 1;
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[n - i + 1]);
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j * (j + 1) / 2 <= i; ++j) {
        dp[i][j] = INF;
        if (check(i - 1, j) && dp[i - 1][j] != INF) dp[i][j] = dp[i - 1][j];
        if (dp[i - j][j - 1] != INF && dp[i - j][j - 1] > sum(i - j + 1, i))
          dp[i][j] = min(dp[i][j], (int)sum(i - j + 1, i));
        if (dp[i][j] != INF) ans = max(ans, j);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
