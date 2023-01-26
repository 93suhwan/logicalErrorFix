#include <bits/stdc++.h>
using namespace std;
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
int main() {
  file();
  fast();
  int n, m, mod = 998244353;
  cin >> n >> m;
  vector<pair<int, int> > v1(n);
  for (auto& it : v1) cin >> it.first >> it.second;
  auto get_div = [&](pair<int, int> p, int num) {
    return p.second / num - ((p.first - 1) / num);
  };
  auto solve = [&](int g, int sum) -> int {
    vector<pair<int, int> > tmp;
    for (auto& it : v1) {
      if (!get_div(it, g)) return 0;
      pair<int, int> x;
      x.first = (it.first - 1) / g + 1;
      x.second = x.first + get_div(it, g) - 1;
      tmp.push_back(x);
    }
    if (tmp.empty()) return 0;
    vector<int> dp(sum + 1, 1);
    for (auto& it : tmp) {
      vector<int> cur(sum + 1);
      for (int i = 1; i <= sum; i++) {
        int r = max(0, i - it.first);
        int l = max(-1, i - it.second);
        cur[i] = dp[r] - (l <= 0 ? 0 : dp[l - 1]);
        cur[i] = (cur[i] + mod) % mod;
      }
      for (int i = 1; i <= sum; i++) cur[i] = (cur[i] + cur[i - 1]) % mod;
      dp = cur;
    }
    return dp[sum];
  };
  vector<int> arr(m + 1, 1);
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < n; j++) arr[i] = solve(i, m / i);
  for (int i = m; i >= 1; i--)
    for (int j = i + i; j <= m; j += i) arr[i] = (arr[i] - arr[j] + mod) % mod;
  cout << arr[1] << '\n';
  return 0;
}
