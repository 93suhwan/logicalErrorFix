#include <bits/stdc++.h>
#pragma gcc optimize(2)
using namespace std;
const int maxn = 1e5 + 10;
vector<int> g[maxn];
pair<int, int> pt[maxn];
int ans;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    ans = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) {
      int k;
      cin >> k;
      for (int j = 1; j <= k; j++) {
        int a;
        cin >> a;
        g[i].push_back(a);
      }
      pt[i].first = g[i].back() + 1;
      for (int j = g[i].size() - 2; j >= 0; j--) {
        pt[i].first = max(pt[i].first - 1, g[i][j] + 1);
      }
      pt[i].second = g[i].size();
    }
    sort(pt + 1, pt + 1 + n);
    int deta = 0;
    int nw = pt[1].first + pt[1].second;
    for (int i = 2; i <= n; i++) {
      if (nw < pt[i].first) {
        deta += pt[i].first - nw;
        nw = pt[i].first;
      }
      nw += pt[i].second;
    }
    cout << pt[1].first + deta << '\n';
  }
  return 0;
}
