#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
vector<pair<int, int>> arr, dist, qu;
int fa[2 * N + 1], cnt[2 * N + 1];
int fi(int x) { return fa[x] == x ? x : fa[x] = fi(fa[x]); }
long long prf[2 * N + 1], ans[2 * N + 1], sum;
long long calc(int x) { return prf[x] - prf[x - cnt[x]]; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  arr.emplace_back(0, 0);
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    sum += a;
    arr.emplace_back(a, 1);
  }
  for (int i = 1; i <= m; i++) {
    int b;
    cin >> b;
    arr.emplace_back(b, 0);
  }
  for (int i = 1; i <= q; i++) {
    int k;
    cin >> k;
    qu.emplace_back(k, i);
  }
  iota(fa + 1, fa + n + m + 1, 1);
  sort(arr.begin(), arr.end());
  for (int i = 1; i <= n + m; i++) {
    cnt[i] = arr[i].second;
    prf[i] = prf[i - 1] + arr[i].first;
    dist.emplace_back(arr[i].first - arr[i - 1].first, i);
  }
  sort(dist.begin(), dist.end());
  sort(qu.begin(), qu.end());
  int id = 0;
  for (auto x : qu) {
    while (id < n + m && x.first >= dist[id].first) {
      int b = dist[id].second, a = b - 1;
      b = fi(b);
      sum -= calc(a), sum -= calc(b);
      cnt[b] += cnt[a];
      sum += calc(b);
      fa[a] = b;
      ++id;
    }
    ans[x.second] = sum;
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
