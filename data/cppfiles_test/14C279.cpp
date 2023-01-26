#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1000;
long long n, m;
struct node {
  int a, b;
  bool friend operator<(node a, node b) {
    if (a.a == b.a) return a.b < b.b;
    return a.a < b.a;
  }
} save[maxn];
int st[maxn];
int s = 0;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &save[i].b);
      save[i].a = i - save[i].b;
    }
    sort(save + 1, save + 1 + n);
    int ans = 1e9 + 7, s = 0;
    int i;
    for (i = 1; i <= n; i++)
      if (save[i].a >= 0) break;
    for (int k = i; k <= n; k++) {
      if (!s || save[k].b > st[s])
        st[++s] = save[k].b;
      else {
        int pos = lower_bound(st + 1, st + 1 + s, save[k].b) - st;
        st[pos] = save[k].b;
      }
      if (s >= m) {
        ans = min(ans, save[k].a);
        break;
      }
    }
    if (ans == 1e9 + 7)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
