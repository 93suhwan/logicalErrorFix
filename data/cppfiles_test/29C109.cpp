#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 7;
struct nd {
  long long coeff, frq;
  long long sum;
};
nd tr[4 * MAXN];
long long lazy[4 * MAXN];
nd combine(const nd &a, const nd &b) {
  nd rt;
  rt.coeff = a.coeff + b.coeff;
  rt.frq = a.frq + b.frq;
  rt.sum = a.sum + b.sum;
  return rt;
}
void propagate(int u, int l, int r) {
  if (lazy[u]) {
    tr[u].sum += lazy[u] * tr[u].frq;
    tr[u].coeff += lazy[u];
    if (l != r) {
      lazy[u * 2] += lazy[u];
      lazy[u * 2 + 1] += lazy[u];
    }
    lazy[u] = 0;
  }
}
void update(int u, int l, int r, int x, int y, long long v) {
  propagate(u, l, r);
  if (r < x || y < l) return;
  if (x <= l && r <= y) {
    lazy[u] += v;
    propagate(u, l, r);
    return;
  }
  int mid = (l + r) / 2;
  update(u * 2, l, mid, x, y, v);
  update(u * 2 + 1, mid + 1, r, x, y, v);
  tr[u] = combine(tr[u * 2], tr[u * 2 + 1]);
}
void update(int u, int l, int r, int idx) {
  propagate(u, l, r);
  if (r < idx || idx < l) return;
  if (l == r) {
    tr[u].frq++;
    tr[u].sum += tr[u].coeff;
    return;
  }
  int mid = (l + r) / 2;
  update(u * 2, l, mid, idx);
  update(u * 2 + 1, mid + 1, r, idx);
  tr[u] = combine(tr[u * 2], tr[u * 2 + 1]);
}
nd query(int u, int l, int r, int x, int y) {
  propagate(u, l, r);
  if (x <= l && r <= y) return tr[u];
  int mid = (l + r) / 2;
  if (y <= mid) return query(u * 2, l, mid, x, y);
  if (mid < x) return query(u * 2 + 1, mid + 1, r, x, y);
  return combine(query(u * 2, l, mid, x, y),
                 query(u * 2 + 1, mid + 1, r, x, y));
}
long long a[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  long long presum = 0;
  for (int k = 1; k <= n; k++) {
    for (int x = a[k]; x <= mx; x += a[k]) {
      update(1, 1, mx, x, mx, a[k]);
    }
    update(1, 1, mx, a[k]);
    presum += a[k];
    cout << presum * k - tr[1].sum << " ";
  }
  return 0;
}
