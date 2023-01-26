#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const long long int int_max = 1e18;
const long long int int_min = -1e18;
const long double PI = acos(-1);
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string s[n + 2];
  for (long long int i = 1; i <= n - 2; i++) {
    cin >> s[i];
  }
  string ans = s[1];
  for (long long int i = 2; i <= n - 2; i++) {
    if (s[i][0] == s[i - 1][1]) {
      ans += s[i][1];
    } else {
      ans += s[i];
    }
  }
  long long int sz = ans.size();
  if (sz != n) {
    ans += 'b';
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
