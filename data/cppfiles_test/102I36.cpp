#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 1000;
const long long MOD = 998244353;
using namespace std;
long long pw(long long u, long long v) {
  if (v == 0) return 1;
  long long ret = pw(u, v / 2);
  ret = (ret * ret) % MOD;
  if (v % 2 == 1) ret = (ret * u) % MOD;
  return ret;
}
long long fact[KL + 10], inv[KL + 10], invi[KL + 10];
void mk() {
  fact[0] = invi[0] = invi[1] = inv[0] = 1;
  for (long long i = 1; i < KL; i++) fact[i] = (fact[i - 1] * i) % MOD;
  for (long long i = 2; i < KL; i++) {
    invi[i] = invi[MOD % i] * (MOD - MOD / i) % MOD;
  }
  for (long long i = 1; i < KL; i++) inv[i] = inv[i - 1] * invi[i] % MOD;
}
long long dv(long long u, long long v) { return (u * pw(v, MOD - 2)) % MOD; }
long long C(long long u, long long v) {
  if (u < v) return 0;
  long long ret = (inv[v] * inv[u - v]) % MOD * fact[u] % MOD;
  return ret;
}
long long k, A, h;
long long ppw[KL], p[KL];
int main() {
  ppw[0] = 1;
  for (int i = 1; i <= 31; i++) {
    ppw[i] = 2LL * ppw[i - 1];
  }
  mk();
  scanf("%lld", &k);
  scanf("%lld", &A);
  scanf("%lld", &h);
  for (long long i = 0; i < ppw[20]; i++) {
    long long ret = 0;
    vector<long long> vec;
    for (int j = 1; j <= ppw[k]; j++) {
      vec.push_back(j);
    }
    int cnt = 0;
    while (vec.size()) {
      if (vec.size() == 1) {
        ret += vec[0] * A;
        p[vec[0]] = 1;
        ret %= MOD;
        break;
      }
      vector<long long> nw;
      for (int j = 1; j < vec.size(); j += 2) {
        if ((i & ppw[cnt])) {
          nw.push_back(vec[j - 1]);
          long long po = (long long)vec.size() / 2 + 1;
          p[vec[j]] = po;
          ret += vec[j] * pw(A, po);
          ret %= MOD;
        } else {
          nw.push_back(vec[j]);
          long long po = (long long)vec.size() / 2 + 1;
          ret += vec[j - 1] * pw(A, po);
          p[vec[j - 1]] = po;
          ret %= MOD;
        }
        cnt++;
      }
      vec.clear();
      for (auto v : nw) vec.push_back(v);
    }
    if (ret == h) {
      for (int i = 1; i <= ppw[k]; i++) printf("%lld ", p[i]);
      printf("\n");
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
