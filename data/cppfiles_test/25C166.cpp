#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
const long long md = 1e9 + 7;
void _solve() {
  string s, t;
  cin >> s >> t;
  string sr = s;
  long long n = s.length();
  reverse(sr.begin(), sr.end());
  long long ok = 0;
  for (long long i = n - 1, j = 0; j < n; i--, j++) {
    for (long long k = 0; k < t.length(); k++) {
      if (t[k] == s[i]) {
        long long l, r, lok = 0, rok = 0;
        for (l = i - 1, r = k - 1; r >= 0 && l >= 0 && s[l] == t[r]; l--, r--)
          ;
        lok = (r == -1);
        for (l = j + 1, r = k + 1; r < t.length() && l < n && sr[l] == t[r];
             l++, r++)
          ;
        rok = (r == t.length());
        ok |= lok & rok;
      }
    }
  }
  if (ok)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt--) _solve();
  return 0;
}
