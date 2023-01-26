#include <bits/stdc++.h>
using namespace std;
long long a[1000005], b[1000005], c[1000005], treemx[4000005], treemn[4000005];
void build(int k, int l, int r) {
  if (l == r) {
    treemx[k] = treemn[k] = c[l];
    return;
  }
  int mid = (l + r) / 2;
  build(2 * k, l, mid);
  build(2 * k + 1, mid + 1, r);
  treemx[k] = max(treemx[2 * k], treemx[2 * k + 1]);
  treemn[k] = min(treemn[2 * k], treemn[2 * k + 1]);
}
long long askmx(int k, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) return treemx[k];
  int mid = (l + r) / 2;
  long long mx = -1e18;
  if (mid >= ll) mx = max(mx, askmx(2 * k, l, mid, ll, rr));
  if (mid < rr) mx = max(mx, askmx(2 * k + 1, mid + 1, r, ll, rr));
  return mx;
}
long long askmn(int k, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) return treemn[k];
  int mid = (l + r) / 2;
  long long mn = 1e18;
  if (mid >= ll) mn = min(mn, askmn(2 * k, l, mid, ll, rr));
  if (mid < rr) mn = min(mn, askmn(2 * k + 1, mid + 1, r, ll, rr));
  return mn;
}
void solve() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
  for (int i = 1; i <= n; i++) {
    c[i] = c[i - 1] + b[i] - a[i];
  }
  build(1, 1, n);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (askmn(1, 1, n, l, r) == c[l - 1] && c[r] == c[l - 1]) {
      printf("%lld\n", askmx(1, 1, n, l, r) - c[l - 1]);
    } else
      printf("-1\n");
  }
}
int main() { solve(); }
