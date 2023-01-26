#include <bits/stdc++.h>
using namespace std;
int dp[10500], a[100005];
int main(void) {
  int n;
  int i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 0; i <= 1024; i++) dp[i] = 5000;
  dp[0] = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1024; j >= 0; j--) {
      if (a[i] > dp[j]) {
        dp[j ^ a[i]] = min(dp[j ^ a[i]], a[i]);
      }
    }
  }
  int sum = 0;
  for (i = 0; i <= 1024; i++) {
    if (dp[i] != 5000) sum++;
  }
  printf("%d\n", sum);
  for (i = 0; i <= 1024; i++)
    if (dp[i] != 5000) printf("%d ", i);
}
