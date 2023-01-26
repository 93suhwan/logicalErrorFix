#include <bits/stdc++.h>
using namespace std;
template <typename Head>
inline void dout(Head in) {
  cerr << in << '\n';
}
long long bp(long long n, long long m, long long mod) {
  long long res = 1;
  while (m) {
    m & 1 ? res = res * n % mod : res;
    n = n * n % mod;
    m >>= 1LL;
  }
  return res;
}
int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  long long constexpr mod = (long long)998244353;
  int constexpr maxn = (int)2e5 + 1;
  vector<long long> fac(maxn);
  fac[0] = fac[1] = 1LL;
  for (int i = 2; i < maxn; i++) {
    fac[i] = fac[i - 1] * (long long)i % mod;
  }
  vector<long long> inv(maxn);
  inv[maxn - 1] = bp(fac[maxn - 1], mod - 2, mod);
  for (int i = maxn - 2; ~i; i--) {
    inv[i] = inv[i + 1] * (long long)(i + 1) % mod;
  }
  function<long long(long long, long long)> A = [&](long long l, long long r) {
    return fac[r] * inv[l] % mod;
  };
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    map<long long, long long> cnt;
    for (long long &e : a) {
      cin >> e;
      cnt[e]++;
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    if ((int)a.size() == 1) {
      cout << fac[n] << "\n";
      continue;
    }
    if (a.back() - a[(int)a.size() - 2] > 1) {
      cout << "0\n";
      continue;
    }
    long long ans = fac[n];
    long long minus = fac[cnt[a[(int)a.size() - 2]]] % mod *
                      A(cnt[a[(int)a.size() - 2]] + 1, n) % mod;
    ans -= minus;
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans << "\n";
  }
  return 0;
}
