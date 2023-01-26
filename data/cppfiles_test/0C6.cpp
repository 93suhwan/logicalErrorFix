#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
static inline long long safe_mod(long long a) {
  long long res = a % MOD;
  if (res < 0) res += MOD;
  return res;
}
static inline tuple<long long, long long> mult(tuple<long long, long long> a,
                                               tuple<long long, long long> b) {
  auto [a0, a1] = a;
  auto [b0, b1] = b;
  return {safe_mod((a0 * b0) - (a1 * b1)),
          safe_mod(a0 * b1 + a1 * b0 - a1 * b1)};
}
static inline tuple<long long, long long> diff(tuple<long long, long long> a,
                                               tuple<long long, long long> b) {
  return {safe_mod(get<0>(a) - get<0>(b)), safe_mod(get<1>(a) - get<1>(b))};
}
static inline tuple<long long, long long> add(tuple<long long, long long> a,
                                              tuple<long long, long long> b) {
  return {(get<0>(a) + get<0>(b)) % MOD, (get<1>(a) + get<1>(b)) % MOD};
}
static inline vector<tuple<long long, long long>> divide(
    vector<tuple<long long, long long>> p, tuple<long long, long long> c) {
  int n = p.size();
  vector<tuple<long long, long long>> r(n - 1);
  for (int i = n - 1; i >= 1; i--) {
    r[i - 1] = p[i];
    p[i - 1] = diff(p[i - 1], mult(p[i], c));
  }
  return r;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(14);
  int n, q;
  cin >> n >> q;
  vector<long long> coeffs(3 * n + 4, 1);
  vector<long long> inv(3 * n + 4, 1);
  for (int i = 2; i < 3 * n + 4; i++) {
    inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
  }
  for (long long i = 1; i < 3 * n + 4; i++) {
    coeffs[i] = (((coeffs[i - 1] * (3 * n + 4 - i)) % MOD) * inv[i]) % MOD;
    if (coeffs[i] < 0) cout << "OOOOOO " << i << " " << coeffs[i] << "\n";
  }
  vector<long long> e_poly_1(3 * n + 4), e_poly_e(3 * n + 4),
      e2_poly_1(3 * n + 4), e2_poly_e(3 * n + 4);
  for (int i = 0; i < 3 * n + 4; i++) {
    if (i % 3 == 0) {
      e_poly_1[i] = coeffs[i];
      e_poly_e[i] = 0;
      e2_poly_1[i] = coeffs[i];
      e2_poly_e[i] = 0;
    } else if (i % 3 == 1) {
      e_poly_1[i] = MOD - coeffs[i];
      e_poly_e[i] = MOD - coeffs[i];
      e2_poly_1[i] = 0;
      e2_poly_e[i] = coeffs[i];
    } else {
      e_poly_1[i] = 0;
      e_poly_e[i] = coeffs[i];
      e2_poly_1[i] = MOD - coeffs[i];
      e2_poly_e[i] = MOD - coeffs[i];
    }
  }
  vector<long long> e_div_1(3 * n + 3);
  vector<long long> e_div_e(3 * n + 3);
  for (int i = 3 * n + 3; i >= 1; i--) {
    long long a = e_poly_1[i], b = e_poly_e[i];
    e_div_1[i - 1] = a;
    e_div_e[i - 1] = b;
    e_poly_1[i - 1] = safe_mod(e_poly_1[i - 1] + a + b);
    e_poly_e[i - 1] = safe_mod(e_poly_e[i - 1] + 2 * b - a);
  }
  vector<long long> e2_div_1(3 * n + 3);
  vector<long long> e2_div_e(3 * n + 3);
  for (int i = 3 * n + 3; i >= 1; i--) {
    long long a = e2_poly_1[i], b = e2_poly_e[i];
    e2_div_1[i - 1] = a;
    e2_div_e[i - 1] = b;
    e2_poly_1[i - 1] = safe_mod(e2_poly_1[i - 1] + 2 * a - b);
    e2_poly_e[i - 1] = safe_mod(e2_poly_e[i - 1] + b + a);
  }
  long long inv_3 = inv[3];
  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    long long res = coeffs[k + 1];
    if (k % 3 == 0) {
      res = res + e_div_1[k] + e2_div_1[k];
    } else if (k % 3 == 1) {
      res = res - e_div_e[k] + e2_div_e[k] - e2_div_1[k];
      res = res % MOD;
      if (res < 0) res += MOD;
    } else {
      res = res + e_div_e[k] - e_div_1[k] - e2_div_e[k];
      res = res % MOD;
      if (res < 0) res += MOD;
    }
    cout << (res * inv_3) % MOD << "\n";
  }
}
