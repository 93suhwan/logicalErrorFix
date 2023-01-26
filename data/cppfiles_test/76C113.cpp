#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
const ll inf = 1e18;
void pline(vector<ll> lis) {
  for (ll(i) = (0); (i) < (lis.size()); (i)++) {
    printf("%lld", lis[i]);
    if (i != lis.size() - 1)
      printf(" ");
    else
      printf("\n");
  }
}
ll max(int x, ll y) { return max((ll)x, y); }
ll max(ll x, int y) { return max(x, (ll)y); }
vector<ll> Sieve(ll n, ll mode = 0) {
  vector<ll> plis(0);
  vector<ll> divlis(n + 1, -1);
  vector<ll> flag(n + 1, 1);
  flag[0] = 0;
  flag[1] = 0;
  ll ind = 2;
  while (ind <= n) {
    if (flag[ind]) {
      plis.push_back(ind);
      ll ind2 = ind * ind;
      while (ind2 <= n) {
        flag[ind2] = 0;
        divlis[ind2] = ind;
        ind2 += ind;
      }
    }
    ind += 1;
  }
  if (mode == 0) {
    return plis;
  } else {
    return divlis;
  }
}
int main() {
  auto divlis = Sieve(4000010, 1);
  ll n, mod;
  scanf("%lld%lld", &n, &mod);
  vector<ll> nind(4000010, -1);
  vector<ll> dp(4000010, 0);
  dp[1] = 1;
  ll nsum = 0;
  ll dps = 1;
  for (ll(i) = (2); (i) < (n + 1); (i)++) {
    nsum += 1;
    vector<ll> s(1, 1);
    ll j = i;
    while (divlis[j] != -1) {
      ll ds = divlis[j];
      vector<ll> t(0);
      ll cnt = ds;
      while (j % ds == 0) {
        t.push_back(cnt);
        j /= ds;
        cnt *= ds;
      }
      vector<ll> u(0);
      for (ll x : s) {
        for (ll y : t) {
          u.push_back(x * y);
        }
      }
      for (ll z : u) {
        s.push_back(z);
      }
    }
    if (j != 1) {
      ll ds = j;
      vector<ll> t(0);
      ll cnt = ds;
      while (j % ds == 0) {
        t.push_back(cnt);
        j /= ds;
        cnt *= ds;
      }
      vector<ll> u(0);
      for (ll x : s) {
        for (ll y : t) {
          u.push_back(x * y);
        }
      }
      for (ll z : u) {
        s.push_back(z);
      }
    }
    for (ll x : s) {
      if (x != 1 && x != i) {
        nsum -= dp[nind[x]];
        nsum = (nsum + mod) % mod;
        nind[x]++;
        nsum += dp[nind[x]];
        nsum %= mod;
      }
    }
    dp[i] = (dps + nsum) % mod;
    dps += dp[i];
    dps %= mod;
    nind[i] = 1;
  }
  cout << dp[n] << '\n';
}
