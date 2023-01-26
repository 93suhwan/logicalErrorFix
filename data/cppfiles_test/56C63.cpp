#include <bits/stdc++.h>
using namespace std;
long long orz = 1000000007LL;
int k, tot = 1;
struct node {
  long long no;
  int color;
  long long ans[7] = {0, 0, 0, 0, 0, 0, 0};
} tr[120005];
map<long long, int> vis;
bool cmp(node x, node y) { return x.no > y.no; }
long long qpower(long long a, long long b, long long p) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return ans;
}
long long p4[65];
long long power4(long long x) {
  int i = 0;
  while (x > 1) {
    x /= 2;
    i++;
  }
  return p4[k - i];
}
int main() {
  char color[10];
  int q;
  long long f, no, i, x, j, ttl, ttr, l, L, R, ttot;
  scanf("%d%d", &k, &q);
  for (i = 1; i <= k; i++) {
    p4[i] = qpower(4LL, (1LL << i) - 2LL, orz);
  }
  while (q--) {
    scanf("%lld%s", &no, color);
    tr[tot].no = no;
    if (color[0] == 'w') {
      tr[tot].color = 1;
    } else if (color[0] == 'y') {
      tr[tot].color = 6;
    } else if (color[0] == 'g') {
      tr[tot].color = 2;
    } else if (color[0] == 'b') {
      tr[tot].color = 5;
    } else if (color[0] == 'r') {
      tr[tot].color = 3;
    } else if (color[0] == 'o') {
      tr[tot].color = 4;
    }
    vis[no] = tot;
    tot++;
  }
  for (i = 1, ttot = tot; i < ttot; i++) {
    no = tr[i].no;
    do {
      no /= 2LL;
      if (vis.find(no) == vis.end()) {
        tr[tot].no = no;
        tr[tot].color = 100;
        vis[no] = tot;
        tot++;
      } else
        break;
    } while (no > 1);
  }
  sort(tr + 1, tr + tot, cmp);
  vis.clear();
  for (i = 1; i < tot; i++) vis[tr[i].no] = i;
  for (i = 1; i < tot; i++) {
    x = tr[i].no;
    L = vis[x * 2LL];
    R = vis[x * 2LL + 1LL];
    for (j = 1; j <= 6; j++) {
      if (tr[i].color != 100 && tr[i].color != j) continue;
      if (x >= (1LL << (k - 1))) {
        tr[i].ans[j] = 1;
      } else {
        ttl = 0;
        ttr = 0;
        for (l = 1; l <= 6; l++) {
          if (j == l || j + l == 7) continue;
          if (L == 0)
            ttl += power4(x * 2LL);
          else
            ttl += tr[L].ans[l];
          if (R == 0)
            ttr += power4(x * 2LL + 1);
          else
            ttr += tr[R].ans[l];
          ttl %= orz;
          ttr %= orz;
        }
        tr[i].ans[j] = ttl * ttr % orz;
      }
      tr[i].ans[0] += tr[i].ans[j];
    }
  }
  printf("%lld\n", tr[vis[1]].ans[0] % orz);
  return 0;
}
