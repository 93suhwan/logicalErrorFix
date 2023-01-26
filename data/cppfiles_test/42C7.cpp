#include <bits/stdc++.h>
using namespace std;
const int N = 200000, P = 1000000007;
int n, m, c[N + 9], Ans;
struct Segment {
  int l, r;
} a[N + 9];
int ord[N + 9], rnk[N + 9], b[N + 9], pos[N + 9];
bool cmp(int o1, int o2) { return a[o1].r < a[o2].r; }
bool cmp1(int o1, int o2) { return a[ord[o1]].l < a[ord[o2]].l; }
int f[N + 9];
struct Bit {
  int t[N + 9];
  int lowbit(int x) { return x & -x; }
  void add(int pos, int x) {
    for (; pos; pos -= lowbit(pos)) t[pos] = (t[pos] + x) % P;
  }
  int query(int pos) {
    int res = 0;
    for (; pos <= n; pos += lowbit(pos)) res = (res + t[pos]) % P;
    return res;
  }
} sum;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].l, &a[i].r), ord[i] = i;
  sort(ord + 1, ord + 1 + n, cmp);
  for (int i = 1; i <= n; i++) rnk[ord[i]] = b[i] = i;
  sort(b + 1, b + 1 + n, cmp1);
  for (int i = 1; i <= n; i++) pos[b[i]] = i;
  for (int i = 1; i <= n; i++) sum.add(pos[i], f[i] = sum.query(pos[i]) + 1);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", c + i), c[i] = rnk[c[i]];
  sort(c + 1, c + 1 + m);
  for (int i = m, rbound = 0; i >= 1; i--)
    if (pos[c[i]] > rbound) {
      for (int j = rbound + 1; j <= pos[c[i]]; j++)
        if (b[j] <= c[i]) Ans = (Ans + f[b[j]]) % P;
      rbound = pos[c[i]];
    }
  printf("%d\n", Ans);
  return 0;
}
