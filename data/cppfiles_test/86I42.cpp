#include <bits/stdc++.h>
using namespace std;
long long a[2000000], dp[1000000];
int main() {
  long long test_cases = 1, tc = 0;
  cin >> test_cases;
  while (test_cases-- && ++tc) {
    long long n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    long long i = 0, last = -10, ans = 0;
    while (i < n) {
      if ((s[0][i] == '0' && s[1][i] == '1') ||
          (s[0][i] == '1' && s[1][i] == '0'))
        ans += 2;
      else if (s[0][i] == '0' && s[1][i] == '0') {
        if (last == i - 1)
          ans += 2, last = -10;
        else
          last = i;
      } else
        last = i;
      i++;
    }
    cout << ans << endl;
  }
  return 0;
}
