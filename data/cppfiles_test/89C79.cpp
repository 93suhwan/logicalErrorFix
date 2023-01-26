#include <bits/stdc++.h>
using namespace std;
int f(int i, set<int> &s, int &ans, vector<vector<int>> &g) {
  s.insert(i);
  int p = 0;
  for (auto j : g[i]) {
    if (s.find(j) == s.end()) {
      int r = f(j, s, ans, g);
      if (r == 2)
        ans += 2;
      else
        p = 1;
    }
  }
  return 1 + p;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    set<int> s;
    int ans = 0;
    int k = f(0, s, ans, g);
    if (k == 2) ans++;
    cout << n - ans << "\n";
  }
}
