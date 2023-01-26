#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
int n, m, q, l = 1, a[1000010], b[1000010], vis[1000010], fa[1000010];
long long sum, s[1000010], ans[1000010];
struct node {
  long long val, id;
} c[1000010], k[1000010], cha[1000010];
bool cmp(node a, node b) { return a.val < b.val; }
int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  sum -= s[x] - s[x - vis[x]], sum -= s[y] - s[y - vis[y]];
  vis[x] += vis[y], fa[y] = x, sum += s[x] - s[x - vis[x]];
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), c[i].val = a[i], c[i].id = 1, sum += a[i];
  for (int i = 1; i <= m; i++)
    scanf("%d", &b[i]), c[i + n].val = b[i], c[i + n].id = 0;
  for (int i = 1; i <= q; i++) scanf("%lld", &k[i].val), k[i].id = i;
  sort(c + 1, c + n + m + 1, cmp), sort(k + 1, k + q + 1, cmp);
  for (int i = 1; i <= n + m; i++)
    fa[i] = i, cha[i].val = c[i].val - c[i - 1].val, cha[i].id = i,
    vis[i] = c[i].id, s[i] = s[i - 1] + c[i].val;
  sort(cha + 1, cha + n + m + 1, cmp);
  for (int i = 1; i <= q; i++) {
    while (l <= n + m && cha[l].val <= k[i].val)
      merge(cha[l].id, cha[l].id - 1), l++;
    ans[k[i].id] = sum;
  }
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
  return 0;
}
