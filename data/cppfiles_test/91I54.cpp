#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];
long long dp[2][MAXN];
const long long Mod = 998244353;
stack<int> S[4];
vector<int> V;
map<int, int> book;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    for (register int i = 1; i <= n; i++) cin >> a[i];
    int Last = 0;
    long long ans = 0;
    for (register int i = n; i >= 1; i--) {
      S[i & 1].push(a[i]);
      dp[i & 1][a[i]] = 1;
      book[a[i]] = 1;
      while (!S[(i & 1) ^ 1].empty()) {
        int x = S[(i & 1) ^ 1].top();
        V.push_back(x);
        S[(i & 1) ^ 1].pop();
        int p = (a[i] / ((a[i] + x - 1) / x));
        ans = (ans + ((i * (((a[i] + x - 1) / x) - 1) % Mod) *
                      dp[(i & 1) ^ 1][x] % Mod)) %
              Mod;
        dp[i & 1][p] = (dp[(i & 1) ^ 1][x] + dp[i & 1][p]) % Mod;
        if (book[p] == 0) {
          book[p] = 1;
          S[i & 1].push(p);
        }
      }
      book.clear();
      for (register int i = 0; i < V.size(); i++) dp[(i & 1) ^ 1][V[i]] = 0;
      V.clear();
    }
    while (!S[1].empty()) S[1].pop();
    while (!S[0].empty()) S[0].pop();
    printf("%lld\n", ans);
  }
  return 0;
}
