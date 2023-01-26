#include <bits/stdc++.h>
using namespace std;
const int maxx = (1 << 13);
int main() {
  ios::sync_with_stdio(false);
  vector<int> ans(maxx, 0);
  vector<vector<int>> g(maxx, vector<int>());
  vector<vector<int>> used(maxx, vector<int>(maxx, 0));
  ans[0] = 1;
  for (int i = 0; i < maxx; i++) {
    used[0][i] = 1;
    g[i].push_back(0);
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int to : g[x]) {
      int val = x ^ to;
      ans[val] = 1;
      for (int j = x + 1; j < maxx && !used[val][j]; j++) {
        used[val][j] = 1;
        g[j].push_back(val);
      }
    }
    g[x].clear();
  }
  cout << accumulate(begin(ans), end(ans), 0) << endl;
  for (int i = 0; i < maxx; i++) {
    if (ans[i]) {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}
