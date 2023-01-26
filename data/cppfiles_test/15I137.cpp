#include <bits/stdc++.h>
std::vector<int> V[110];
int count[110][110][110];
void func(int k, int prev, int top, int height) {
  count[k][top][height]++;
  for (int i = 0; i < V[k].size(); i++) {
    if (V[k][i] == prev) continue;
    func(V[k][i], k, top, height + 1);
  }
}
int x[110];
long long int DP[110][110];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= a; i++) V[i].clear();
    for (int i = 1; i <= a; i++)
      for (int j = 1; j <= a; j++)
        for (int k = 0; k <= a; k++) count[i][j][k] = 0;
    for (int i = 1; i < a; i++) {
      int c, d;
      scanf("%d%d", &c, &d);
      V[c].push_back(d);
      V[d].push_back(c);
    }
    if (b == 2) {
      printf("%d\n", a * (a - 1) / 2);
      continue;
    }
    for (int i = 1; i <= a; i++) func(i, 0, i, 0);
    long long int ans = 0;
    for (int i = 1; i <= a; i++) {
      if (V[i].size() >= b) {
        for (int j = 2; j <= b; j += 2) {
          int t = V[i].size();
          for (int k = 0; k < t; k++) x[k] = count[V[i][k]][i][j / 2];
          for (int k = 1; k <= b; k++) DP[t][k] = 0;
          DP[t][0] = 1;
          for (int l = t - 1; l >= 0; l--) {
            for (int k = 0; k <= b; k++) DP[l][k] = DP[l + 1][k];
            for (int k = 1; k <= b; k++)
              DP[l][k] += DP[l + 1][k - 1] * x[l], DP[l][k] %= 1000000007;
          }
          ans += DP[0][b], ans %= 1000000007;
        }
      }
    }
    printf("%lld\n", ans);
  }
}
