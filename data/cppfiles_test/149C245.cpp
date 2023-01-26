#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    x--;
    string ans = "";
    for (long long i = n - 1; i >= 0; i--) {
      if (s[i] == 'a') {
        ans += 'a';
        continue;
      }
      long long j = i;
      while (j >= 0 && s[j] == s[i]) j--;
      long long val = k * (i - j) + 1;
      for (long long p = 0; p < x % val; p++) ans += 'b';
      x /= val;
      i = j + 1;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
  }
}
