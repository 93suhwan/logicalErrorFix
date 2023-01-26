#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 5;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long cnt = count(s.begin(), s.end(), '?');
  if (cnt == n) {
    string ans;
    for (long long i = 0; i < n; i++) {
      if (i % 2)
        ans += 'B';
      else
        ans += 'R';
    }
    cout << ans << "\n";
    return;
  }
  if (s[0] == '?') {
    if (s[1] == 'B')
      s[0] = 'R';
    else if (s[1] == 'R')
      s[0] = 'B';
    else {
      s[0] = 'B';
      string k = s;
      for (long long i = 1; i < n - 1; i++) {
        char c = s[i - 1];
        char a = s[i + 1];
        if (s[i] == '?') {
          if (c == 'B')
            s[i] = 'R';
          else if (c == 'R')
            s[i] = 'B';
        }
      }
      if (s[n - 1] == '?') {
        if (s[n - 2] == 'B')
          s[n - 1] = 'R';
        else if (s[n - 2] == 'R')
          s[n - 1] = 'B';
      }
      string an = s;
      long long cnt = 0;
      for (long long i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) cnt++;
      }
      s = k;
      s[0] = 'R';
      for (long long i = 1; i < n - 1; i++) {
        char c = s[i - 1];
        char a = s[i + 1];
        if (s[i] == '?') {
          if (c == 'B')
            s[i] = 'R';
          else if (c == 'R')
            s[i] = 'B';
        }
      }
      if (s[n - 1] == '?') {
        if (s[n - 2] == 'B')
          s[n - 1] = 'R';
        else if (s[n - 2] == 'R')
          s[n - 1] = 'B';
      }
      long long l = 0;
      for (long long i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) l++;
      }
      if (l > cnt) {
        cout << an << "\n";
        return;
      } else {
        cout << s << "\n";
        return;
      }
    }
  }
  for (long long i = 1; i < n - 1; i++) {
    char c = s[i - 1];
    char a = s[i + 1];
    if (s[i] == '?') {
      if (c == 'B')
        s[i] = 'R';
      else if (c == 'R')
        s[i] = 'B';
    }
  }
  if (s[n - 1] == '?') {
    if (s[n - 2] == 'B')
      s[n - 1] = 'R';
    else if (s[n - 2] == 'R')
      s[n - 1] = 'B';
  }
  cout << s << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
