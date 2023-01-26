#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, inf = 2e9 + 1488;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long mn = inf;
  for (char c = 'a'; c <= 'z'; ++c) {
    long long i = 0, j = n - 1, ok = 1, k = 0;
    while (i < j) {
      if (s[i] == s[j])
        i++, j--;
      else {
        if (s[i] == c)
          i++, k++;
        else if (s[j] == c)
          j--, k++;
        else {
          ok = 0;
          break;
        }
      }
    }
    if (ok) mn = min(mn, k);
  }
  cout << (mn == inf ? -1 : mn) << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long q;
  cin >> q;
  while (q--) solve();
  return 0;
}
