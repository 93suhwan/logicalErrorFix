#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, t;
  cin >> s >> t;
  long long n = s.size();
  long long m = 3;
  bool f1 = false, f2 = false;
  sort(s.begin(), s.end());
  if (t[0] == 'a') {
    for (long long i = 0; i < 3; i++) {
      if (t[i] == 'b') f1 = true;
      if (t[i] == 'c') f2 = true;
      if (f1 || f2) break;
    }
    if (f2) {
      cout << s << endl;
    } else {
      bool f = false, g = false, h = false;
      long long indb = n, indc = n;
      for (long long i = 0; i < n; i++) {
        if (s[i] == 'a') f = true;
        if (s[i] == 'b') {
          indb = min(indb, i);
          g = true;
        }
        if (s[i] == 'c') {
          indc = min(indc, i);
          h = true;
        }
      }
      if (f && g && h) {
        for (long long i = 0; i < n; i++)
          if (s[i] == 'a') cout << s[i];
        for (long long i = indc; i < n; i++)
          if (s[i] == 'c') cout << s[i];
        for (long long i = 0; i < n; i++)
          if (s[i] != 'a' && s[i] != 'c') cout << s[i];
        cout << endl;
      } else
        cout << s << endl;
    }
  } else {
    cout << s << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
