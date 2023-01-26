#include <bits/stdc++.h>
using namespace std;
const long long maxn = 4e5 + 1;
struct dak {
  long long val, pos;
};
long long l[maxn], r[maxn];
long long pre[maxn], pre2[maxn];
vector<dak> p;
vector<pair<long long, long long> > v;
vector<pair<long long, long long> > qr;
long long n, m, q;
long long cur = 0;
long long res[maxn];
inline long long get(long long r, long long x) { return pre[r] - pre[r - x]; }
inline long long cnt(long long x) { return pre2[x] - pre2[l[x] - 1]; }
void join(long long pos) {
  cur -= get(pos - 1, cnt(pos - 1)) + get(r[pos], cnt(r[pos])) -
         get(r[pos], cnt(r[pos]) + cnt(pos - 1));
  r[l[pos - 1]] = r[pos];
  l[r[pos]] = l[pos - 1];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    v.push_back({x, 1});
    cur += x;
  }
  for (long long i = 1; i <= m; i++) {
    long long x;
    cin >> x;
    v.push_back({x, 0});
  }
  sort(v.begin(), v.end());
  for (long long i = 1; i <= n + m; i++) {
    l[i] = r[i] = i;
    pre[i] = pre[i - 1] + v[i - 1].first;
    pre2[i] = pre2[i - 1] + v[i - 1].second;
  }
  for (long long i = 1; i < n + m; i++) {
    p.push_back({v[i].first - v[i - 1].first, i + 1});
  }
  sort(p.begin(), p.end(),
       [](const dak &a, const dak &b) { return a.val < b.val; });
  for (long long i = 1, x; i <= q; i++) {
    cin >> x;
    qr.push_back({x, i});
  }
  sort(qr.begin(), qr.end());
  long long pos = 0;
  for (pair<long long, long long> &query : qr) {
    while (pos < p.size() && p[pos].val <= query.first) {
      join(p[pos].pos);
      pos++;
    }
    res[query.second] = cur;
  }
  for (long long i = 1; i <= q; i++) cout << res[i] << '\n';
}
