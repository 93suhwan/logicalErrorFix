#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, fg, tim;
} p[200007];
struct nod {
  int fu, mint;
} f[200007];
int cmp(node a, node b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
int cmp1(node a, node b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}
int cmp3(int a, int b) { return a > b; }
int find(int a) {
  if (f[a].fu == a) return a;
  return f[a].fu = f[f[a].fu].fu;
}
int main() {
  int t, n, k;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].tim);
      p[i].fg = i;
      f[i].fu = i;
      f[i].mint = p[i].tim;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 2; i <= n; i++) {
      if (p[i].x == p[i - 1].x) {
        if (p[i].y - p[i - 1].y <= k) {
          int o = find(p[i - 1].fg);
          int op = find(p[i].fg);
          f[op].fu = o;
          f[o].mint = min(f[o].mint, f[op].mint);
        }
      }
    }
    sort(p + 1, p + n + 1, cmp1);
    for (int i = 2; i <= n; i++) {
      if (p[i].y == p[i - 1].y) {
        if (p[i].x - p[i - 1].x <= k) {
          int o = find(p[i - 1].fg);
          int op = find(p[i].fg);
          f[op].fu = o;
          f[o].mint = min(f[o].mint, f[op].mint);
        }
      }
    }
    vector<int> timm;
    for (int i = 1; i <= n; i++) {
      if (f[i].fu == i) timm.push_back(f[i].mint);
    }
    sort(timm.begin(), timm.end(), cmp3);
    int ans = 0;
    for (int i = 1; i < (int)timm.size(); i++) {
      if (timm[i] <= ans)
        break;
      else {
        ans++;
        for (; i != timm.size() && timm[i] == timm[i + 1]; ++i)
          ;
      }
    }
    printf("%d\n", ans);
  }
}
