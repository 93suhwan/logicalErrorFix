#include <bits/stdc++.h>
using namespace std;
int l[200005], r[200005];
int fa[200005][20];
char s[200005];
char ss[200005];
int pos[200005];
int ok[200005];
int re[200005];
int nn;
void dfs(int i) {
  if (i == 0) return;
  dfs(l[i]);
  pos[nn] = i;
  ss[nn++] = s[i];
  dfs(r[i]);
}
void dfs2(int i) {
  if (i == 0) return;
  dfs(l[i]);
  if (re[i]) ss[nn++] = s[i];
  ss[nn++] = s[i];
  dfs(r[i]);
}
int main() {
  int n, k;
  cin >> n >> k;
  cin >> (s + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", l + i, r + i);
    if (l[i]) fa[l[i]][0] = i;
    if (r[i]) fa[r[i]][0] = i;
  }
  for (int j = 1; j < 20; j++)
    for (int i = 1; i <= n; i++) {
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
  dfs(1);
  {
    int i = n - 1;
    char last = ss[n - 1];
    while (ss[i] == ss[n - 1] && i >= 0) i--;
    for (; i >= 0; i--) {
      if (ss[i] == ss[i + 1]) {
      } else {
        last = ss[i + 1];
      }
      if (ss[i] < last) ok[i] = 1;
    }
  }
  for (int i = 0; i < n; i++)
    if (ok[i]) {
      int now = pos[i];
      int num = 1;
      for (int j = 19; j >= 0; j--) {
        if (fa[now][j] != 0 && re[fa[now][j]] != 1) {
          now = fa[now][j];
          num += (1 << j);
        }
      }
      if (num <= k) {
        k -= num;
        re[now] = 1;
        cout << "ok" << endl;
        for (int ii = pos[i]; ii != now; ii = fa[ii][0]) {
          re[ii] = 1;
        }
      }
    }
  nn = 0;
  dfs2(1);
  cout << ss << endl;
  return 0;
}
