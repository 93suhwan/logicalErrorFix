#include <bits/stdc++.h>
using namespace std;
const int MAXN = 112345, MAXM = 450;
long long v[MAXN], dp[MAXM], s[MAXN];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int cur = 1;
    while (cur * (cur + 1) / 2 <= n) {
      dp[cur] = -1123456789012345678;
      cur++;
    }
    dp[0] = 1123456789012345678;
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &v[i]);
      s[i] = s[i - 1] + v[i];
    }
    int sq = sqrt(n) + 10;
    sq = min(sq, MAXM - 1);
    for (int i = n; i >= 1; i--) {
      int at = n - i + 1;
      at = min(at, sq);
      for (int j = at; j >= 1; j--) {
        if (i + j - 1 > n) continue;
        long long pr = i + j - 1, sm = s[pr] - s[i - 1];
        if (dp[j - 1] > sm) dp[j] = max(dp[j], sm);
      }
    }
    int resp = 0;
    while (dp[resp] > 0) resp++;
    printf("%d\n", resp - 1);
  }
  return 0;
}
