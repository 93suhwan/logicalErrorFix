#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long ab = 0, ba = 0, n = s.length();
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] == 'a' && s[i + 1] == 'b') ab++;
    if (s[i] == 'b' && s[i + 1] == 'a') ba++;
  }
  if (ab == ba) {
    cout << s;
    return;
  } else if (ab > ba) {
    for (long long i = 0; i < n - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b') {
        if (i == 0 || s[i - 1] == 'b') {
          s[i] = 'b';
          ab--;
        }
      }
      if (ab == ba) {
        cout << s;
        return;
      }
    }
  } else {
    for (long long i = 0; i < n - 1; i++) {
      if (s[i] == 'b' && s[i + 1] == 'a') {
        if (i == 0 || s[i - 1] == 'a') {
          s[i] = 'a';
          ab--;
        }
      }
      if (ab == ba) {
        cout << s;
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
