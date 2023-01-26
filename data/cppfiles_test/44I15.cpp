#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int absv(int x) { return x < 0 ? -x : x; }
int n, x[2005], G[2005][2005];
char S[2005][2005];
bool dfs(int v, int c) {
  if (x[v] == !c)
    return false;
  else if (x[v] == c)
    return true;
  x[v] = c;
  for (int i = 0; i < (int)(n + 1); i++)
    if (G[v][i] != -1 && !dfs(i, c ^ G[v][i])) return false;
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); i++) scanf("%s", S[i]);
  if (n & 1) {
    printf("NONE\n");
    return 0;
  }
  for (int i = 0; i < (int)(n + 1); i++)
    for (int j = 0; j < (int)(n + 1); j++) G[i][j] = -1;
  for (int i = 0; i < n; i += 2) G[i][i + 2] = G[i + 2][i] = 1;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++)
      if (S[i][j] != '.') {
        int val = (S[i][j] == 'S') ^ (i & 1) ^ (j & 1);
        int d0 = absv(i - j), d1 = absv(i + j - n + 1);
        G[d0][n - d1] = G[n - d1][d0] = val;
      }
  for (int i = 0; i < (int)(n + 1); i++) x[i] = -1;
  int cnt = 0;
  for (int i = 0; i < (int)(n + 1); i++)
    if (x[i] == -1) {
      cnt++;
      if (!dfs(i, 0)) {
        printf("NONE\n");
        return 0;
      }
    }
  if (cnt >= 2)
    printf("MULTIPLE\n");
  else {
    for (int i = 0; i < (int)(n); i++)
      for (int j = 0; j < (int)(n); j++)
        S[i][j] =
            (i & 1) ^ (j ^ 1) ^ x[absv(i - j)] ^ x[n - absv(i + j - n + 1)]
                ? 'S'
                : 'G';
    printf("UNIQUE\n");
    for (int i = 0; i < (int)(n); i++) printf("%s\n", S[i]);
  }
  return 0;
}
