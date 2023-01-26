#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-8;
const int N = 2e5 + 10;
const int M = 1e6 + 10;
int a[N];
long long dp[N];
void run() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  dp[1] = 1;
  long long sum = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] += sum;
    for (int l = 2, r = 0; l <= i; l = r + 1) {
      r = min(i, i / (i / l));
      dp[i] += 1ll * dp[i / l] * (r - l + 1);
      dp[i] = dp[i] % m;
    }
    sum += dp[i];
    sum %= m;
  }
  cout << dp[n] << endl;
}
int main() {
  run();
  return 0;
}
