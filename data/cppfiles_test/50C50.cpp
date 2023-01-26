#include <bits/stdc++.h>
using namespace std;
const long long P = 998244353;
int N;
long long A[200009];
long long dp[200009][2];
long long s[200009][2];
long long res;
void In() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
}
inline long long Mod(long long x) { return ((x % P) + P) % P; }
void Solve() {
  int stk[200009];
  int tt = 0;
  int t;
  dp[0][0] = s[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    while (tt && A[stk[tt]] >= A[i]) tt--;
    t = stk[tt];
    if (!tt)
      dp[i][0] = Mod(s[i - 1][1] * A[i]), dp[i][1] = Mod(s[i - 1][0] * A[i]);
    else
      dp[i][0] = Mod(dp[t][0] + Mod(A[i] * Mod(s[i - 1][1] - s[t - 1][1]))),
      dp[i][1] = Mod(dp[t][1] + Mod(A[i] * Mod(s[i - 1][0] - s[t - 1][0])));
    s[i][0] = Mod(s[i - 1][0] + dp[i][0]),
    s[i][1] = Mod(s[i - 1][1] + dp[i][1]);
    stk[++tt] = i;
  }
}
void Out() {
  printf("%lld\n", Mod((dp[N][0] - dp[N][1]) * ((N & 1) ? -1ll : 1ll)));
}
int main() {
  In();
  Solve();
  Out();
  return 0;
}
