#include <bits/stdc++.h>
using namespace std;
bool formed(int n, string s) {
  char d = '?';
  for (int i = s.size() - 1; i >= 0; i--) {
    int x = n % 10;
    n /= 10;
    char c = x + '0';
    if (c == s[i]) continue;
    if (s[i] == '_') continue;
    if (s[i] == 'X' && d == '?') {
      d = c;
      continue;
    }
    if (s[i] == 'X' && d == c) continue;
    return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  while (test--) {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
      if (s == "0")
        cout << 1;
      else
        cout << 0;
      continue;
    }
    int hi = 1;
    for (int i = 0; i < n - 2; i++) hi *= 10;
    int lo = hi / 10;
    string te = "";
    te += s[n - 2];
    te += s[n - 1];
    int ans = 0;
    for (int i = 0; i <= 75; i += 25) {
      if (i == 0 && n == 2) continue;
      string t;
      if (!formed(i, te)) continue;
      if (n == 2) {
        ans++;
        continue;
      }
      string temp = s.substr(0, n - 2);
      for (int j = lo; j < hi; j++) {
        if (formed(j, temp)) ans++;
      }
    }
    cout << ans;
  }
  return 0;
}
