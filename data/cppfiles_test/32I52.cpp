#include <bits/stdc++.h>
using namespace std;
int T, N, M;
long long dp[100005][505];
int a[100005];
long long Sum[100005];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
    Sum[0] = 0;
    for (int i = 1; i <= N; i++) Sum[i] = Sum[i - 1] + a[i];
    int Len = int(sqrt(2 * N));
    for (int i = 1; i <= N; i++) dp[i][1] = a[i];
    for (int i = N; i >= 1; i--) {
      for (int j = 1; i + j + 1 <= N && j <= Len; j++) {
        dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        if (dp[i + j][j - 1] > Sum[i + j - 1] - Sum[i - 1])
          dp[i][j] = max(dp[i][j], Sum[i + j - 1] - Sum[i - 1]);
      }
    }
    for (int i = Len; i >= 1; i--) {
      if (dp[1][i]) {
        printf("%d\n", i);
        break;
      }
    }
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= Len; j++) dp[i][j] = 0;
  }
  return 0;
}
