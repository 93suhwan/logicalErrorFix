#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int dp[200002];
  dp[1] = 1;
  dp[2] = 1;
  for (long long int i = 3; i <= 200000; i++) {
    dp[i] = (dp[i - 1] * i) % 1000000007;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp[2 * n]);
  }
  return 0;
}
