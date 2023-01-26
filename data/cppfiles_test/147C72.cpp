#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
void solve() {
  long long i, n, E = 0, N = 0;
  string s;
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == 'N')
      N++;
    else
      E++;
  }
  if (N == 1 && s.size() > 1)
    cout << "NO\n";
  else
    cout << "YES\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
