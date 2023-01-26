#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 10, N = 260, M = 5e6 + 10;
constexpr int MAX_INF = 0x3f3f3f3f;
int mp[maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int root = 0;
    memset(mp, 0, sizeof(mp));
    while (m--) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      mp[b] = 1;
    }
    for (int i = 1; i <= n; i++) {
      if (!mp[i]) {
        root = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i == root) continue;
      printf("%d %d\n", i, root);
    }
  }
}
