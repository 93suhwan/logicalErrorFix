#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> g[maxn];
int d[maxn], in[maxn];
queue<int> q;
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    while (!q.empty()) q.pop();
    int n;
    cin >> n;
    int sum = n;
    for (int i = 1; i <= n; i++) g[i].clear();
    memset(d, 0, sizeof(int) * (n + 10));
    memset(in, 0, sizeof(int) * (n + 10));
    for (int i = 1; i <= n; i++) {
      int k;
      cin >> k;
      if (k == 0) {
        d[i] = 1;
        q.push(i);
        sum--;
      }
      for (int j = 1; j <= k; j++) {
        int x;
        cin >> x;
        g[x].push_back(i);
        in[i]++;
      }
    }
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (auto it : g[x]) {
        in[it]--;
        if (in[it] == 0) {
          q.push(it);
          sum--;
        }
        if (it > x)
          d[it] = max(d[it], d[x]);
        else
          d[it] = max(d[it], d[x] + 1);
      }
    }
    if (sum != 0)
      cout << "-1" << endl;
    else {
      int ans = 0;
      for (int i = 1; i <= n; i++) ans = max(ans, d[i]);
      cout << ans << endl;
    }
  }
}
