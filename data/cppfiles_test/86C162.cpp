#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
void solve(int z) {
  long long int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i])
      ans += 2;
    else if (s[i] == '0') {
      if (s[i + 1] == t[i + 1] && s[i + 1] == '1')
        ans += 2, i++;
      else
        ans++;
    } else {
      if (s[i + 1] == t[i + 1] && s[i + 1] == '0') ans += 2, i++;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
