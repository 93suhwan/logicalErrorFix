#include <bits/stdc++.h>
using namespace std;
long long fac[3000010], inv[3000010];
long long P(long long a, long long n) {
  if (n == 0) return 1;
  if (n == 1) return a;
  long long x = P(a, n / 2);
  if (n % 2)
    return (((x * x) % 1000000007) * a) % 1000000007;
  else
    return (x * x) % 1000000007;
}
long long C(long long n, long long r) {
  return (((fac[n] * inv[r]) % 1000000007) * inv[n - r]) % 1000000007;
}
long long n, m;
long long a[3000010], b[3000010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fac[0] = 1;
  for (long long i = 1; i <= 3000000; i++) {
    fac[i] = fac[i - 1] * i;
    fac[i] %= 1000000007;
  }
  inv[3000000] = P(fac[3000000], 1000000007 - 2);
  for (long long i = 2999999; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1);
    inv[i] %= 1000000007;
  }
  cin >> n >> m;
  for (int i = 0; i <= 3 * n + 3; i++) a[i] = C(3 * n + 3, i);
  for (int i = 0; i <= 3 * n + 3; i++) {
    b[i] = a[i];
    a[i] -= b[i];
    a[i + 1] -= 3 * b[i];
    a[i + 2] -= 3 * b[i];
    while (a[i] < 0) a[i] += 1000000007;
    while (a[i + 1] < 0) a[i + 1] += 1000000007;
    while (a[i + 2] < 0) a[i + 2] += 1000000007;
  }
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    cout << b[3 * n - t] << "\n";
  }
}
