#include <bits/stdc++.h>
using namespace std;
const string yes = "YES";
const string no = "NO";
signed main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        ans += 2;
        continue;
      }
      if (i == n - 1) {
        if (s1[i] == '0') ans++;
        continue;
      }
      if (s1[i] == '0') {
        if (s1[i + 1] == '1' && s2[i + 1] == '1') {
          ans += 2;
          i++;
        } else
          ans++;
        continue;
      }
      long long j = i;
      while (j < n && s1[j] == '1' && s2[j] == '1') {
        j++;
      }
      ans += 2;
      i = j;
    }
    cout << ans << '\n';
  }
  return 0;
}
