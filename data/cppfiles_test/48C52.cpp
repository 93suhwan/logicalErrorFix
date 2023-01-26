#include <bits/stdc++.h>
using namespace std;
void die(string S) {
  puts(S.c_str());
  exit(0);
}
long long x[100100], a[100100], b[100100];
long long psum[100100];
long long segtree[400400];
void upd(long long u, long long l, long long r, long long p, long long v) {
  if (l == r) {
    segtree[u] = v;
    return;
  }
  long long mid = (l + r) / 2;
  if (p <= mid)
    upd(u << 1, l, mid, p, v);
  else
    upd((u << 1) | 1, mid + 1, r, p, v);
  segtree[u] = max(segtree[u << 1], segtree[(u << 1) | 1]);
}
long long query(long long u, long long l, long long r, long long ll,
                long long rr) {
  if (l == ll && r == rr) return segtree[u];
  long long mid = (l + r) / 2;
  if (rr <= mid)
    return query(u << 1, l, mid, ll, rr);
  else if (ll > mid)
    return query((u << 1) | 1, mid + 1, r, ll, rr);
  else
    return max(query(u << 1, l, mid, ll, mid),
               query((u << 1) | 1, mid + 1, r, mid + 1, rr));
}
long long segtree2[400400];
void upd2(long long u, long long l, long long r, long long p, long long v) {
  if (l == r) {
    segtree2[u] = v;
    return;
  }
  long long mid = (l + r) / 2;
  if (p <= mid)
    upd2(u << 1, l, mid, p, v);
  else
    upd2((u << 1) | 1, mid + 1, r, p, v);
  segtree2[u] = max(segtree2[u << 1], segtree2[(u << 1) | 1]);
}
long long query2(long long u, long long l, long long r, long long ll,
                 long long rr) {
  if (l == ll && r == rr) return segtree2[u];
  long long mid = (l + r) / 2;
  if (rr <= mid)
    return query2(u << 1, l, mid, ll, rr);
  else if (ll > mid)
    return query2((u << 1) | 1, mid + 1, r, ll, rr);
  else
    return max(query2(u << 1, l, mid, ll, mid),
               query2((u << 1) | 1, mid + 1, r, mid + 1, rr));
}
signed main() {
  long long n, q;
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  for (long long i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] += b[i - 1];
  }
  for (long long i = 1; i <= n; i++) {
    upd(1, 1, n, i, a[i] - b[i]);
    upd2(1, 1, n, i, b[i] - a[i]);
  }
  while (q--) {
    long long l, r;
    cin >> l >> r;
    if (a[r] - a[l - 1] != b[r] - b[l - 1]) {
      puts("-1");
      continue;
    }
    long long delta = a[l - 1] - b[l - 1];
    if (query(1, 1, n, l, r) > delta) {
      puts("-1");
      continue;
    }
    cout << query2(1, 1, n, l, r) + delta << endl;
  }
  return 0;
}
