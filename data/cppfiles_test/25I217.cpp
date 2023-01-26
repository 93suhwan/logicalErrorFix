#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
void solve() {
  string s, t;
  cin >> s >> t;
  long long index;
  if ((index = s.find(t, 0)) != string::npos) {
    cout << "YES\n";
    return;
  }
  reverse(t.begin(), t.end());
  if ((index = s.find(t, 0)) != string::npos) {
    cout << "YES\n";
    return;
  }
  long long i, j;
  for (j = 0; j < t.length(); j++) {
    for (i = j; i < t.length() - 1; i++) {
      if (t[i - 1] == t[i + 1]) {
        break;
      }
    }
    string s1 = t.substr(0, i + 1);
    string s2 = t.substr(i + 1);
    reverse(s2.begin(), s2.end());
    if ((index = s.find(s1, 0)) != string::npos and
        (index = s.find(s2, 0)) != string::npos) {
      cout << "YES\n";
      return;
    }
    j = i + 1;
  }
  cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
