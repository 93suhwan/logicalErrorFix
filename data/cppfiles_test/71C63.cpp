#include <bits/stdc++.h>
using namespace std;
vector<long long> g[11], f;
void dfs(long long num, int a, int b, int l, int mdl) {
  if (l == 0) {
    g[mdl].push_back(num);
    return;
  }
  dfs(num * 10 + a, a, b, l - 1, mdl);
  dfs(num * 10 + b, a, b, l - 1, mdl);
}
void init() {
  for (int i = 0; i <= 9; i++) {
    long long num = 0;
    for (int j = 1; j <= 10; j++) {
      num = num * 10 + i;
      g[j].push_back(num), f.push_back(num);
    }
  }
  for (int l = 1; l <= 10; l++) {
    for (int i = 0; i <= 9; i++)
      for (int j = i + 1; j <= 9; j++) dfs(0, i, j, l, l);
  }
  for (int l = 1; l <= 10; l++) sort(g[l].begin(), g[l].end());
}
int main() {
  init();
  int T;
  cin >> T;
  while (T--) {
    char s[12];
    long long o = 0;
    int k;
    scanf("%s", s + 1);
    int l = strlen(s + 1);
    for (int j = 1; j <= l; j++) o = o * 10 + (s[j] - '0');
    scanf("%d", &k);
    if (k == 1) {
      long long ans = 100000000000ll;
      for (int j = 0; j < f.size(); j++) {
        if (f[j] >= o) ans = min(ans, f[j]);
      }
      printf("%lld\n", ans);
    } else {
      for (int j = 0; j < g[l].size(); j++)
        if (g[l][j] >= o) {
          printf("%lld\n", g[l][j]);
          break;
        }
    }
  }
  return 0;
}
