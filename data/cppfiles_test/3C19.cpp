#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long sz = (long long)s.size();
  long long ka = 1;
  for (long long i = 0; i < sz; i++) ka *= 10;
  long long ki = ka / 10;
  if (sz == 1)
    ki = 0;
  else if (sz == 2)
    ki = 25;
  long long ans = 0;
  for (long long i = ki; i < ka; i += 25) {
    string t = to_string(i);
    long long tambah = 1;
    long long x = -1;
    for (long long j = 0; j < sz; j++) {
      if (s[j] != t[j]) {
        if (s[j] != '_' && s[j] != 'X') {
          tambah = 0;
          break;
        }
        if (s[j] == 'X') {
          if (x == -1) {
            x = t[j] - '0';
          } else if (x != t[j] - '0') {
            tambah = 0;
            break;
          }
        }
      }
    }
    ans += tambah;
  }
  cout << ans << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long tc = 1;
  while (tc--) solve();
  return 0;
}
