#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 7, M = N * 2;
const long long p = 998244353;
long long num, x, n, ans;
long long in[N];
long long h[N], e[N], ne[N], idx;
void add(long long a, long long b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
bool topo() {
  priority_queue<pair<long long, long long>,
                 vector<pair<long long, long long> >,
                 greater<pair<long long, long long> > >
      q;
  long long cnt = 0;
  for (long long i = 1; i <= n; ++i) {
    if (in[i] == 0) {
      cnt++;
      q.push({1, i});
    }
  }
  while (!q.empty()) {
    ans = q.top().first;
    long long pos = q.top().second;
    q.pop();
    for (long long i = h[pos]; i != -1; i = ne[i]) {
      long long j = e[i];
      --in[j];
      if (in[j] == 0) {
        cnt++;
        if (j > pos)
          q.push({ans, j});
        else
          q.push({ans + 1, j});
      }
    }
  }
  return cnt == n;
}
void solve() {
  ans = -1;
  idx = 0;
  scanf("%lld", &n);
  for (long long i = 1; i <= n; ++i) h[i] = -1;
  for (long long i = 1; i <= n; ++i) {
    scanf("%lld%", &num);
    in[i] = num;
    while (num--) {
      scanf("%lld", &x);
      add(x, i);
    }
  }
  if (topo())
    printf("%lld\n", ans);
  else
    printf("-1\n");
}
signed main() {
  long long t = 1;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
  return 0;
}
