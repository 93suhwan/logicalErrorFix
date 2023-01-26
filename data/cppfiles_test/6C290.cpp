#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 200004;
const int INF = 0x3f3f3f3f;
int vis[MAXN];
vector<int> g[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  int m;
  scanf("%d", &m);
  int u, v, cnt = 0;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &u);
    scanf("%d", &v);
    if (++vis[min(u, v)] == 1) ++cnt;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 3) {
      printf("%d\n", n - cnt);
    } else {
      scanf("%d", &u);
      scanf("%d", &v);
      if (op == 2) {
        if (--vis[min(u, v)] == 0) --cnt;
      } else {
        if (++vis[min(u, v)] == 1) ++cnt;
      }
    }
  }
  return 0;
}
