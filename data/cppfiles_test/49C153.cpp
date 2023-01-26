#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll pwr(ll a, ll pw) {
  ll ret = 1;
  while (pw > 0) {
    if (pw & 1) {
      ret = ret * a % mod;
    }
    a = a * a % mod;
    pw >>= 1;
  }
  return ret;
}
ll modinv(ll a) { return pwr(a, mod - 2); }
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<vector<ll> > prob_win(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      prob_win[i][j] = v[i] * modinv(v[i] + v[j]) % mod;
      prob_win[j][i] = v[j] * modinv(v[i] + v[j]) % mod;
    }
  }
  vector<vector<ll> > win_msk(n, vector<ll>(1 << n, 1ll));
  for (int i = 0; i < n; i++) {
    for (int msk = 0; msk < 1 << n; msk++) {
      for (int bit = 0; bit < n; bit++) {
        if (msk >> bit & 1) {
          win_msk[i][msk] = win_msk[i][msk] * prob_win[i][bit] % mod;
        }
      }
    }
  }
  ll ans = 0;
  vector<ll> dp_prob(1 << n, 1ll);
  for (int msk = 1; msk < 1 << n; msk++) {
    ll num_winners = __builtin_popcount(msk);
    for (int bit = 0; bit < n; bit++) {
      if (msk >> bit & 1) {
        dp_prob[msk] = dp_prob[msk] * win_msk[bit][(1 << n) - 1 - msk] % mod;
      }
    }
    for (int sub_winners = (msk - 1) & msk; sub_winners > 0;
         sub_winners = (sub_winners - 1) & msk) {
      int sub_losers = msk ^ sub_winners;
      ll p = dp_prob[sub_winners];
      for (int bit = 0; bit < n; bit++) {
        if (sub_losers >> bit & 1) {
          p = p * win_msk[bit][(1 << n) - 1 - msk] % mod;
        }
      }
      dp_prob[msk] = (dp_prob[msk] - p + mod) % mod;
    }
    ans = (ans + dp_prob[msk] * num_winners % mod) % mod;
  }
  cout << ans << "\n";
  return 0;
}
