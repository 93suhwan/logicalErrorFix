#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 6;
int tim[N], k, n, par[N], mn[N], sz[N];
void init() {
  for (int i = 1; i <= n; i++) sz[i] = 1, par[i] = i, mn[i] = 1e9;
}
int findp(int u) { return (par[u] == u ? u : findp(par[u])); }
void con(int u, int v) {
  u = findp(u);
  v = findp(v);
  if (u == v) return;
  if (sz[u] < sz[v]) swap(u, v);
  sz[u] += sz[v];
  par[v] = u;
  mn[u] = min(mn[v], mn[u]);
}
set<int> st;
vector<int> vec;
bool check(int num) {
  int ans = 0;
  for (int i = 0; i < vec.size(); i++) ans += vec[i] > num;
  return ans <= num;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    st.clear();
    cin >> n >> k;
    init();
    vector<pair<pair<int, int>, int> > vx, vy;
    for (int i = 1; i <= n; i++) {
      int x, y;
      cin >> x >> y >> tim[i];
      vx.push_back({{x, y}, i});
      vy.push_back({{y, x}, i});
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    for (int i = 1; i < n; i++) {
      if (vx[i - 1].first.first == vx[i].first.first) {
        if (abs(vx[i - 1].first.second - vx[i].first.second) <= k)
          con(vx[i].second, vx[i - 1].second);
      }
      if (vy[i - 1].first.first == vy[i].first.first) {
        if (abs(vy[i - 1].first.second - vy[i].first.second) <= k)
          con(vy[i].second, vy[i - 1].second);
      }
    }
    for (int i = 1; i <= n; i++) st.insert(findp(i));
    vec.clear();
    for (auto i : st) vec.push_back(tim[i]);
    int start = 0, end = 3e5;
    while (start <= end) {
      int mid = start + end >> 1;
      if (check(mid))
        end = mid - 1;
      else
        start = mid + 1;
    }
    cout << end << '\n';
  }
}
