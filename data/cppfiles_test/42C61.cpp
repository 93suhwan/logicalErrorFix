#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 7;
const int mod = 1e9 + 7;
int add(int x, int y) { return (x += y) < mod ? x : x - mod; }
int n;
struct BIT {
  int t[MAXN];
  void insert(int k, int w) {
    for (; k < MAXN; k += (k & (-k))) t[k] = add(t[k], w);
  }
  int ask(int k) {
    int res = 0;
    for (; k; k -= (k & (-k))) res = add(res, t[k]);
    return res;
  }
  void clear() { memset(t, 0, sizeof(t)); }
} T;
struct node {
  int l, r, f, id;
  bool operator<(const node &p) const { return l < p.l; }
} a[MAXN];
int pos[MAXN];
bool cmp(int x, int y) { return a[x].r < a[y].r; }
int s[MAXN], l, r, top;
int solve(int p) {
  while (l <= r && a[s[r]].l < p) --r;
  if (l > r) return 0;
  int res = 0;
  while (top <= n && a[top].l < p) T.insert(a[top].r, mod - a[top].f), ++top;
  res = add(res, T.ask(a[s[r]].r - 1));
  int nxt = a[s[r--]].l;
  return add(res + 1, solve(nxt));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].l, &a[i].r), a[i].id = i;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) pos[a[i].id] = i;
  for (int i = n; i; --i) {
    a[i].f = add(1, T.ask(a[i].r));
    T.insert(a[i].r, a[i].f);
  }
  l = 1, scanf("%d", &r);
  T.clear();
  for (int i = 1; i <= r; ++i) scanf("%d", &s[i]), s[i] = pos[s[i]];
  top = 1;
  for (int i = 1; i <= n; ++i) T.insert(a[i].r, a[i].f);
  sort(s + 1, s + r + 1, cmp);
  printf("%d\n", solve(1));
}
