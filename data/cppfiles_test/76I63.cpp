#include <bits/stdc++.h>
using namespace std;
mt19937 gen(time(0));
const int N = 1e6 + 100;
const int M = 18;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
vector<int> g[N], ord;
int u[N];
bool comp(int a, int b) {
  return (int32_t(g[a].size()) < int32_t(g[b].size()));
}
void try_set(int n) {
  for (int i = 0; i < n; i++) u[i] = 0;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int v = ord[i];
    if (u[v]) continue;
    ans.push_back(v);
    u[v] = 1;
    for (auto to : g[v]) u[to] = 1;
  }
  if (int32_t(ans.size()) >= 5) {
    for (int i = 0; i < 5; i++) cout << ans[i] + 1 << " ";
    exit(0);
  }
}
void try_click(int n) {
  for (int i = 0; i < n; i++) u[i] = 0;
  vector<int> ans;
  int kol = 0;
  for (int i = 0; i < n; i++) {
    int v = ord[i];
    if (u[v] != kol) continue;
    ans.push_back(v);
    u[v]++;
    kol++;
    for (auto to : g[v]) u[to]++;
  }
  if (int32_t(ans.size()) >= 5) {
    for (int i = 0; i < 5; i++) cout << ans[i] + 1 << " ";
    exit(0);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < n; i++) ord.push_back(i);
  sort(ord.begin(), ord.end(), comp);
  int T = 100;
  while (T--) {
    try_set(n);
    random_shuffle(ord.begin(), ord.end());
  }
  sort(ord.rbegin(), ord.rend(), comp);
  T = 100;
  while (T--) {
    try_click(n);
    random_shuffle(ord.begin(), ord.end());
  }
  cout << -1;
}
