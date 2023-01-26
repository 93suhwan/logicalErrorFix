#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 2 * N;
int e[M], ne[M], h[N];
int idx = 0;
int ans = 0;
void add(int a, int b) {
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx++;
  return;
}
int dfs(int u, int fa) {
  int sum = 0;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int son = e[i];
    if (son == fa) continue;
    sum += dfs(son, u);
  }
  if (sum == 0)
    return 1;
  else {
    ans += sum - 1;
    return 0;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    idx = 0;
    ans = 0;
    int n;
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      add(u, v);
      add(v, u);
    }
    dfs(1, 0);
    printf("%d\n", ans + 1);
  }
}
