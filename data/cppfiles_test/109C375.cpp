#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (i == s.size() - 1) {
      ans += (s[i] - '0');
    } else {
      if (s[i] - '0' != 0) {
        ans += ((s[i] - '0') + 1);
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
