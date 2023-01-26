#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int INF = 1 << 30;
const double eps = 1e-6;
const long long mod = 998244353;
long long inv[maxn];
map<string, int> mp;
void init() {
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}
long long C(int n, int m) {
  if (m < 0) return 0;
  long long res = 1;
  for (int i = n; i > n - m; i--) res = res * i % mod;
  for (int i = 1; i <= m; i++) res = res * inv[i] % mod;
  return res;
}
long long qmod(long long b, long long c) {
  long long res = 1;
  while (c) {
    if (c & 1) res = res * b % mod;
    b = b * b % mod;
    c >>= 1;
  }
  return res;
}
long long fp() {
  long long res = qmod(2, mp["??"]);
  if (!mp["WB"] && !mp["W?"] && !mp["?B"]) res = (res - 1) % mod;
  if (!mp["BW"] && !mp["B?"] && !mp["?W"]) res = (res - 1) % mod;
  return (mod - res) % mod;
}
int main() {
  init();
  int n;
  cin >> n;
  int cb = 0, cw = 0;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    mp[s]++;
    for (auto c : s) {
      cb += (c == 'B');
      cw += (c == 'W');
    }
  }
  long long ans = C(2 * n - cb - cw, n - cb);
  if (mp.count("BB") == 0 && mp.count("WW") == 0) ans = (ans + fp()) % mod;
  cout << ans << endl;
  return 0;
}
