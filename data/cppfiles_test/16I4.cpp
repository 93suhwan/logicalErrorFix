#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
void init_code() {}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a[26] = {0};
  for (long long i = 0; i < n; i++) {
    a[s[i] - 'a']++;
  }
  int count = 0;
  int num = 0;
  for (long long i = 0; i < 26; i++) {
    if (a[i] != 0) {
      count++;
      if (a[i] > 1) num++;
    }
  }
  if (count == 1 || num > 1) {
    cout << --count << endl;
    return;
  }
  cout << count << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
