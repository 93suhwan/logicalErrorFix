#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int store[100005];
long long int gift[100005];
struct Compare {
  bool operator()(const pair<long long int, int> &a,
                  const pair<long long int, int> &b) {
    if (a.first > b.first)
      return 1;
    else if (a.first == b.first) {
      if (gift[a.second] < gift[b.second])
        return 1;
      else
        return 0;
    }
    return 0;
  }
};
int main() {
  cin >> t;
  while (t--) {
    cin >> m >> n;
    vector<vector<pair<long long int, int>>> g(
        m, vector<pair<long long int, int>>(n, {0, 0}));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) cin >> g[i][j].first, g[i][j].second = j;
    set<long long int> s;
    for (int i = 0; i < n; i++) gift[i] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[j][i].first > gift[i]) {
          gift[i] = g[j][i].first;
          store[i] = j;
        }
      }
    }
    set<int> stores;
    for (int i = 0; i < n; i++) stores.insert(store[i]);
    for (int i = 0; i < n; i++) s.insert(gift[i]);
    if (stores.size() <= (n - 1)) {
      cout << *s.begin() << "\n";
    } else {
      long long int ans = 0;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          for (int k = 0; k < n; k++) {
            if (k == j) continue;
            auto [val, p] = g[i][j];
            auto [val2, p2] = g[i][k];
            long long int opval = gift[p], op2val = gift[p2];
            s.erase(opval);
            s.erase(op2val);
            s.insert(val);
            s.insert(val2);
            ans = max(ans, *s.begin());
            s.erase(val);
            s.erase(val2);
            s.insert(opval);
            s.insert(op2val);
          }
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
