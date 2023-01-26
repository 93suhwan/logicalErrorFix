#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
int main() {
  int ta;
  scanf("%d", &ta);
  for (int ifa = 0; ifa < ta; ifa++) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) a[i] = abs(a[i]);
    const int INF = 2e9;
    std::vector<int> dm(n, INF);
    std::vector<int> dp(n, INF);
    std::vector<int> pp(n);
    std::vector<int> pm(n);
    dm[0] = -INF;
    dp[0] = -INF;
    pp[0] = 1;
    pm[0] = -1;
    for (int i = 0; i < n - 1; i++) {
      int to = a[i + 1];
      if (-to >= -a[i] && dm[i + 1] > dm[i]) {
        dm[i + 1] = dm[i];
        pm[i + 1] = -1;
      }
      if (-to >= dm[i] && dm[i + 1] > -a[i]) {
        dm[i + 1] = -a[i];
        pm[i + 1] = -1;
      }
      if (to >= -a[i] && dp[i + 1] > dm[i]) {
        dp[i + 1] = dm[i];
        pp[i + 1] = -1;
      }
      if (to >= dm[i] && dp[i + 1] > -a[i]) {
        dp[i + 1] = -a[i];
        pp[i + 1] = -1;
      }
      if (-to >= a[i] && dm[i + 1] > dp[i]) {
        dm[i + 1] = dp[i];
        pm[i + 1] = 1;
      }
      if (-to >= dp[i] && dm[i + 1] > a[i]) {
        dm[i + 1] = a[i];
        pm[i + 1] = 1;
      }
      if (to >= a[i] && dp[i + 1] > dp[i]) {
        dp[i + 1] = dp[i];
        pp[i + 1] = 1;
      }
      if (to >= dp[i] && dp[i + 1] > a[i]) {
        dp[i + 1] = a[i];
        pp[i + 1] = 1;
      }
    }
    int cur = n - 1;
    int sg = 0;
    if (dp[n - 1] != INF) sg = 1;
    if (dm[n - 1] != INF) sg = -1;
    if (sg == 0)
      printf("NO\n");
    else {
      while (cur >= 0) {
        a[cur] *= sg;
        if (sg > 0)
          sg = pp[cur--];
        else
          sg = pm[cur--];
      }
      printf("YES\n");
      for (int i = 0; i < n; i++) printf("%d ", a[i]);
      printf("\n");
    }
  }
}
