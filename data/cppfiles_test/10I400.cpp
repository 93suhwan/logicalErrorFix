#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
const int mod = 998244353;
int a[maxn], b[maxn];
vector<int> g[maxn];
int main() {
  int t, n, m, i, j, k, num1, num2;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    memset(b, 0, sizeof(n) * (n + 10));
    for (i = 0; i <= n; i++) g[i].clear();
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      g[a[i]].push_back(i);
    }
    int pos = 1;
    for (i = 1; i <= n; i++)
      if (g[i].size() >= k) {
        for (j = 0; j < k; j++) b[g[i][j]] = j + 1;
      } else {
        for (j = 0; j < g[i].size(); j++) {
          b[g[i][j]] = pos++;
          if (pos > k) pos -= k;
        }
      }
    for (i = n - 1; i >= 0; i--)
      if (pos != 1 && g[a[i]].size() < k && b[i] == pos - 1) {
        b[i] = 0;
        pos--;
      }
    for (i = 0; i < n; i++) printf("%d%c", b[i], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
