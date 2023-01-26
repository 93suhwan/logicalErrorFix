#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 9;
const long long inf = 1e12 + 7;
vector<long long> v, prv[N], c, tmp;
long long T, n, a[N], b[N], m;
long long bit1[N], bit2[N];
void upd(long long bit[], long long p, long long val) {
  for (long long i = p; i < N; i += i & -i) bit[i] += val;
}
void Reset(long long bit[], long long p) {
  for (long long i = p; i < N; i += i & -i) bit[i] = 0;
}
long long Get(long long bit[], long long p) {
  long long res = 0;
  for (long long i = p; i > 0; i -= i & -i) res += bit[i];
  return res;
}
long long Query(long long bit[], long long l, long long r) {
  return Get(bit, r) - Get(bit, l - 1);
}
void Repack() {
  v.clear();
  c.clear();
  tmp.clear();
  for (long long i = 1; i <= n + 1; i++) prv[i].clear();
}
void f(long long l, long long r, long long lf, long long rg) {
  if (l > r) return;
  long long mid = (l + r) / 2;
  for (long long i = lf; i <= rg; i++) {
    if (a[i] < b[mid]) upd(bit1, i, 1);
    if (a[i] > b[mid]) upd(bit2, i, 1);
  }
  long long best = 0, mn = inf;
  for (long long i = lf; i <= rg; i++) {
    long long now = Query(bit2, 1, i - 1) + Query(bit1, i, N - 1);
    if (now < mn) mn = now, best = i;
  }
  for (long long i = lf; i <= rg; i++) Reset(bit1, i), Reset(bit2, i);
  prv[best].push_back(mid);
  f(l, mid - 1, lf, best);
  f(mid + 1, r, best, rg);
}
long long cal() {
  tmp = c;
  sort(tmp.begin(), tmp.end());
  tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
  for (long long i = 0; i < c.size(); i++) {
    c[i] = lower_bound(tmp.begin(), tmp.end(), c[i]) - tmp.begin() + 1;
  }
  long long ans = 0;
  for (long long i = 0; i < c.size(); i++) {
    ans += Query(bit1, c[i] + 1, N - 1);
    upd(bit1, c[i], 1);
  }
  for (long long i = 0; i < c.size(); i++) Reset(bit1, c[i]);
  return ans;
}
bool lf(long long x, long long y) { return b[x] < b[y]; }
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  if (fopen("tst"
            ".INP",
            "r")) {
    freopen(
        "tst"
        ".INP",
        "r", stdin);
  }
  cin >> T;
  while (T--) {
    cin >> n >> m;
    Repack();
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= m; i++) cin >> b[i];
    sort(b + 1, b + m + 1);
    f(1, m, 1, n + 1);
    for (long long i = 1; i <= n + 1; i++) {
      sort(prv[i].begin(), prv[i].end(), lf);
      for (auto j : prv[i]) c.push_back(b[j]);
      if (i != n + 1) c.push_back(a[i]);
    }
    cout << cal() << "\n";
  }
}
