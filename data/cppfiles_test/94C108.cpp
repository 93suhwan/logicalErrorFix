#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n;
  cin >> n;
  int ntemp = n;
  vector<int> need(0);
  while (ntemp > 0) {
    need.push_back(ntemp % 10);
    ntemp /= 10;
  }
  int sz = need.size();
  vector<vector<int>> dp(sz, vector<int>(2, 0));
  int ans = 0;
  for (int ncarry = 0; ncarry < 1 << sz; ncarry += 4) {
    int sum = 1;
    for (int i = 0; i < sz; ++i) {
      int tempncarry = ncarry;
      vector<int> needcarry(sz);
      int pos = 0;
      while (tempncarry > 0) {
        needcarry[pos] = (tempncarry % 2);
        tempncarry /= 2;
        pos++;
      }
      needcarry.push_back(0);
      needcarry.push_back(0);
      needcarry.push_back(0);
      int comb = 0;
      for (int a = 0; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
          if (a + b + needcarry[i] ==
              need[i] + ((needcarry[i + 2] == 1) ? 10 : 0)) {
            comb++;
          }
        }
      }
      sum *= comb;
    }
    ans += sum;
  }
  cout << ans - 2 << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ntest = 1;
  cin >> ntest;
  for (int test = 0; test < ntest; ++test) {
    solve();
  }
  return 0;
}
