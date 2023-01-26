#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long R = 998244353, R1 = 19491001, R2 = 236, NUMTESTCASE;
const long long NN = 10 + 1e5, Inverse2 = 500000004;
const double pi = acos(-1.0);
int di[8] = {1, 0, -1, 0, 1, -1, 1, -1}, dj[8] = {0, 1, 0, -1, 1, -1, -1, 1};
int n, Arr[NN];
pair<int, int> Dp[NN][2];
int Maps[2][NN], InvMaps[NN];
int main() {
  memset(InvMaps, -1, sizeof InvMaps);
  for (cin >> NUMTESTCASE; NUMTESTCASE; NUMTESTCASE--) {
    scanf("%d", &n);
    for (int i = (1); i <= (n); ++i) scanf("%d", Arr + i);
    int Ans = 0;
    for (long long i = 1; i <= n; i++)
      Ans = (Ans + 1ll * (n - i + 2) * (n - i + 1) / 2 % R) % R;
    Ans = (R - Ans) % R;
    for (int i = (n); i >= (1); --i) {
      InvMaps[Arr[i]] = 1;
      Maps[i & 1][0] = 1;
      Maps[i & 1][1] = Arr[i];
      Dp[Arr[i]][i & 1] = {1, 1};
      Ans = (Ans + 1) % R;
      for (int k = 1; k <= Maps[i & 1 ^ 1][0]; k++) {
        pair<int, pair<int, int>> p = {Maps[i & 1 ^ 1][k],
                                       Dp[Maps[i & 1 ^ 1][k]][i & 1 ^ 1]};
        int t = 0, Nxt = Arr[i], Cnt = p.second.second;
        if (Arr[i] <= p.first)
          t = 1;
        else
          t = (Arr[i] + p.first - 1) / p.first,
          Nxt = Arr[i] / ((Arr[i] + p.first - 1) / p.first);
        t = (1ll * t * Cnt % R + p.second.first) % R;
        Ans = (Ans + t) % R;
        int &Pos = InvMaps[Nxt];
        if (Pos == -1)
          Pos = ++Maps[i & 1][0], Maps[i & 1][Maps[i & 1][0]] = Nxt;
        Dp[Nxt][i & 1] = {(Dp[Nxt][i & 1].first + t) % R,
                          Dp[Nxt][i & 1].second + Cnt};
      }
      for (int k = (1); k <= (Maps[i & 1 ^ 1][0]); ++k)
        InvMaps[Maps[i & 1 ^ 1][k]] = -1,
                             Dp[Maps[i & 1 ^ 1][k]][i & 1 ^ 1] = {0, 0};
    }
    for (int k = (1); k <= (Maps[n & 1][0]); ++k)
      InvMaps[Maps[n & 1][k]] = -1, Dp[Maps[n & 1][k]][n & 1] = {0, 0};
    Maps[n & 1][0] = 0;
    for (int k = (1); k <= (Maps[n & 1 ^ 1][0]); ++k)
      InvMaps[Maps[n & 1 ^ 1][k]] = -1,
                           Dp[Maps[n & 1 ^ 1][k]][n & 1 ^ 1] = {0, 0};
    Maps[n & 1 ^ 1][0] = 0;
    printf("%d\n", Ans);
  }
  return 0;
}
