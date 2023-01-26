#include <bits/stdc++.h>
using namespace std;
long long solve(string s, char sec, char l) {
  long long n = s.size();
  long long last = n - 1;
  long long second = n - 2;
  if (s[last] == 'X') {
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'X') {
        s[i] = l;
      }
    }
  }
  if (s[second] == 'X') {
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'X') {
        s[i] = sec;
      }
    }
  }
  if (s[last] == '_') s[last] = l;
  if (s[second] == '_') s[second] = sec;
  long long ans = 0;
  if (s[last] == l and s[second] == sec and s[0] != '0') {
    ans = 1;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '_') {
        ans *= (i == 0 ? 9 : 10);
      }
    }
    bool found = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'X') {
        found = 1;
        break;
      }
    }
    if (found) {
      if (s[0] == 'X') {
        ans *= 9;
      } else
        ans *= 10;
    }
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  string s;
  cin >> s;
  if (s.size() == 1) {
    if (s[0] == 'X' || s[0] == '_' || s[0] == '0') {
      cout << 1 << "\n";
    } else
      cout << 0 << "\n";
  } else {
    long long ans = 0;
    ans += solve(s, '0', '0');
    ans += solve(s, '2', '5');
    ans += solve(s, '5', '0');
    ans += solve(s, '7', '5');
    cout << ans << "\n";
  }
  return 0;
}
