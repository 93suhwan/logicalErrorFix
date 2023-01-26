#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const long long maxx = 1e18;
using namespace std;
const int N = 2e5 + 5;
vector<vector<int>> res(N, vector<int>(20, 0));
void preCompute() {
  for (int i = 0; i < 20; i++) {
    int mask = 1 << i;
    int cnt = 0;
    for (int j = 1; j < N; j++) {
      if ((mask & j))
        res[j][i] = res[j - 1][i] + 1;
      else
        res[j][i] = res[j - 1][i];
    }
  }
}
void solve() {
  int l, r;
  cin >> l >> r;
  int mx = INT_MIN;
  for (int i = 0; i < 20; i++) mx = max(res[r][i] - res[l - 1][i], mx);
  cout << r - l + 1 - mx << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  int t;
  preCompute();
  cin >> t;
  while (t--) solve();
  return 0;
}
