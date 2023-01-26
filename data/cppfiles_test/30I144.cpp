#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = n + 1;
  for (long long i = 0; i < 26; i++) {
    long long l = 0, r = n - 1, c = 0;
    while (l <= r) {
      if (s[l] == s[r]) {
        l++;
        r--;
      } else if (s[i] == s[l]) {
        l++;
        c++;
      } else if (s[i] == s[r]) {
        c++;
        r--;
      } else {
        c = n + 1;
        break;
      }
    }
    ans = min(ans, c);
  }
  if (ans == (n + 1)) {
    cout << "-1" << endl;
    return;
  } else {
    cout << ans << endl;
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
