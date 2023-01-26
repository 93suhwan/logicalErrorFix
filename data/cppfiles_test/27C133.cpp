#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse2")
const long long Alpha = 30;
long long Q, id[Alpha];
string s, t, ANS;
vector<long long> vec[Alpha];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> Q;
  while (Q--) {
    ANS = "YES\n";
    cin >> s >> t;
    long long n = s.size() - 1, m = t.size() - 1;
    while (n >= 0 && m >= 0) {
      while (n >= 0 && s[n] != t[m]) {
        n -= 2;
      }
      if (n >= 0) {
        n--;
      } else
        ANS = "NO\n";
      m--;
    }
    if (m >= 0) ANS = "NO\n";
    cout << ANS;
  }
  return 0;
}
