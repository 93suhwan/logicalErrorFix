#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1ll << 21);
long long sum[MAXN], mins[22];
vector<vector<long long>> vm;
long long dp[MAXN];
long long f(long long x) {
  long long &res = dp[x];
  if (res >= 0) return res;
  if (x == (1ll << ((int)vm.size())) - 1) return res = 0;
  res = 0;
  long long s = sum[x];
  for (int i = 0, ggdem = ((int)vm.size()); i < ggdem; ++i) {
    if (!((1ll << i) & x)) {
      long long val = 0;
      if (mins[i] + s <= 0) {
        val += vm[i][s];
      }
      if (mins[i] + s >= 0) {
        val += f(x ^ (1ll << i));
      }
      res = max(res, val);
    }
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0, ggdem = n; i < ggdem; ++i) cin >> s[i];
  vm.resize(n);
  for (int i = 0, ggdem = n; i < ggdem; ++i) {
    long long mini = 0, va = 0;
    vm[i] = {0};
    for (auto j : s[i]) {
      if (j == '(')
        va++;
      else
        va--;
      if (va == mini) vm[i].back()++;
      if (va < mini) vm[i].push_back(1);
      mini = min(mini, va);
    }
    mins[i] = mini;
    sum[(1ll << i)] = va;
  }
  for (int i = 1, ggdem = (1ll << n); i < ggdem; ++i) {
    for (int j = 0, ggdem = n; j < ggdem; ++j) {
      if ((1ll << j) & i) {
        sum[i] = sum[i ^ (1ll << j)] + sum[(1ll << j)];
      }
    }
  }
  memset((dp), (-1), sizeof(dp));
  cout << f(0) << "\n";
  return 0;
}
