#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
const int mod = 1e9 + 7;
const int N = 200010, M = 200030;
long double eps = 1e-8;
double PI = acos(-1.0);
int t;
int n, m, k;
int vis[N];
int main() {
  scanf("%d%d", &n, &m);
  int ans = n;
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    int minn = min(a, b);
    vis[minn]++;
    if (vis[minn] == 1) ans--;
  }
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    int op;
    int a, b;
    scanf("%d", &op);
    if (op == 3)
      printf("%d\n", ans);
    else if (op == 1) {
      scanf("%d%d", &a, &b);
      int minn = min(a, b);
      vis[minn]++;
      if (vis[minn] == 1) ans--;
    } else {
      scanf("%d%d", &a, &b);
      int minn = min(a, b);
      vis[minn]--;
      if (vis[minn] == 0) ans++;
    }
  }
  return 0;
}
