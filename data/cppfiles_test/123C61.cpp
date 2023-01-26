#include <bits/stdc++.h>
using namespace std;
int n, k, d[200100], l, pb, mc[200100];
vector<int> e[200100], c[200100];
priority_queue<pair<int, int>> pq;
void dfs(int i = 0, int p = -1) {
  d[i] = 1;
  for (int j : e[i])
    if (j != p) {
      dfs(j, i);
      d[i] = max(d[i], d[j] + 1);
      c[i].push_back(j);
    }
  sort(c[i].begin(), c[i].end(), [&](int j, int k) { return d[j] < d[k]; });
  if (d[i] == 1)
    l++;
  else
    mc[i] = c[i].back(), c[i].pop_back();
}
void add(int i) {
  pb--;
  if (d[i] > 1) {
    for (int j : c[i]) pq.emplace(d[j], j);
    add(mc[i]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cin >> n >> k;
  pb = n;
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b, a--, b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  dfs();
  if (l <= k) {
    int r = max(l, min(k, n / 2));
    cout << (long long)(n - r) * r << "\n";
    return 0;
  }
  pq.emplace(d[0], 0);
  for (int i = 0; i < k; i++) {
    auto [od, j] = pq.top();
    pq.pop();
    add(j);
  }
  int r = k;
  int rb = min(pb, max(r, r + (n - 2 * r) / 2));
  cout << (long long)(n - r - rb) * (r - rb) << "\n";
}
