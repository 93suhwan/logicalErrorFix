#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int INF = 1234567890;
const long long MAX = 100003;
const double epsi = 0.0000001;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') continue;
      ans += (s[i] - '0');
      if (i != n - 1) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
