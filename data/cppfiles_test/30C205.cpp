#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long LINF = 1e18 + 5, INF = 0x3f3f3f3f, hxe = 1319, mod = 1e18 + 5;
inline long long Qpow(long long a, long long b) {
  long long s = 1;
  while (b) {
    if (b & 1) {
      s = (s * a) % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return s;
}
string str;
long long check(int x) {
  char c = 'a' + x - 1;
  int l = 0, r = str.size() - 1;
  int res = 0;
  while (l < r) {
    if (str[l] == str[r]) {
      l++, r--;
      continue;
    }
    if (str[l] != str[r] && str[l] == c) {
      l++;
      res++;
      continue;
    }
    if (str[l] != str[r] && str[r] == c) {
      r--;
      res++;
      continue;
    }
    return INF;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  cin >> str;
  long long ans = INF;
  for (int i = (1); i <= (26); ++i) ans = min(ans, check(i));
  ans = ans == INF ? -1 : ans;
  cout << ans << endl;
  return;
}
int main() {
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}
