#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9 + 9;
const long double eps = 1e-7;
long long pa[maxn], cost[maxn], cnt[maxn], pre[maxn], sum;
long long findset(long long x) {
  return x == pa[x] ? x : pa[x] = findset(pa[x]);
}
void uni(long long a, long long b) {
  a = findset(a), b = findset(b);
  pa[a] = b;
  cnt[b] += cnt[a];
  sum -= cost[a] + cost[b];
  cost[b] = pre[b] - pre[b - cnt[b]];
  sum += cost[b];
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, q;
  cin >> n >> m >> q;
  for (long long i = 1; i <= n + m; i++) {
    pa[i] = i;
  }
  vector<pair<long long, long long> > arr;
  vector<long long> a(n + 5), b(m + 5);
  for (long long i = 1; i <= n; i++) cin >> a[i], arr.push_back({a[i], 1});
  for (long long i = 1; i <= m; i++) cin >> b[i], arr.push_back({b[i], 0});
  sort(arr.begin(), arr.end());
  vector<tuple<long long, long long, long long> > edge;
  for (long long i = 0; i < arr.size(); i++) {
    if (arr[i].second == 1)
      cnt[i + 1]++, cost[i + 1] += arr[i].first, sum += arr[i].first;
    if (i != 0) {
      edge.push_back({arr[i].first - arr[i - 1].first, i, i + 1});
    }
    pre[i + 1] = pre[i] + arr[i].first;
  }
  sort(edge.begin(), edge.end());
  vector<pair<long long, long long> > query;
  vector<pair<long long, long long> > ans;
  for (long long i = 1; i <= q; i++) {
    long long x;
    cin >> x;
    query.push_back({x, i});
  }
  sort(query.begin(), query.end());
  long long pos = 0;
  for (auto [c, a, b] : edge) {
    while (pos < q and query[pos].first < c) {
      ans.push_back({query[pos].second, sum});
      pos++;
    }
    uni(a, b);
  }
  sort(ans.begin(), ans.end());
  for (auto i : ans) cout << i.second << '\n';
}
