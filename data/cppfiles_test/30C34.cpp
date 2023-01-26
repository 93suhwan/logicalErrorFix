#include <bits/stdc++.h>
using namespace std;
void solve(int tc) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = n + 1;
  for (int i = 0; i < 26; i++) {
    int lo = 0, hi = n - 1;
    int cnt = 0;
    while (lo <= hi) {
      if (s[lo] == s[hi]) {
        lo++;
        hi--;
      } else if (s[lo] == ('a' + i)) {
        cnt++;
        lo++;
      } else if (s[hi] == ('a' + i)) {
        cnt++;
        hi--;
      } else {
        cnt = n + 1;
        break;
      }
    }
    ans = min(ans, cnt);
  }
  if (ans == n + 1) {
    cout << -1 << '\n';
  } else
    cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
}
