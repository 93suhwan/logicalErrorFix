#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int T, n, x, y, A, B, C, d[N];
vector<int> v[N];
void dfs(int x, int y) {
  for (int i : v[x])
    if (i != y) dfs(i, x);
  if (x == 1) return;
  if (d[x] != 1) {
    B++;
    d[y]--;
  } else if (y == 1)
    A++;
  else
    C++;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &x, &y);
      v[x].push_back(y);
      v[y].push_back(x);
      d[x]++;
      d[y]++;
    }
    dfs(1, 0);
    printf("%d\n", max(A, 1) + C - B);
    A = B = C = 0;
    for (int i = 1; i <= n; i++) v[i].clear(), d[i] = 0;
  }
}
