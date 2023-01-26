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
int32_t main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  long long constexpr mod = (long long)998244353;
  long long constexpr maxn = (long long)2e5 + 1;
  vector<long long> fac(maxn);
  fac[0] = fac[1] = 1LL;
  for (long long i = 2; i < maxn; i++) {
    fac[i] = fac[i - 1] * (long long)i % mod;
  }
  vector<long long> inv(maxn);
  inv[maxn - 1] = bp(fac[maxn - 1], mod - 2, mod);
  for (long long i = maxn - 2; ~i; i--) {
    inv[i] = inv[i + 1] * (long long)(i + 1) % mod;
  }
  function<long long(long long, long long)> A = [&](long long l, long long r) {
    if (l > r) {
      return 1LL;
    }
    return fac[r] * inv[l] % mod;
  };
  long long t;
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
    if ((long long)a.size() == 1) {
      cout << fac[n] << "\n";
      continue;
    }
    if (a.back() - a[(long long)a.size() - 2] > 1) {
      cout << "0\n";
      continue;
    }
    long long ans = fac[n];
    long long minus = cnt[a.back()] * fac[cnt[a[(long long)a.size() - 2]]] %
                      mod *
                      A(cnt[a[(long long)a.size() - 2]],
                        cnt[a.back()] + cnt[(long long)a.size() - 2] - 2) %
                      mod;
    minus = minus * A(cnt[a.back()] + cnt[a[(long long)a.size() - 2]], n) % mod;
    ans -= minus;
    cout << (ans + mod) % mod << "\n";
  }
  return 0;
}
