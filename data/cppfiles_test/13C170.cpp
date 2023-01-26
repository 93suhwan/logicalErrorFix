#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a = 0, b = 0, c = 0;
  string s;
  cin >> s;
  if (s.length() & 1)
    cout << "NO";
  else {
    for (long long i = 0; i < s.length(); ++i) {
      if (s[i] == 'A')
        a++;
      else {
        if (s[i] == 'C')
          c++;
        else
          b++;
      }
    }
    if ((a == b && c == 0) || (b == c && a == 0) || a + c == b)
      cout << "YES";
    else
      cout << "NO";
  }
}
signed main() {
  ios::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
