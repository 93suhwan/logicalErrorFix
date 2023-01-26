#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MAXN = 2e6 + 700;
int main() {
  long long t, n;
  cin >> t;
  while (t--) {
    string s;
    cin >> n >> s;
    long long ans = 0;
    for (long long i = 0; i < s.size(); i++) {
      if (s[i] != '0') {
        ans += s[i] - '0';
        if (i != s.size() - 1) ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
