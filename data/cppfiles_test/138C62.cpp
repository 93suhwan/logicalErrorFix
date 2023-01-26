#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct dbg {
  template <class c>
  dbg& operator<<(const c&) {
    return *this;
  }
};
const int MX = 4e5;
int a[MX], b[MX], c[MX], n, m, q;
int lo[MX], hi[MX], sz[MX], cnt[MX], par[MX];
long long ans = 0;
long long pre[MX], out[MX];
long long rng(int l, int r) {
  long long ret = pre[r];
  if (l > 0) ret -= pre[l - 1];
  return ret;
}
int get_par(int i) { return (i == par[i] ? i : par[i] = get_par(par[i])); }
void join(int i, int j) {
  i = get_par(i), j = get_par(j);
  if (i == j) return;
  if (sz[i] > sz[j]) swap(i, j);
  ans -= rng(hi[i] - cnt[i] + 1, hi[i]);
  ans -= rng(hi[j] - cnt[j] + 1, hi[j]);
  lo[j] = min(lo[i], lo[j]);
  hi[j] = max(hi[j], hi[i]);
  cnt[j] += cnt[i];
  ans += rng(hi[j] - cnt[j] + 1, hi[j]);
  par[i] = j;
}
void fun() {
  cin >> n >> m >> q;
  iota(par, par + n + m, 0);
  iota(lo, lo + n + m, 0);
  iota(hi, hi + n + m, 0);
  for (int i = 0; i < (int)n; i++) {
    cin >> a[i];
    ans += a[i];
    c[i] = a[i];
  }
  for (int i = 0; i < (int)m; i++) {
    cin >> b[i];
    c[n + i] = b[i];
  }
  sort(c, c + n + m);
  sort(a, a + n);
  for (int i = 0; i < (int)n + m; i++) {
    pre[i] = c[i] + (i > 0 ? pre[i - 1] : 0);
    sz[i] = 1;
  }
  int jc = 0;
  for (int i = 0; i < n; i++) {
    while (jc < n + m and c[jc] < a[i]) jc++;
    cnt[jc] = 1;
    jc++;
  }
  vector<pair<int, int>> diff;
  for (int i = 0; i < (int)n + m - 1; i++) {
    if (c[i] == c[i + 1]) join(i, i + 1);
    diff.push_back(make_pair(c[i + 1] - c[i], i));
  }
  sort(diff.begin(), diff.end());
  vector<pair<int, int>> queries;
  for (int i = 0; i < (int)q; i++) {
    int k;
    cin >> k;
    queries.push_back(make_pair(k, i));
  }
  sort(queries.begin(), queries.end());
  for (int i = 0, di = 0; i < q; i++) {
    while (di < ((int)diff.size()) and diff[di].first <= queries[i].first) {
      join(diff[di].second, diff[di].second + 1);
      di++;
    }
    out[queries[i].second] = ans;
  }
  for (int i = 0; i < (int)q; i++) cout << out[i] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  while (T--) fun();
  return 0;
}
