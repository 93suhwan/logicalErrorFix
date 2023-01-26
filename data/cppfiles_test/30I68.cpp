#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int INF = 1e9;
int n;
int a[MAXN];
char str[MAXN];
bool vis[26][MAXN];
int solve(int c) {
  int mid1, mid2;
  int ret = 0;
  for (int l = 1, r = n; l <= r; l++, r--) {
    while (a[l] == c) l++;
    while (a[r] == c) r--;
    ret += 2;
    mid1 = l, mid2 = r;
    if (a[l] != a[r]) {
      return 0;
    }
  }
  if (mid1 == mid2) {
    ret--;
    for (int i = mid1 - 1; i > 1; --i) {
      int nxt = 2 * mid1 - i;
      if (nxt > n) break;
      if (vis[c][i] && vis[c][nxt]) ret += 2;
    }
  } else {
    ret += (mid2 - mid1 - 1);
    for (int i = mid1 - 1; i > 1; --i) {
      int nxt = mid2 + (mid1 - i);
      if (nxt > n) break;
      if (vis[c][i] && vis[c][nxt]) ret += 2;
    }
  }
  return ret;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; ++i) {
      a[i] = str[i] - 'a';
      vis[a[i]][i] = true;
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      ans = max(ans, solve(i));
    }
    printf("%d\n", ans == 0 ? -1 : n - ans);
  }
}
