#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd(1231);
const int MAXINT = 1e9 + 12;
const long long int MAXLL = 1e18 + 21;
vector<vector<int>> graph;
vector<int> isPochka;
vector<int> isLeaf;
vector<int> isUsed;
void dfs1(int v, int p = -1) {
  if (graph[v].size() == 1 && p != -1) {
    isLeaf[v] = 1;
    return;
  }
  bool hasLeaf = false;
  for (auto& other : graph[v]) {
    if (other == p) continue;
    dfs1(other, v);
    if (isLeaf[other] || !isPochka[other]) hasLeaf = true;
  }
  if (hasLeaf) {
    isPochka[v] = 1;
    for (auto& other : graph[v]) {
      if (other == p) continue;
      if (!isLeaf[other] && isPochka[other]) continue;
      isUsed[other] = 1;
    }
  }
}
void solve() {
  int n;
  cin >> n;
  graph = vector<vector<int>>(n);
  isPochka = vector<int>(n);
  isLeaf = vector<int>(n);
  isUsed = vector<int>(n);
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int root = 0;
  dfs1(root);
  int cntP = 0;
  for (int i = 0; i < n; i++)
    if (isPochka[i]) cntP++;
  int cntL = 0;
  for (int i = 0; i < n; i++) {
    if (isLeaf[i] || isUsed[i]) cntL++;
  }
  int answ = cntL - cntP + 1;
  cout << answ << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
