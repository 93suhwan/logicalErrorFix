#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
using namespace std;
int ara[2003], mem[2003][2003];
bool vis[2003][2003];
int dp(int pos, int cnt) {
  if (pos == -1 || cnt == 0) return 0;
  int &ret = mem[pos][cnt];
  if (vis[pos][cnt]) return ret;
  vis[pos][cnt] = 1;
  return ret = max(dp(pos - 1, cnt), (ara[pos] == cnt) + dp(pos - 1, cnt - 1));
}
int main() {
  int ts;
  scanf("%d", &ts);
  while (ts--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &ara[i]);
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++) vis[i][j] = 0;
    int res = 1e7;
    for (int i = n - 1; i >= k - 1; i--)
      for (int j = i + 1; j >= k; j--)
        if (dp(i, j) >= k) res = min(res, (i + 1) - j);
    if (res >= 1e7) res = -1;
    printf("%d\n", res);
  }
  return 0;
}
