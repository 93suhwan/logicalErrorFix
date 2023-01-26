#include <bits/stdc++.h>
#pragma GCC optimize("O1")
using namespace std;
void solve() {
  long long int n, k, x;
  cin >> n >> k >> x;
  string s;
  cin >> s;
  vector<long long int> v;
  long long int c = 0;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == '*')
      c++;
    else {
      if (c) v.push_back(c * (k) + 1);
      c = 0;
    }
  }
  if (c) v.push_back(c * (k) + 1);
  long long int p = 1;
  long long int t = v.size(), pos = -1;
  x--;
  for (long long int i = t - 1; i >= 0; i--) {
    p *= v[i];
    if (p >= x) {
      p /= v[i];
      long long int a = x / p, b = x % p;
      string ans = "";
      long long int j = 0;
      while (j < n && s[j] == 'a') ans.push_back('a'), j++;
      for (long long int i = 0; i < a; i++) ans.push_back('b');
      for (long long int p = i + 1; p < t - 1; p++) {
        ans.push_back('a');
        for (long long int o = 0; o < (v[p] - 1); o++) ans.push_back('b');
      }
      if (t > i + 1) {
        ans.push_back('a');
        for (long long int o = 0; o < b; o++) ans.push_back('b');
      }
      j = n - 1;
      while (j >= 0 && s[j] == 'a') {
        j--;
        ans.push_back('a');
      }
      cout << ans;
      cout << "\n";
      return;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
