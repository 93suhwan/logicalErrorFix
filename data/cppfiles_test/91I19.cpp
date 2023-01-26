#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];
long long dp[4][MAXN];
const long long Mod = 998244353;
queue<int> S[4];
vector<int> V;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    for (register int i = 1; i <= n; i++) cin >> a[i];
    long long ans = 0;
    for (register int i = n; i >= 1; i--) {
      S[i & 1].push(a[i]);
      dp[i & 1][a[i]] = 1;
      int Last = a[i];
      while (!S[(i & 1) ^ 1].empty()) {
        int x = S[(i & 1) ^ 1].front();
        V.push_back(x);
        S[(i & 1) ^ 1].pop();
        int p = (a[i] / ((a[i] + x - 1) / x));
        dp[i & 1][p] = (dp[(i & 1) ^ 1][x] + dp[i & 1][p]) % Mod;
        ans = (ans + ((i * (((a[i] + x - 1) / x) - 1) % Mod) *
                      dp[(i & 1) ^ 1][x] % Mod)) %
              Mod;
        if (p != Last) {
          Last = p;
          S[i & 1].push(p);
        }
      }
      for (register int j = 0; j < V.size(); j++) dp[(i & 1) ^ 1][V[j]] = 0;
      V.clear();
    }
    while (!S[1].empty()) S[1].pop();
    while (!S[0].empty()) S[0].pop();
    printf("%lld\n", ans);
  }
  return 0;
}
