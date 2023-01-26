#include <bits/stdc++.h>
using namespace std;
vector<int> g[101];
long long c[101][101];
int arr[101];
void f(int root, int parent, int k) {
  arr[k]++;
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
  long long ans;
  scanf("%d", &t);
  for (; t > 0; t--) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
      scanf("%d %d", &a, &b);
      g[a].push_back(b);
      g[b].push_back(a);
    }
    if (k == 1)
      printf("%d\n", n);
    else if (k == 2)
      printf("%lld\n", (long long)n * (long long)(n - 1) / 2);
    else {
      ans = 0;
      for (int i = 1; i <= n; i++) {
        memset(arr, 0, sizeof(arr));
        f(i, i, 0);
        for (int j = 1; j <= n; j++)
          if (arr[j] >= k) ans = (ans + c[arr[j]][k]) % 1000000007;
      }
      printf("%lld\n", ans);
    }
    for (int i = 1; i <= n; i++) g[i].clear();
  }
  return 0;
}
