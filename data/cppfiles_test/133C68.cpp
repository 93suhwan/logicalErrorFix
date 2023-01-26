#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s = "";
  for (int i = 0; i < n - 2; i++) {
    string x;
    cin >> x;
    s += x;
  }
  string ans = "";
  if (n == 3) {
    cout << 'b' + s << "\n";
  } else {
    ans += s[0];
    for (int i = 1; i < s.size();) {
      if (s[i] == s[i + 1]) {
        ans += s[i];
        i = i + 2;
      } else {
        ans += s[i];
        if (i + 1 < s.size()) {
          ans += s[i + 1];
        }
        i = i + 2;
      }
    }
    if (n > ans.size()) {
      ans += 'a';
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
