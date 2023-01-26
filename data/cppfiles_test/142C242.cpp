#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int store[100005];
long long int gift[100005];
int main() {
  cin >> t;
  while (t--) {
    cin >> m >> n;
    vector<vector<long long int>> g(m, vector<long long int>(n, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) cin >> g[i][j];
    multiset<long long int> s;
    for (int i = 0; i < n; i++) gift[i] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[j][i] > gift[i]) {
          gift[i] = g[j][i];
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
            long long int val = g[i][j];
            long long int val2 = g[i][k];
            long long int opval = gift[j], op2val = gift[k];
            s.erase(s.find(opval));
            s.erase(s.find(op2val));
            s.insert(val);
            s.insert(val2);
            ans = max(ans, *s.begin());
            s.erase(s.find(val));
            s.erase(s.find(val2));
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
