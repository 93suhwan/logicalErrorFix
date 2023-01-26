#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<string> poss(6, "");
  vector<string> str = {"abc", "acb", "bac", "bca", "cab", "cba"};
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < n; j++) {
      poss[i] += str[i][j % 3];
    }
  }
  int cost[6][n];
  memset(cost, 0, sizeof(cost));
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < n; j++) {
      cost[i][j] = (j > 0 ? cost[i][j - 1] : 0) + (poss[i][j] != s[j]);
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int minCost = (r - l + 1);
    for (int i = 0; i < 6; i++) {
      minCost = min(minCost, cost[i][r] - (l > 0 ? cost[i][l - 1] : 0));
    }
    cout << minCost << "\n";
  }
}
