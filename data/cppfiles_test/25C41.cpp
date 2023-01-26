#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  long long cnt = 0;
  long long j = cnt;
  for (long long i = 0; i < s1.length(); i++) {
    for (j = i; j < s1.length(); j++) {
      long long val1 = (j - i + 1);
      long long val2 = (s2.length() - val1);
      if (j < val2 or val2 < 0) {
        continue;
      }
      string tmp = "";
      for (long long k = i; k < j + 1; k++) {
        tmp += s1[k];
      }
      long long k = j - 1;
      while (val2--) {
        tmp += s1[k];
        k--;
      }
      if (tmp == s2) {
        cout << "YES\n";
        return;
      }
    }
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
