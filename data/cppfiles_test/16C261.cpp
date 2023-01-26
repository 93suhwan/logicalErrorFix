#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long inf = 8e18;
const int LOG = 20;
long long pw(long long a, long long b, long long M = mod, long long ret = 1) {
  while (b) {
    ret = ret * (b & 1 ? a : 1) % M, a = a * a % M, b >>= 1;
  }
  return ret;
}
int n, cnt[30];
string s;
void solve() {
  cin >> n >> s;
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  string t;
  int ans = 0, ptr = 0;
  for (int i = 0; i < 30; i++) {
    while (cnt[i]) {
      cnt[i]--;
      if (s[ptr] - 'a' == i) {
        ans++;
      }
      ptr++;
    }
  }
  cout << n - ans << endl;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
