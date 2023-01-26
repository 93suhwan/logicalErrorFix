#include <bits/stdc++.h>
using namespace std;
vector<int> cand;
vector<int> prime(1000005);
vector<long long> primes;
void SieveOfEratosthenes(int n) {
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == 0) {
      for (int i = p * p; i <= n; i += p)
        if (prime[i] == 0) prime[i] = p;
    }
  }
}
long long power(long long x, long long y) {
  long long res = 1ll;
  x = x % 1000000007;
  if (x == 0ll) return 0;
  while (y > 0ll) {
    if (y & 1ll) res = (res * x) % 1000000007;
    y = y >> 1ll;
    x = (x * x) % 1000000007;
  }
  return res;
}
long long add(long long x, long long y) {
  x += y;
  while (x >= 1000000007) x -= 1000000007;
  while (x < 0) x += 1000000007;
  return x;
}
long long mul(long long x, long long y) { return (x * 1ll * y) % 1000000007; }
long long binpow(long long x, long long y) {
  long long z = 1ll;
  while (y) {
    if (y & 1) z = mul(z, x);
    x = mul(x, x);
    y >>= 1ll;
  }
  return z;
}
long long inv(long long x) { return binpow(x, 1000000007 - 2); }
long long divide(long long x, long long y) { return mul(x, inv(y)); }
long long fact[2000006];
void precalc() {
  fact[0] = 1;
  for (long long i = 1; i < 2000006; i++)
    fact[i] = (fact[i - 1] * i) % 1000000007;
}
long long C(long long n, long long k) {
  if (n < k) return 0;
  if (k < 0) return 0;
  if (n == 0) return 1;
  return divide(fact[n], mul(fact[k], fact[n - k]));
}
long long sub(long long A, long long B) {
  return (A - B + 1000000007) % 1000000007;
}
long long build(long long tl, long long tr, long long v, long long segtree[],
                long long A[]) {
  if (tl == tr) {
    segtree[v] = A[tl - 1];
    return segtree[v];
  } else {
    long long tm = (tl + tr) / 2;
    auto x1 = build(tl, tm, v * 2, segtree, A);
    auto x2 = build(tm + 1, tr, 2 * v + 1, segtree, A);
    return segtree[v] = (segtree[2 * v] + segtree[2 * v + 1]);
  }
}
long long maxival(long long v, long long tl, long long tr, long long l,
                  long long r, long long segtree[]) {
  if (l > r) return 0;
  if (l == tl && r == tr) return segtree[v];
  long long tm = (tl + tr) / 2;
  auto x1 = maxival(2 * v, tl, tm, l, min(r, tm), segtree);
  auto x2 = maxival(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, segtree);
  return (x1 + x2);
}
long long updateval(long long v, long long tl, long long tr, long long pos,
                    long long newval, long long segtree[]) {
  if (tl == tr) {
    segtree[v] = newval;
    return tl;
  } else {
    long long tm = (tl + tr) / 2;
    long long x;
    if (pos >= tl && pos <= tm)
      x = updateval(2 * v, tl, tm, pos, newval, segtree);
    else {
      x = updateval(2 * v + 1, tm + 1, tr, pos, newval, segtree);
    }
    segtree[v] = (segtree[2 * v] + segtree[2 * v + 1]);
    return x;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(5);
  int t = 1;
  cin >> t;
  int tx = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long A[n];
    long long i;
    for (i = 0; i < n; i++) cin >> A[i];
    long long f = -1;
    if (A[n - 1] == 0) {
      for (i = 1; i <= n + 1; i++) cout << i << " ";
      cout << "\n";
      continue;
    }
    if (A[0] == 1) {
      cout << n + 1 << " ";
      for (i = 1; i <= n; i++) cout << i << " ";
      cout << "\n";
      continue;
    }
    for (i = 1; i < n; i++) {
      if (A[i - 1] == 0 && A[i] == 1) f = i - 1;
    }
    if (f == -1) {
      cout << -1 << "\n";
      continue;
    }
    for (i = 0; i <= f; i++) cout << i + 1 << " ";
    cout << n + 1 << " ";
    for (i = f + 1; i < n; i++) cout << i + 1 << " ";
    cout << "\n";
  }
  return 0;
}
