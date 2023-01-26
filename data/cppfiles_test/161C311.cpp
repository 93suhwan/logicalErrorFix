#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, vis[N];
struct w {
  int l, r, x;
} e[N];
bool cmp(w x, w y) { return x.r - x.l > y.r - y.l; }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &e[i].l, &e[i].r);
    for (int i = 1; i <= n; i++) vis[i] = 0;
    sort(e + 1, e + n + 1, cmp);
    for (int i = n; i >= 1; i--) {
      for (int j = e[i].l; j <= e[i].r; j++) {
        if (!vis[j]) printf("%d %d %d\n", e[i].l, e[i].r, j);
        vis[j] = 1;
      }
    }
  }
}
