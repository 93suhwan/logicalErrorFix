#include <bits/stdc++.h>
using namespace std;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
template <typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
  out << "{" << p.first << "," << p.second << "}";
  return out;
}
int n, k;
vector<int> leaf;
int dep[(200004)], val[(200004)];
vector<int> edge[(200004)];
int dfs1(int x, int f) {
  dep[x] = 0;
  bool isleaf = 1;
  for (auto i : edge[x]) {
    if (i == f) continue;
    isleaf = 0;
    dep[x] = max(dep[x], dfs1(i, x) + 1);
  }
  if (isleaf) leaf.push_back(x);
  return dep[x];
}
void dfs2(int x, int f, int d) {
  val[x] = d;
  sort(edge[x].begin(), edge[x].end(),
       [](int lhs, int rhs) { return dep[lhs] > dep[rhs]; });
  if (edge[x].front() == f && edge[x].size() > 1) swap(edge[x][0], edge[x][1]);
  for (auto i : edge[x]) {
    if (i == f) continue;
    if (i == edge[x].front()) {
      dfs2(i, x, d + 1);
    } else
      dfs2(i, x, 1);
  }
}
void solve() {
  cin >> n >> k;
  for (int i = 1, a, b; i < n; i++) {
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  dfs1(1, 1);
  dfs2(1, 1, 1);
  sort(leaf.begin(), leaf.end(),
       [](int lhs, int rhs) { return val[lhs] > val[rhs]; });
  long long ans = 0, sum = 0;
  long long b, w, r;
  for (int i = 0; i < min(k, (int)leaf.size()); i++) {
    sum += val[leaf[i]];
  }
  r = min(k, (int)leaf.size());
  b = n - sum;
  if (b > r) {
    long long v = b - r + n - (r + b);
    ans = min(ans, -(v / 2) * (v - v / 2));
  }
  sum = 0;
  for (int i = 0; i < min(k, (int)leaf.size()); i++) {
    sum += val[leaf[i]];
    r = i + 1;
    b = n - sum;
    if (b > r) {
      long long v = b - r + n - (r + b);
      ans = max(ans, -(v / 2) * (v - v / 2));
    } else {
      w = n - (r + b);
      ans = max(ans, w * (r - b));
    }
  }
  for (int i = leaf.size(); i < k; i++) {
    r = i + 1;
    b = n - sum;
    if (b > r) {
      long long v = b - r + n - (r + b);
      ans = max(ans, -(v / 2) * (v - v / 2));
    } else {
      w = n - (r + b);
      ans = max(ans, w * (r - b));
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int cas = 1; cas <= t; cas++) {
    solve();
  }
  return 0;
}
