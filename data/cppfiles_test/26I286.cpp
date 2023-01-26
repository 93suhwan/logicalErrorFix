#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
void solve() {
  long long n, k, i, ans = 0, a = 0, b = 0, c = 0, d = 0;
  string s;
  cin >> s;
  string t = s;
  for (i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      if (s[i] == '?') s[i] = '1';
      if (t[i] == '?') t[i] = '0';
    } else {
      if (s[i] == '?') s[i] = '0';
      if (t[i] == '?') t[i] = '1';
    }
  }
  for (i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      if (s[i] == '1') a++;
      if (t[i] == '1') c++;
    } else {
      if (s[i] == '1') b++;
      if (t[i] == '1') d++;
    }
    if (abs(a - b) >= (10 - i) / 2 || abs(c - d) >= (10 - i) / 2) {
      cout << i + 2 << "\n";
      return;
    }
  }
  cout << 10 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
