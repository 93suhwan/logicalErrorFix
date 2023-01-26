#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, q;
int a[N * 2], f[N * 2];
long long sum[N * 2];
pair<int, int> u[N];
long long total, ans[N];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    pq;
int getf(int x) { return f[x] <= 0 ? x : f[x] = getf(f[x]); }
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) cin >> a[i], a[i] = -a[i];
  for (int i = n + 1; i <= n + m; i++) cin >> a[i];
  sort(a + 1, a + 1 + n + m, [](int u, int v) { return abs(u) < abs(v); });
  for (int i = 1; i <= n + m; i++) {
    if (a[i] < 0)
      f[i] = -1, a[i] = -a[i], total += a[i];
    else
      f[i] = 0;
    sum[i] = sum[i - 1] + a[i];
    if (i != 1) pq.push({a[i] - a[i - 1], i});
  }
  for (int i = 1; i <= q; i++) cin >> u[i].first, u[i].second = i;
  sort(u + 1, u + 1 + q);
  for (int i = 1; i <= q; i++) {
    int val = u[i].first, id = u[i].second;
    while (!pq.empty() && pq.top().first <= val) {
      pair<int, int> x = pq.top();
      pq.pop();
      int r1 = x.second - 1, r2 = getf(x.second);
      total -= sum[r1] - sum[r1 + f[r1]];
      total -= sum[r2] - sum[r2 + f[r2]];
      f[r2] += f[r1], f[r1] = r2;
      total += sum[r2] - sum[r2 + f[r2]];
    }
    ans[id] = total;
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
  return 0;
}
