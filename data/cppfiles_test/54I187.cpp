#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 2000 + 5;
const int OO = 1e9;
const int mod = 1e9 + 7;
int n, k;
long long fact[N], inv[N], cur, nxt;
long long mul(long long a, long long b) { return (a * b) % mod; }
long long add(long long a, long long b) { return (a + b) % mod; }
long long sub(long long a, long long b) { return (a - b + mod) % mod; }
long long nCr(int n, int r) {
  return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}
void calcCurAndNxt() {
  cur = nxt = 0;
  for (int i = 0; i <= n; ++i) {
    bool isOneXOR = (i & 1);
    bool isOneAND = (i == n);
    if (isOneAND == isOneXOR) {
      nxt = add(nxt, nCr(n, i));
    } else if (isOneXOR) {
      cur = add(cur, nCr(n, i));
    }
  }
}
long long pw(long long a, long long b) {
  if (!b) {
    return 1;
  }
  auto ret = pw(a, b / 2);
  ret = mul(ret, ret);
  if (b & 1) {
    ret = mul(ret, a);
  }
  return ret;
}
void calcFacAndInv() {
  fact[0] = inv[0] = 1;
  for (long long i = 1; i < N; i++) {
    fact[i] = mul(i, fact[i - 1]);
    inv[i] = pw(fact[i], mod - 2);
  }
}
long long solve(int bit) {
  if (!bit) {
    return 0;
  }
  return add(cur, mul(nxt, solve(bit - 1)));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  calcFacAndInv();
  while (tt--) {
    cin >> n >> k;
    calcCurAndNxt();
    cout << sub(pw(2, 1LL * k * n), solve(k)) << '\n';
  }
  return 0;
}
