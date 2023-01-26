#include <bits/stdc++.h>
using namespace std;
string red(string s) {
  string ss = "";
  for (long long i = 0; i < s.length(); i++)
    if (s[i] != '*') ss += s[i];
  return ss;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    if (x == 1) {
      cout << red(s) << "\n";
      continue;
    }
    vector<vector<long long> > v;
    for (long long i = n - 1; i >= 0; i--) {
      if (s[i] == 'a') {
        continue;
      }
      long long j = i;
      while (j >= 0 && s[i] == s[j]) j--;
      v.push_back({i, (i - j) * k + 1});
      i = j + 1;
    }
    long long prd = 1;
    long long i;
    reverse(v.begin(), v.end());
    for (i = (long long)v.size() - 1; i >= 0; i--) {
      if (v[i][1] >= ceil((double)x / prd)) break;
      prd = prd * v[i][1];
    }
    i = max(i, (long long)0);
    string ans = s.substr(0, v[i][0]);
    for (long long j = i; j < v.size(); j++) {
      if (j != i) prd /= v[j][1];
      long long cnt = ceil((double)x / prd);
      for (long long k = 1; k < cnt; k++) ans += 'b';
      x -= (cnt - 1) * (prd);
      if (j == (long long)v.size() - 1) {
        for (long long k = v[j][0] + 1; k < n; k++) ans += s[k];
      } else {
        for (long long k = v[j][0] + 1; k < v[j + 1][0]; k++) ans += s[k];
      }
    }
    ans = red(ans);
    cout << ans << "\n";
  }
}
