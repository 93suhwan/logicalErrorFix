#include <bits/stdc++.h>
using namespace std;
const int P = 1 << 20;
int dp[P], le[P];
int main() {
  int n;
  cin >> n;
  map<int, int> f[20];
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int sum = 0, mn = 0, cnt = 0;
    for (int j = 0; j < (int)s.size(); ++j) {
      if (s[j] == '(')
        ++sum;
      else
        --sum;
      mn = min(mn, sum);
      if (sum == mn) ++f[i][-sum];
      if (mn == 0 && sum == 0) ++cnt;
    }
    le[1 << i] = sum;
    dp[1 << i] = cnt;
  }
  int p = (1 << n);
  for (int mask = 1; mask < p; ++mask) {
    for (int bit = 0; bit < n; ++bit) {
      if (mask & (1 << bit)) continue;
      dp[mask | (1 << bit)] =
          max(dp[mask | (1 << bit)], dp[mask] + f[bit][le[mask]]);
      le[mask | (1 << bit)] = le[mask] + le[1 << bit];
    }
  }
  printf("%d", dp[p - 1]);
  return 0;
}
