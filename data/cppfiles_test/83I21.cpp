#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 42;
vector<int> z_func(string s) {
  int l = 0, r = 0;
  vector<int> z(s.size());
  z[0] = s.size();
  for (int i = 1; i < s.size(); ++i) {
    if (i < r) z[i] = z[i - l];
    while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]]) ++z[i];
    if (i >= r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> z(n, vector<int>(n));
    string s1;
    for (int i = n - 1; i > -1; --i) {
      s1 = s[i] + s1;
      vector<int> zi = z_func(s1);
      for (int j = i; j < n; ++j) z[i][j] = zi[j - i];
    }
    s += 'z' + 1;
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) dp[i] = n - i;
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (s[i + z[j][i]] > s[j + z[j][i]])
          dp[i] = max(dp[i], dp[j] + n - i - z[j][i]);
    cout << *max_element(dp.begin(), dp.end()) << endl;
  }
}
