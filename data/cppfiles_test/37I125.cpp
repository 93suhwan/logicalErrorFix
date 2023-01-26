#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 50;
const long long mm = 998244353;
int n, m, ans, T;
long long f[maxn];
vector<int> tr[maxn];
long long dfs1(int x, int fa) {
  long long tot = 1;
  for (int i = 0; i < tr[x].size(); ++i)
    if (tr[x][i] != fa) tot = tot * dfs1(tr[x][i], x) * 2 % mm;
  return tot;
}
int dfs(int x, int fa, int z) {
  int tot = 0;
  for (int i = 0; i < tr[x].size(); ++i)
    if (tr[x][i] != fa)
      if (tr[tr[x][i]].size() % z == 0)
        ;
      else if (tr[tr[x][i]].size() % z == z - 1)
        ++tot;
      else
        return 0;
  if (tot % z == 0 || tot % z == z - 1)
    ;
  else
    return 0;
  for (int i = 0; i < tr[x].size(); ++i)
    if (tr[x][i] != fa)
      if (!dfs(tr[x][i], x, z)) return 0;
  return 1;
}
int main() {
  scanf("%d", &T);
  for (int oo = 1; oo <= T; ++oo) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      while (!tr[i].empty()) tr[i].pop_back();
    for (int i = 1; i < n; ++i) {
      int q1, q2;
      scanf("%d%d", &q1, &q2);
      tr[q1].push_back(q2);
      tr[q2].push_back(q1);
    }
    for (int i = 1; i <= n; ++i) f[i] = 0;
    f[1] = dfs1(1, 1);
    for (int i = n - 1; i > 1; --i)
      if ((n - 1) % i == 0 && !f[i]) {
        f[i] += dfs(1, 1, i);
        if (f[i])
          for (int j = 1; j * j <= i; ++j) f[j] -= f[i];
      }
    for (int i = 1; i <= n; ++i)
      if (f[i] >= 0)
        printf("%d ", (f[i] + mm) % mm);
      else
        printf("0 ");
    printf("\n");
  }
  return 0;
}
