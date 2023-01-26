#include <bits/stdc++.h>
using namespace std;
const long long int MAX_N = 1e5 + 5;
const long long int MOD = 1e9 + 7;
const long long int INF = 1e9;
void solve() {
  long long int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  long long int res = 0;
  for (long long int i = 0; i < n; i++) {
    if (t[i] == '1') {
      if (s[i] == '0') {
        res++;
      } else if (i > 0 && s[i - 1] == '1') {
        res++;
        s[i - 1] = '0';
      } else if (i < n && s[i + 1] == '1') {
        res++;
        s[i + 1] = '0';
      }
    }
  }
  cout << res << "\n";
  ;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(10);
  cout << fixed;
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}
