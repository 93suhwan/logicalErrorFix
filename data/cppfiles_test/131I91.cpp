#include <bits/stdc++.h>
std::mt19937 rng(
    (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
void solve(int ttt) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  map<int, int> indMap;
  for (long long int i = 0; i < n; i++) indMap[a[i]] = i;
  vector<pair<int, int> > edg;
  vector<int> p2;
  for (int i = 0; i < 31; i++) {
    p2.push_back(1 << i);
  }
  map<int, int> toInd;
  int c = 0;
  for (long long int i = 0; i < n; i++) {
    toInd[a[i]] = i;
    c++;
  }
  for (long long int i = 0; i < n; i++) {
    int cur = a[i];
    int prevInd = toInd[a[i]];
    while (1) {
      if (cur == 0) break;
      int t = *lower_bound(p2.begin(), p2.end(), cur);
      int x = t - cur;
      int curInd;
      if (toInd.count(x)) {
        curInd = toInd[x];
      } else {
        toInd[x] = c;
        curInd = c++;
      }
      edg.push_back(make_pair(prevInd, curInd));
      cur = x;
      prevInd = curInd;
    }
  }
  vector<vector<int> > adj(c);
  for (auto e : edg) {
    adj[e.first].push_back(e.second);
    adj[e.second].push_back(e.first);
  }
  int mxD = 0;
  int curI = 0;
  int d = 0;
  vector<bool> vis(c, false);
  function<void(int)> dfs = [&](int x) {
    vis[x] = true;
    if (mxD < d) {
      mxD = d;
      curI = x;
    }
    for (auto &i : adj[x]) {
      if (!vis[i]) {
        d++;
        dfs(i);
        d--;
      }
    }
  };
  dfs(0);
  int curJ = curI;
  mxD = 0;
  d = 0;
  vis.assign(c, false);
  dfs(curI);
  cout << curI + 1 << " " << curJ + 1 << " " << mxD << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ttt;
  ttt = 1;
  for (long long int i = 0; i < ttt; i++) solve(i);
}
