#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k, vis[N], b[N], l, vis1[N], vis2[N];
struct node {
  int v, num;
} a[N];
bool cmp(node x, node y) { return x.v < y.v; }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(vis, 0, sizeof vis);
    memset(vis1, 0, sizeof vis1);
    memset(vis2, 0, sizeof vis2);
    scanf("%d%d", &n, &k);
    l = n;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].v);
      a[i].num = i;
      vis[a[i].v]++;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
      if (vis[i] > k) {
        vis1[i] += vis[i] - k;
        l -= vis1[i];
      }
    int c = 1;
    for (int i = 1; i <= n; i++) {
      if (c > k) c = 1;
      if (vis1[a[i].v] > 0)
        vis1[a[i].v]--, b[a[i].num] = 0;
      else
        b[a[i].num] = c++;
    }
    if (l % k != 0)
      for (int i = 1; i <= n; i++) {
        if (vis2[b[i]] == l / k)
          b[i] = 0;
        else
          vis2[b[i]]++;
      }
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
    cout << endl;
  }
}
