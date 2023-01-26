#include <bits/stdc++.h>
using namespace std;
bool checkBit(long long int n, long long int i) { return (n & (1LL << i)); }
long long int setBit(long long int n, long long int i) {
  return (n | (1LL << i));
}
long long int resetBit(long long int n, long long int i) {
  return (n & (~(1LL << i)));
}
const long long int MX = 1e18;
const long long int mod = 1e9 + 7;
int inTime[300003], outTime[300003], up[300003][22], l, timer, par[300003];
vector<int> v[300003];
int cnt[300003];
void DFS(int cur, int p) {
  inTime[cur] = ++timer;
  up[cur][0] = par[cur] = p;
  for (int i = 1; i <= l; i++) up[cur][i] = up[up[cur][i - 1]][i - 1];
  for (int x : v[cur]) {
    if (x ^ p) DFS(x, cur);
  }
  outTime[cur] = ++timer;
}
bool IsAncestor(int x, int y) {
  return inTime[x] <= inTime[y] && outTime[x] >= outTime[y];
}
int LCA(int x, int y) {
  if (IsAncestor(x, y)) return x;
  if (IsAncestor(y, x)) return y;
  for (int i = l; i >= 0; i--) {
    if (!IsAncestor(up[x][i], y)) x = up[x][i];
  }
  return up[x][0];
}
void PreProcess(int numberOfNodes) {
  l = ceil(log2(numberOfNodes));
  DFS(1, 1);
}
int find_set(int a) {
  if (a == par[a]) return a;
  return par[a] = find_set(par[a]);
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) par[i] = i;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    int px = find_set(x);
    int py = find_set(y);
    if (px != py) {
      par[py] = px;
      v[x].push_back(y);
      v[y].push_back(x);
    }
  }
  int q;
  cin >> q;
  vector<pair<int, int> > query;
  while (q--) {
    int x, y;
    cin >> x >> y;
    query.push_back({x, y});
    cnt[x]++, cnt[y]++;
  }
  int odd = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] & 1) odd++;
  }
  if (odd) {
    cout << "No"
         << "\n"
         << odd / 2 << "\n";
    return;
  }
  PreProcess(n);
  cout << "Yes"
       << "\n";
  for (auto [x, y] : query) {
    int lca = LCA(x, y);
    vector<int> v1, v2;
    while (lca != x) v1.push_back(x), x = par[x];
    while (lca != y) v2.push_back(y), y = par[y];
    v1.push_back(lca);
    while (!v2.empty()) {
      v1.push_back(v2.back());
      v2.pop_back();
    }
    cout << v1.size() << "\n";
    for (auto x : v1) {
      cout << x << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
