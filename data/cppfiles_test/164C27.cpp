#include <bits/stdc++.h>
using namespace std;
int T[200010][2], tid[200010], deep[200010];
char s[200010], t[200010];
bool mark[200010], mark2[200010];
int n, k, idx;
void DFS(int u) {
  if (T[u][0]) {
    deep[T[u][0]] = deep[u] + 1;
    DFS(T[u][0]);
  }
  tid[++idx] = u;
  t[idx] = s[u];
  if (T[u][1]) {
    deep[T[u][1]] = deep[u] + 1;
    DFS(T[u][1]);
  }
}
bool DFS2(int u, int top) {
  bool flag = false;
  if (T[u][0]) {
    if (DFS2(T[u][0], top)) flag = true;
  }
  if (flag) mark2[u] = true;
  if (mark[u] && !flag) {
    if (deep[u] - deep[top] + 1 <= k) {
      k -= (deep[u] - deep[top] + 1);
      mark2[u] = true;
      flag = true;
    }
  }
  if (T[u][1] && flag) DFS2(T[u][1], T[u][1]);
  return flag;
}
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &T[i][0], &T[i][1]);
  DFS(1);
  int p = n;
  for (int i = n; i >= 1; --i) {
    if (t[p] > t[i]) mark[tid[i]] = true;
    if (t[i - 1] != t[i]) p = i;
  }
  DFS2(1, 1);
  for (int i = 1; i <= n; ++i) {
    printf("%c", t[i]);
    if (mark2[tid[i]]) printf("%c", t[i]);
  }
  printf("\n");
  return 0;
}
