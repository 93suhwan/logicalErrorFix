#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, i;
    cin >> n;
    string s, s1;
    cin >> s;
    cin >> s1;
    long long int ans = 0;
    for (i = 0; i < n; i++) {
      if (s1[i] == '0') {
        continue;
      }
      if (s[i] == '0') {
        ans++;
      } else {
        if (i - 1 >= 0 && s[i - 1] == '1') {
          s[i - 1] = '0';
          ans++;
        }
        if (i + 1 < n && s[i + 1] == '1') {
          s[i + 1] = '0';
          ans++;
        }
      }
    }
    cout << ans << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
