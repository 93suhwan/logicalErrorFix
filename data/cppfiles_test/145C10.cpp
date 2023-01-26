#include <bits/stdc++.h>
using namespace std;
const long long P = 1e9 + 7;
void dfs(int i, vector<vector<int>> &adjList, vector<bool> &seen) {
  seen[i] = true;
  for (int nei : adjList[i]) {
    if (seen[nei]) continue;
    dfs(nei, adjList, seen);
  }
}
void solve() {
  int n;
  long long k;
  cin >> n >> k;
  vector<tuple<long long, long long, long long>> v(n);
  map<int, vector<int>> byx;
  map<int, vector<int>> byy;
  vector<vector<int>> adjList(n);
  for (int i = 0; i < n; i++) {
    long long x, y, t;
    cin >> x >> y >> t;
    v[i] = {x, y, t};
    set<int> neis;
    for (auto j : byx[x]) {
      auto [x2, y2, t2] = v[j];
      if (abs(y2 - y) <= k) {
        neis.insert(j);
      }
    }
    for (auto j : byy[y]) {
      auto [x2, y2, t2] = v[j];
      if (abs(x2 - x) <= k) {
        neis.insert(j);
      }
    }
    for (auto nei : neis) {
      adjList[i].push_back(nei);
      adjList[nei].push_back(i);
    }
    byx[x].push_back(i);
    byy[y].push_back(i);
  }
  long long lo = 0, hi = 1e9 + 10;
  while (lo < hi) {
    long long mid = lo + (hi - lo) / 2;
    vector<bool> seen(n, false);
    for (int i = 0; i < n; i++) {
      auto [x, y, t] = v[i];
      if (seen[i]) continue;
      if (t <= mid) {
        dfs(i, adjList, seen);
      }
    }
    int cc = 0;
    for (int i = 0; i < n; i++) {
      if (!seen[i]) {
        cc++;
        dfs(i, adjList, seen);
      }
    }
    if (cc <= mid + 1) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
