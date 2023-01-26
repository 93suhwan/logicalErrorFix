#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, i;
    string s;
    cin >> s;
    n = s.length();
    long long ans = 0;
    i = 0;
    for (i = 0; i < n; i++) {
      if (s[i] == '0') {
        while (s[i] == '0') i++;
        i--;
        ans++;
      }
    }
    cout << min(ans, 2LL) << '\n';
  }
  return 0;
}
