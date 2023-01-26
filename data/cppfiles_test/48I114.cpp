#include <bits/stdc++.h>
using namespace std;
void die(string S) {
  puts(S.c_str());
  exit(0);
}
long long x[100100];
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
  segtree[u] = min(segtree[u << 1], segtree[(u << 1) | 1]);
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
    return min(query(u << 1, l, mid, ll, mid),
               query((u << 1) | 1, mid + 1, r, mid + 1, rr));
}
long long X[100100];
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
  for (long long i = 1; i <= n; i++) cin >> x[i];
  for (long long i = 1; i <= n; i++) {
    long long y;
    cin >> y;
    x[i] = y - x[i];
  }
  for (long long i = 1; i <= n; i++) {
    psum[i] = psum[i - 1] + x[i];
    upd(1, 1, n, i, psum[i]);
  }
  long long lst = 1, cur = 0;
  vector<pair<pair<long long, long long>, long long> > v;
  for (long long i = 1; i <= n; i++)
    if (x[i]) {
      if (!cur)
        cur = (x[i] > 0) + 1;
      else if (cur != (x[i] > 0) + 1) {
        v.push_back(
            make_pair(make_pair(lst, i - 1), abs(psum[i - 1] - psum[lst - 1])));
        cur = (x[i] > 0) + 1;
        lst = i;
      }
    }
  for (long long i = 0; i < (long long)(v.size()); i++)
    upd2(1, 0, (long long)(v.size()) - 1, i, v[i].second);
  while (q--) {
    long long l, r;
    cin >> l >> r;
    if (query(1, 1, n, l, r) < psum[l - 1]) {
      puts("-1");
      continue;
    }
    if (psum[r] ^ psum[l - 1]) {
      puts("-1");
      continue;
    }
    long long fst =
        lower_bound((v).begin(), (v).end(), make_pair(make_pair(l, 0ll), 0ll)) -
        v.begin();
    long long lst = lower_bound((v).begin(), (v).end(),
                                make_pair(make_pair(r, r), 1000000000ll)) -
                    v.begin() - 1;
    if (fst > lst) {
      cout << psum[r] - psum[l - 1] << endl;
      continue;
    }
    long long ans = query2(1, 0, (long long)(v.size()) - 1, fst, lst);
    ans = max(ans, abs(psum[v[fst].first.first] - psum[l - 1]));
    ans = max(ans, abs(psum[r] - psum[v[lst].first.second]));
    cout << ans << endl;
  }
  return 0;
}
