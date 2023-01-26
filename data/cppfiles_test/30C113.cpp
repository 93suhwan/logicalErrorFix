#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = n + 1;
  for (int c = 0; c < 26; c++) {
    char ch = 'a';
    ch += c;
    long long l = 0, r = n - 1;
    bool ok = true;
    long long count = 0;
    while (l <= r) {
      if (s[l] == s[r]) {
        l++;
        r--;
      } else if (s[l] == ch) {
        count++;
        l++;
      } else if (s[r] == ch) {
        count++;
        r--;
      } else {
        ok = false;
        break;
      }
    }
    if (ok) ans = min(ans, count);
  }
  if (ans == n + 1) ans = -1;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
