#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O8")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long int N = 1e5 + 20, mod = 1e9 + 7, inf = 1e18, dlt = 12250,
                    maxm = 2e6;
int poww(long long a, int k) {
  if (!k) return 1;
  if (k == 1) return a;
  long long r = poww(a, k / 2);
  return (((r * r) % mod) * poww(a, k & 1)) % mod;
}
int dp[N][2];
vector<int> ve[27][2];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    string s, t;
    cin >> s >> t;
    n = s.size();
    m = t.size();
    if (n < m) {
      cout << "NO" << '\n';
      continue;
    }
    for (int i = 0; i < 27; i++) {
      ve[i][0].clear();
      ve[i][1].clear();
    }
    for (int i = 0; i < n; i++) ve[s[i] - 'a'][(i & 1)].push_back(i);
    if (ve[t[0] - 'a'][0].empty() && ve[t[0] - 'a'][1].empty()) {
      cout << "NO" << '\n';
      continue;
    }
    for (int i = 0; i < m; i++) {
      dp[i][0] = -1;
      dp[i][1] = -1;
    }
    if (!ve[t[0] - 'a'][0].empty()) dp[0][0] = ve[t[0] - 'a'][0][0];
    if (!ve[t[0] - 'a'][1].empty()) dp[0][1] = ve[t[0] - 'a'][1][0];
    for (int i = 1; i < m; i++) {
      int ch = t[i] - 'a';
      int sz = ve[ch][0].size(), sz1 = ve[ch][1].size();
      if (dp[i - 1][1] != -1 && sz && ve[ch][0][sz - 1] > dp[i - 1][1]) {
        int ind =
            upper_bound(ve[ch][0].begin(), ve[ch][0].end(), dp[i - 1][1]) -
            ve[ch][0].begin();
        dp[i][0] = ve[ch][0][ind];
      }
      if (dp[i - 1][0] != -1 && sz1 && ve[ch][1][sz1 - 1] > dp[i - 1][0]) {
        int ind =
            upper_bound(ve[ch][1].begin(), ve[ch][1].end(), dp[i - 1][0]) -
            ve[ch][1].begin();
        dp[i][1] = ve[ch][1][ind];
      }
    }
    cout << ((dp[m - 1][0] != -1 || dp[m - 1][1] != -1) ? "YES" : "NO") << '\n';
  }
  return 0;
}
