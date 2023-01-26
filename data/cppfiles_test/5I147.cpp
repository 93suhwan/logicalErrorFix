#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<long long> v;
  map<long long, long long> mp;
  long long n, m, j, k, y, i, x, r;
  string s, t;
  cin >> n >> s >> t;
  long long ans = 0;
  for (i = 0; i < n; i++) {
    if (t[i] == '1') {
      if (i == 0) {
        if (s[i] == '0') {
          s[i] = '2';
          ans++;
        } else if (s[i + 1] == '1' && i < n - 1) {
          ans++;
        }
      } else if (i > 0 && i < n - 1) {
        if (s[i - 1] == '1') {
          ans++;
        } else if (s[i] == '0') {
          s[i] = '2';
          ans++;
        } else if (s[i + 1] == '1') {
          ans++;
        }
      } else if (i == n - 1) {
        if (s[i] == '0') {
          s[i] = '2';
          ans++;
        } else if (s[i - 1] == '1' && i > 0) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
