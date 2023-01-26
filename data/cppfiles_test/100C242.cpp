#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const long long MOD = 998244353;
long long facts[200000 + 5];
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res *= a;
      res %= MOD;
    }
    a *= a;
    a %= MOD;
    n >>= 1;
  }
  return res;
}
long double bin_search(long double num) {
  long double l = 0;
  long double r = num;
  while (r - l >= 1e-7) {
    long double m = (r + l) / 2;
    if (m * m > num) {
      r = m;
    } else {
      l = m;
    }
  }
  return l;
}
long long fact(long long n) { return (facts[n] + MOD) % MOD; }
long long C(long long n, long long m) {
  long long top = fact(n);
  return (((((top * binpow(fact(m), MOD - 2)) + MOD) % MOD) *
               binpow(fact(n - m), MOD - 2) +
           MOD) %
          MOD);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> inp(n);
  long long cntMax = 0;
  long long _max = INT_MIN;
  set<long long> elems;
  map<long long, long long> cnts;
  for (long long i = 0; i < n; i++) {
    cin >> inp[i];
    elems.insert(inp[i]);
    if (inp[i] > _max) {
      cntMax = 0;
      _max = inp[i];
    }
    if (inp[i] == _max) {
      cntMax++;
    }
    cnts[inp[i]]++;
  }
  if (cntMax > 1) {
    cout << fact(n) << '\n';
    return;
  }
  elems.erase(_max);
  long long beforeMax = *elems.rbegin();
  if (_max - beforeMax > 1) {
    cout << 0 << '\n';
    return;
  }
  long long ans = fact(n);
  long long m = n - cnts[beforeMax] - 1;
  for (long long i = 0; i <= m; i++) {
    long long comb = C(m, i);
    long long firstFact = fact(i);
    long long secondFact = fact(n - i - 1);
    assert(comb > 0);
    assert(firstFact > 0);
    assert(secondFact > 0);
    long long tmp = (comb * firstFact) + MOD;
    tmp %= MOD;
    tmp *= secondFact;
    tmp %= MOD;
    ans -= tmp;
    ans += MOD;
    ans %= MOD;
    assert(ans > 0);
  }
  cout << ans << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  facts[0] = 1;
  for (long long i = 1; i < 200000 + 5; i++) {
    facts[i] = (facts[i - 1] * i) % MOD;
  }
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "\nTime: " << (double)clock() / CLOCKS_PER_SEC << endl;
  return 0;
}
