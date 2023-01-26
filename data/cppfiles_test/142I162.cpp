#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, siz = 1e6 + 5;
vector<int> inp[siz];
int t, n, m, k, a[siz], person[siz], suf[siz];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> m >> n;
    for (int i = 1; i <= max(n, m); i++) {
      inp[i].clear();
    }
    for (int i = 1; i <= m; i++) {
      inp[i].push_back(0);
      for (int j = 1; j <= n; j++) {
        int x;
        cin >> x;
        inp[i].push_back(x);
      }
    }
    int ans = 1e9;
    set<int> s;
    for (int i = 1; i <= n; i++) {
      int id = 1;
      for (int j = 1; j <= m; j++)
        if (inp[j][i] >= inp[id][i]) id = j;
      s.insert(id);
      ans = min(ans, inp[id][i]);
      person[i] = inp[id][i];
    }
    if (s.size() < n) {
      cout << ans << endl;
      continue;
    }
    ans = 0;
    for (int i = 1; i <= m; i++) {
      int id1 = 0, id2 = 0;
      for (int j = 1; j <= n; j++) {
        if (inp[i][j] > inp[i][id1]) {
          swap(id1, id2);
          id1 = j;
        } else if (inp[i][j] > inp[i][id2])
          id2 = j;
      }
      int cur = inp[i][id2];
      for (int j = 1; j <= n; j++) {
        if (j != id1 and j != id2) cur = min(cur, person[i]);
      }
      ans = max(ans, cur);
    }
    cout << ans << endl;
  }
}
