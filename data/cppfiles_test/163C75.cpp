#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long T, N, M, R, C, Rd, Cd, P;
long long inv(long long x) {
  long long ans = 1;
  for (long long i = 0; i < 35; i++) {
    if ((MOD - 2) & (1LL << i)) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> N >> M >> R >> C >> Rd >> Cd >> P;
    R--, C--, Rd--, Cd--;
    long long Pb = (100 - P) * inv(100) % MOD;
    vector<pair<long long, long long>> cc;
    long long dr = 1, dc = 1, tR = R, tC = C;
    bool ok = 0;
    while (true) {
      bool fr = 0, fc = 0;
      if (tR + dr < 0 || tR + dr >= N) dr = -dr, fr = 1;
      if (tC + dc < 0 || tC + dc >= M) dc = -dc, fc = 1;
      if (ok && R == tR && C == tC && (fr || dr == 1) && (fc || dc == 1)) break;
      cc.push_back({tR, tC});
      tR += dr, tC += dc;
      ok = 1;
    };
    reverse(cc.begin(), cc.end());
    long long m = 1, b = 0;
    for (pair<long long, long long> i : cc) {
      long long r = i.first, c = i.second;
      b = (b + 1) % MOD;
      if (r == Rd || c == Cd) {
        m = m * Pb % MOD;
        b = b * Pb % MOD;
      }
    }
    m = (1 - m + MOD) % MOD;
    cout << b * inv(m) % MOD << '\n';
  }
}
