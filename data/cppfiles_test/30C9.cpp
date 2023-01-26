#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = INT_MAX;
    for (char i = 'a'; i <= 'z'; i++) {
      long long cnt = 0;
      int l = 0, r = n - 1;
      while (l <= r) {
        if (s[l] == s[r]) {
          l++;
          r--;
        } else {
          if (s[l] == i) {
            l++;
            cnt++;
          } else if (s[r] == i) {
            r--;
            cnt++;
          } else {
            cnt = INT_MAX;
            break;
          }
        }
      }
      ans = min(ans, cnt);
    }
    if (ans == INT_MAX)
      cout << "-1\n";
    else
      cout << ans << endl;
  }
  return 0;
}
