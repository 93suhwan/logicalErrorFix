#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
long long ksm(long long b, long long e) {
  long long res = 1;
  while (e) {
    if (e & 1) res = (res * b) % mod;
    b = b * b % mod;
    e >>= 1;
  }
  return res;
}
long long inv(long long x) { return ksm(x, mod - 2); }
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
int main() {
  int t;
  cin >> t;
  for (; t > 0; t--) {
    int n, m, rb, cb, rd, cd, p;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    int tt = (2 * n - 2) * (2 * m - 2) / (int)gcd(2 * n - 2, 2 * m - 2);
    vector<long long> k;
    int cnt = 0;
    for (int i = 0; i < tt; i++) {
      if ((i + rb - 1) % (2 * n - 2) == rd - 1 ||
          (i + rb - 1) % (2 * n - 2) == (2 * n - 1 - rd) ||
          (i + cb - 1) % (2 * m - 2) == cd - 1 ||
          (i + cb - 1) % (2 * m - 2) == (2 * m - 1 - cd)) {
        cnt++;
        k.push_back(i);
      }
    }
    long long pro = ((100 - p) * inv(100)) % mod;
    long long period = ksm(pro, cnt);
    long long q = (1 - period + mod) % mod;
    long long time = (period * (inv(q))) % mod * tt;
    time %= mod;
    long long pr = (p * inv(100)) % mod;
    long long exp = 0;
    for (int i = 0; i < k.size(); i++) {
      long long add = (k[i] * pr) % mod;
      add *= ksm(pro, i);
      add %= mod;
      add *= inv(q);
      add %= mod;
      long long add1 =
          (((k[i] * (pr * ksm(pro, i)) % mod) % mod) * inv(q)) % mod;
      exp += add;
      exp %= mod;
    }
    cout << (exp + time) % mod << endl;
  }
}
