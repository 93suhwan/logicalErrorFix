#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7, n, m, ans, y, cnt;
string s;
short j;
int inn() {
  int x;
  cin >> x;
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _tc;
  cin >> _tc;
  while (_tc--) {
    n = inn();
    m = inn();
    ans = 0;
    j = 0;
    s = bitset<64>(m).to_string();
    reverse(s.begin(), s.end());
    long long h = 1;
    for (int i = 0; i < s.size(); i++) {
      h *= n;
      h %= mod;
      if (j == 0) h = 1;
      if (s[i] == '1') {
        ans += h % mod;
        ans %= mod;
      }
      j++;
    }
    cout << ans << "\n";
  }
  return 0;
}
