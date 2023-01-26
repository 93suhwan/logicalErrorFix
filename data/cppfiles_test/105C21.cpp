#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 200001;
int t, n;
int a[N], b[N];
int m[N];
int mn[N], mx[N];
int ans[N];
vector<int> vec[2000001];
int par[N];
int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
void join(int x, int y) { par[find(x)] = find(y); }
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) par[i] = i;
  set<int> second;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> m[i];
    mn[i] = max(0, a[i] - m[i]);
    int use = min(m[i], b[i]);
    mx[i] = a[i] - (m[i] - use);
    vec[a[i] + b[i] - m[i]].push_back(i);
    second.insert(a[i] + b[i] - m[i]);
  }
  auto cmp = [&](int i, int j) {
    if (mn[i] != mn[j]) return mn[i] < mn[j];
    return mx[i] > mx[j];
  };
  int cnt = 0;
  for (auto it = second.begin(); it != second.end(); it++) {
    int sum = *it;
    sort(begin(vec[sum]), end(vec[sum]), cmp);
    priority_queue<pair<int, int> > pq;
    for (int i : vec[sum]) {
      while (!pq.empty() && pq.top().first >= mx[i]) {
        join(pq.top().second, i);
        pq.pop();
      }
      pq.push({mx[i], i});
    }
    vector<int> vec2;
    for (int i : vec[sum]) {
      if (find(i) == i) {
        vec2.push_back(i);
      }
    }
    int i = 0;
    while (i < (int)vec2.size()) {
      cnt++;
      int use = mx[vec2[i]];
      ans[vec2[i]] = use;
      while (i + 1 < (int)vec2.size() && mn[vec2[i + 1]] <= use) {
        ans[vec2[++i]] = use;
      }
      i++;
    }
    vec[sum].clear();
  }
  cout << cnt << "\n";
  for (int i = 1; i <= n; i++) {
    ans[i] = ans[find(i)];
    cout << a[i] - ans[i] << " " << b[i] - (a[i] + b[i] - m[i] - ans[i])
         << "\n";
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> t;
  while (t--) {
    solve();
  }
}
