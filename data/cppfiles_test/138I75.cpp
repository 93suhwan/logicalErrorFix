#include <bits/stdc++.h>
using namespace std;
long long n, m, q;
pair<long long, long long> a[400100];
long long dsu[200100];
pair<long long, long long> query[200100];
long long ans[200100];
long long last[200100];
long long prsum[200100];
long long f(long long x) {
  if (dsu[x] < 0) return x;
  long long r = f(dsu[x]);
  dsu[x] = r;
  return r;
}
void join(long long x, long long y) {
  long long r1 = f(x);
  long long r2 = f(y);
  if (r1 != r2) {
    if (dsu[r1] > dsu[r2]) swap(r1, r2);
    last[r1] = max(last[r1], last[r2]);
    dsu[r1] += dsu[r2];
    dsu[r2] = r1;
  }
}
priority_queue<pair<long long, pair<long long, long long>>,
               vector<pair<long long, pair<long long, long long>>>,
               greater<pair<long long, pair<long long, long long>>>>
    pq;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long sum = 0;
  cin >> n >> m >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i].first;
    sum += a[i].first;
    a[i].second = 1;
  }
  for (long long i = 1; i <= m; i++) {
    cin >> a[i + n].first;
    a[i + n].second = 0;
  }
  sort(a + 1, a + 1 + n + m);
  for (long long i = 0; i <= n + 10; i++) {
    dsu[i] = -1;
  }
  long long cur = 1;
  for (long long i = 1; i < n + m; i++) {
    if (a[i].second == 1) {
      pq.push({a[i + 1].first - a[i].first, {i, cur}});
      last[cur] = i;
      cur++;
    }
  }
  for (long long i = 0; i < q; i++) {
    cin >> query[i].first;
    query[i].second = i;
  }
  sort(query, query + q);
  for (int i = 1; i <= n + m; i++) {
    prsum[i] = prsum[i - 1] + a[i].first;
  }
  for (long long i = 0; i < q; i++) {
    long long v = query[i].first;
    while (!pq.empty() && v >= pq.top().first) {
      pair<long long, long long> tmp = pq.top().second;
      pq.pop();
      if (a[tmp.first + 1].second == 1) {
        long long r1 = f(tmp.second);
        long long r2 = f(tmp.second + 1);
        sum += prsum[last[r2] + dsu[r2]] - prsum[last[r2] + dsu[r2] + dsu[r1]];
        sum -= prsum[last[r1]] - prsum[last[r1] + dsu[r1]];
        join(tmp.second, tmp.second + 1);
      } else if (tmp.first + 1 == n + m) {
        sum += a[tmp.first + 1].first -
               a[tmp.first + dsu[f(tmp.second)] + 1].first;
        last[f(tmp.second)]++;
      } else {
        pq.push({a[tmp.first + 2].first - a[tmp.first + 1].first,
                 {tmp.first + 1, tmp.second}});
        sum += a[tmp.first + 1].first -
               a[tmp.first + dsu[f(tmp.second)] + 1].first;
        last[f(tmp.second)]++;
      }
    }
    ans[query[i].second] = sum;
  }
  for (long long i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
