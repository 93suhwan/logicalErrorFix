#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Print(T v) {
  for (auto i : v) cout << i << (" ");
  cout << '\n';
}
int INF = 1000000007;
long long LINF = 1000000000000000000;
long long mod1 = 998244353;
int dp[2][100001];
int ceil(int a, int b) {
  int res = a / b;
  if (a % b) res++;
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  long long res = 0;
  dp[1][vec[n - 1]] = 1;
  vector<vector<int>> iter(2);
  iter[1].push_back(vec[n - 1]);
  for (int i = n - 2; i >= 0; i--) {
    iter[0].push_back(vec[i]);
    dp[0][vec[i]] = 1;
    while (not iter[1].empty()) {
      int pod = ceil(vec[i], iter[1].back());
      if (dp[0][vec[i] / pod] == 0) iter[0].push_back(vec[i] / pod);
      dp[0][vec[i] / pod] += dp[1][iter[1].back()];
      res += (i + 1) * dp[1][iter[1].back()] * (pod - 1);
      res %= mod1;
      dp[1][iter[1].back()] = 0;
      iter[1].pop_back();
    }
    for (auto j : iter[0]) swap(dp[1][j], dp[0][j]);
    swap(iter[0], iter[1]);
  }
  while (not iter[1].empty()) {
    dp[1][iter[1].back()] = 0;
    iter[1].pop_back();
  }
  cout << (res) << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
