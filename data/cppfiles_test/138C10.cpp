#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long mod = 1e9 + 7;
const long long INF = (1 << 30) - 1;
const long long N = 4e5 + 10, M = 100;
pair<long long, long long> a[N], q[N], cha[N];
long long n, m;
long long res[N];
long long p[N];
long long cnt[N];
long long pre[N];
long long find(long long first) {
  if (p[first] != first) p[first] = find(p[first]);
  return p[first];
}
signed main() {
  long long qn;
  cin >> n >> m >> qn;
  long long sum = 0;
  for (long long i = 1; i <= n + m; i++) p[i] = i;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = 0;
    sum += a[i].first;
  }
  for (long long i = n + 1; i <= n + m; i++) {
    cin >> a[i].first;
    a[i].second = 1;
  }
  sort(a + 1, a + n + m + 1);
  for (long long i = 1; i <= n + m; i++) {
    if (!a[i].second) cnt[i] = 1;
    cha[i] = {a[i].first - a[i - 1].first, i};
  }
  sort(cha + 2, cha + n + m + 1);
  for (long long i = 1; i <= n + m; i++) {
    pre[i] = pre[i - 1] + a[i].first;
  }
  for (long long i = 1; i <= qn; i++) {
    cin >> q[i].first;
    q[i].second = i;
  }
  sort(q + 1, q + qn + 1);
  long long j = 2;
  for (long long i = 1; i <= qn; i++) {
    long long d = q[i].first;
    while (j <= n + m && cha[j].first <= d) {
      long long u = cha[j].second - 1, v = cha[j].second;
      u = find(u);
      v = find(v);
      sum -= pre[v] - pre[v - cnt[v]];
      sum -= pre[u] - pre[u - cnt[u]];
      cnt[v] += cnt[u];
      sum += pre[v] - pre[v - cnt[v]];
      p[u] = v;
      j++;
    }
    res[q[i].second] = sum;
  }
  for (long long i = 1; i <= qn; i++) {
    cout << res[i] << '\n';
  }
  cout << '\n';
  return 0;
}
