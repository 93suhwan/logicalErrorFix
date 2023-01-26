#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string top;
  string bot;
  cin >> top >> bot;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (bot[i] == '1') {
      if (i - 1 >= 0 && top[i - 1] == '1') {
        ans += 1;
        top[i - 1] = 0;
        continue;
      }
      if (top[i] == '0') {
        ans++;
        continue;
      }
      if (i + 1 < n && top[i + 1] == '1') {
        ans += 1;
        top[i + 1] = 0;
      }
    }
  }
  cout << ans << "\n";
  ;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
