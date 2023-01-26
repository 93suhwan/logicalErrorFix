#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2, mod = 1e9 + 7;
int n, m;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool vis2[N];
void doWork() {
  map<pair<int, int>, bool> vis;
  cin >> n >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    vis[{x, y}] = vis[{y, x}] = true;
  }
  int T = 1e6;
  while (T--) {
    vector<int> v;
    while (v.size() < 5) {
      int x = rng() % n + 1;
      if (vis2[x]) continue;
      int cnt = 0;
      for (auto j : v) cnt += vis[{j, x}];
      if (cnt && cnt != v.size()) break;
      v.push_back(x);
      vis2[x] = true;
    }
    for (auto i : v) vis2[i] = false;
    if (v.size() == 5) {
      for (auto i : v) cout << i << " ";
      return;
    }
  }
  cout << "-1\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    doWork();
  }
}
