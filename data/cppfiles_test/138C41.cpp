#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
struct node1 {
  long long val;
  int tp;
};
struct node2 {
  long long val;
  long long ans;
  int id;
};
struct node3 {
  long long val;
  int l;
  int r;
};
node1 ary[maxn];
node2 syt[maxn];
node3 cha[maxn];
long long sum[maxn];
int f[maxn], cnt[maxn];
int n, m, q;
bool cmpI(node1 n1, node1 n2) { return n1.val < n2.val; }
bool cmpII(node2 n1, node2 n2) { return n1.val < n2.val; }
bool cmpIII(node2 n1, node2 n2) { return n1.id < n2.id; }
bool cmpIV(node3 n1, node3 n2) { return n1.val < n2.val; }
int getf(int p) {
  if (f[p] == p)
    return p;
  else
    return f[p] = getf(f[p]);
}
long long unite(int u, int v) {
  long long res;
  int fu, fv;
  fu = getf(u);
  fv = getf(v);
  if (fu != fv) {
    res = -((sum[fu] - sum[fu - cnt[fu]]) + (sum[fv] - sum[fv - cnt[fv]]));
    f[fu] = fv;
    cnt[fv] += cnt[fu];
    res += sum[fv] - sum[fv - cnt[fv]];
  }
  return res;
}
int main() {
  long long gou;
  int i, j;
  scanf("%d%d%d", &n, &m, &q);
  gou = 0;
  for (i = 1; i <= n; i++) {
    scanf("%lld", &ary[i].val);
    ary[i].tp = 1;
    gou += ary[i].val;
  }
  for (i = n + 1; i <= n + m; i++) {
    scanf("%lld", &ary[i].val);
    ary[i].tp = 0;
  }
  sort(ary + 1, ary + n + m + 1, cmpI);
  for (i = 1; i + 1 <= n + m; i++) {
    cha[i].val = ary[i + 1].val - ary[i].val;
    cha[i].l = i, cha[i].r = i + 1;
  }
  sort(cha + 1, cha + n + m, cmpIV);
  for (i = 1; i <= q; i++) {
    scanf("%lld", &syt[i].val);
    syt[i].id = i;
  }
  sort(syt + 1, syt + q + 1, cmpII);
  for (i = 1; i <= n + m; i++) {
    sum[i] = sum[i - 1] + ary[i].val;
    f[i] = i;
    cnt[i] = ary[i].tp;
  }
  j = 1;
  for (i = 1; i <= q; i++) {
    while (j <= n + m - 1 && cha[j].val <= syt[i].val) {
      gou += unite(cha[j].l, cha[j].r);
      j++;
    }
    syt[i].ans = gou;
  }
  sort(syt + 1, syt + q + 1, cmpIII);
  for (i = 1; i <= q; i++) {
    printf("%lld\n", syt[i].ans);
  }
  return 0;
}
