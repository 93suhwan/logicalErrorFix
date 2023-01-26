#include <bits/stdc++.h>
using namespace std;
vector<int> g[101];
vector<long long> v[101];
bool check[101];
long long c[101][101];
void f(int root, int parent, int k) {
  if (!check[k]) {
    v[k].push_back(1);
    check[k] = true;
  } else
    v[k].back()++;
  for (int i = 0; i < g[root].size(); i++)
    if (g[root][i] != parent) f(g[root][i], root, k + 1);
}
int main() {
  c[0][0] = 1;
  for (int i = 1; i <= 100; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
  }
  int t, n, k, a, b;
  long long ans, temp;
  scanf("%d", &t);
  for (; t > 0; t--) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
      scanf("%d %d", &a, &b);
      g[a].push_back(b);
      g[b].push_back(a);
    }
    if (k == 2)
      printf("%d\n", n * (n - 1) / 2);
    else {
      ans = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
          memset(check, false, sizeof(check));
          f(g[i][j], i, 1);
        }
        for (int j = 1; j <= n; j++) {
          temp = 1;
          for (int r = 0; r < (int)v[j].size(); r++)
            temp = temp * v[j][r] % 1000000007;
          ans = (ans + temp * c[(int)v[j].size()][k]) % 1000000007;
          v[j].clear();
        }
      }
      printf("%lld\n", ans);
    }
    for (int i = 1; i <= n; i++) g[i].clear();
  }
  return 0;
}
