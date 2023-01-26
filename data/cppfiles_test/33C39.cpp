#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 500;
long long dp[1025], s[maxn];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &s[i]);
  }
  memset(dp, 0x3f3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1024; j >= 0; j--)
      if (dp[j] < s[i]) dp[j ^ s[i]] = min(dp[j ^ s[i]], s[i]);
  }
  long long sum = 0;
  for (int i = 0; i < 1025; i++)
    if (dp[i] != 0x3f3f3f3f3f3f3f3f) sum++;
  cout << sum << endl;
  for (int i = 0; i < 1025; i++)
    if (dp[i] != 0x3f3f3f3f3f3f3f3f) printf("%d ", i);
  return 0;
}
