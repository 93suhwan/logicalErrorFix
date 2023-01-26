#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return l + rng() % (r - l + 1); }
const int mod = 998244353;
string s[30];
int n, cnt[30][30], sl[30];
int f[(1 << 23) + 2];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  cin >> n;
  for (int i = 0; i <= n - 1; i++) {
    cin >> s[i];
    for (auto& c : s[i]) cnt[i][c - 'a']++;
  }
  for (int mask = 1; mask <= (1 << n) - 1; mask++) {
    for (int j = 0; j <= 25; j++) sl[j] = 1e9;
    for (int i = 0; i <= n - 1; i++)
      if (((mask >> i) & 1)) {
        for (int j = 0; j <= 25; j++) sl[j] = min(sl[j], cnt[i][j]);
      }
    f[mask] = 1;
    for (int j = 0; j <= 25; j++) f[mask] = f[mask] * (sl[j] + 1) % mod;
  }
  for (int mask = 0; mask <= (1 << n) - 1; mask++) {
    if (__builtin_popcount(mask) % 2) f[mask] = -f[mask];
  }
  for (int i = 0; i <= n - 1; i++) {
    for (int mask = 0; mask <= (1 << n) - 1; mask++)
      if (((mask >> i) & 1)) f[mask] += f[(mask ^ (1 << i))];
  }
  long long kq = 0;
  for (int mask = 0; mask <= (1 << n) - 1; mask++) {
    f[mask] = ((-f[mask]) % mod + mod) % mod;
    int gay = 0, k = 0;
    for (int i = 0; i <= n - 1; i++)
      if (((mask >> i) & 1)) {
        gay += i + 1;
        ++k;
      }
    kq = (kq ^ (1ll * k * gay * f[mask]));
  }
  cout << kq;
}
