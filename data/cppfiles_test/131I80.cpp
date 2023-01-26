#include <bits/stdc++.h>
std::mt19937 rng(
    (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
void solve(int ttt) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  map<int, vector<int> > adj;
  vector<int> p2;
  for (int i = 0; i < 31; i++) {
    p2.push_back(1 << i);
  }
  for (long long int i = 0; i < n; i++) {
    int cur = a[i];
    while (1) {
      int t = *lower_bound(p2.begin(), p2.end(), cur);
      int x = t - cur;
      if (cur == 0) break;
      adj[x].push_back(cur);
      adj[cur].push_back(x);
      cur = x;
    }
  }
  int mxD = 0;
  int curI = 0;
  int d = 0;
  function<void(int, int)> dfs = [&](int x, int p) {
    if (mxD < d) {
      mxD = d;
      curI = x;
    }
    for (auto &i : adj[x]) {
      if (i != p) {
        d++;
        dfs(i, x);
        d--;
      }
    }
  };
  dfs(0, -1);
  int curJ = curI;
  mxD = 0;
  d = 0;
  dfs(curI, -1);
  cout << curI + 1 << " " << curJ + 1 << " " << mxD << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ttt;
  ttt = 1;
  for (long long int i = 0; i < ttt; i++) solve(i);
}
