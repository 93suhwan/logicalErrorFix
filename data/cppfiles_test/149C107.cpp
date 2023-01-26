#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k, x;
    cin >> n >> k >> x;
    string s, ans;
    ans = "";
    cin >> s;
    x--;
    reverse(s.begin(), s.end());
    long long i = 0;
    while (i < n) {
      if (s[i] == 'a') {
        ans += 'a';
        i++;
        continue;
      }
      long long d = 0;
      while (i < n && s[i] == '*') {
        d += k;
        i++;
      }
      for (int j = 0; j < x % (d + 1); j++) ans += 'b';
      x /= (d + 1);
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
  return 0;
}
