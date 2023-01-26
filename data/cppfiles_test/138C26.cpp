#include <bits/stdc++.h>
using namespace std;
inline long long md(long long m, long long v) { return ((v % m) + m) % m; }
struct DSU {
  vector<long long> p, have;
  DSU(long long n) {
    p.resize(n, -1);
    have.resize(n, 0);
  }
  long long gp(long long n) {
    if (p[n] < 0) return n;
    return p[n] = gp(p[n]);
  }
  void merge(long long a, long long b, long long to_b = 0) {
    a = gp(a), b = gp(b);
    if (a == b) return;
    p[b] += p[a];
    have[b] += have[a];
    p[a] = b;
  }
  bool is_merged(long long a, long long b) { return gp(a) == gp(b); }
  long long size(long long n) { return -p[gp(n)]; }
};
void solve() {
  long long n, m, q;
  cin >> n >> m >> q;
  vector<long long> arr, used(n + m);
  vector<long long> a(n), b(m), ans(q);
  for (auto &_ : (a)) cin >> _;
  for (auto &_ : (b)) cin >> _;
  sort((a).begin(), (a).end());
  sort((b).begin(), (b).end());
  for (long long i = 0, j = 0; (long long)(arr).size() < n + m;) {
    if (j == m || (i < n && a[i] < b[j])) {
      used[(long long)(arr).size()] = 1;
      arr.push_back(a[i]);
      i++;
    } else {
      arr.push_back(b[j]);
      j++;
    }
  }
  DSU dsu(n + m);
  for (long long i = 0; i < n + m; i++)
    if (used[i]) dsu.have[i] = 1;
  vector<pair<long long, long long> > query(q);
  for (long long i = 0; i < q; i++) cin >> query[i].first, query[i].second = i;
  sort((query).begin(), (query).end());
  1;
  1;
  long long cur = accumulate((a).begin(), (a).end(), 0LL);
  vector<long long> psum(n + m + 1);
  for (long long i = 0; i < n + m; i++) psum[i + 1] = psum[i] + arr[i];
  vector<pair<long long, long long> > merge_cand;
  for (long long i = 0; i < n + m - 1; i++) {
    merge_cand.push_back({arr[i + 1] - arr[i], i});
  }
  sort((merge_cand).begin(), (merge_cand).end());
  for (long long i = 0, j = 0; i < q; i++) {
    long long k = query[i].first;
    while (j < (long long)(merge_cand).size() && merge_cand[j].first <= k) {
      long long L = dsu.gp(merge_cand[j].second);
      long long LS = dsu.have[L];
      cur -= psum[L + 1] - psum[L + 1 - LS];
      long long R = dsu.gp(L + 1);
      long long RS = dsu.have[R];
      cur += psum[R - RS + 1] - psum[R - RS + 1 - LS];
      dsu.merge(L, R, 1);
      j++;
    }
    ans[query[i].second] = cur;
    1;
  }
  for (long long i = 0; i < q; i++) cout << ans[i] << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
