#include <bits/stdc++.h>
using namespace std;
void readv(vector<long long> &a, long long n) {
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back(x);
  }
}
void outv(vector<long long> &a, long long n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << "\n";
}
long long po(long long x, long long y) {
  long long res = 1;
  for (; y; y >>= 1) {
    if (y & 1) res = res * x % 1000000007;
    x = x * x % 1000000007;
  }
  return res;
}
long long gcd(long long a, long long b) { return (b ? gcd(b, a % b) : a); }
long long fac[200010], inv[200010], ivf[200010];
void initfac() {
  fac[0] = ivf[0] = inv[1] = 1;
  for (long long i = 1; i < 200010; i++) fac[i] = fac[i - 1] * i % 1000000007;
  for (long long i = 1; i < 200010; i++) {
    if (i > 1)
      inv[i] =
          (1000000007 - 1000000007 / i * inv[1000000007 % i] % 1000000007) %
          1000000007;
    ivf[i] = po(fac[i], 1000000007 - 2);
  }
}
long long P(long long n, long long k) {
  if (n < 0 || n < k) return 0;
  return fac[n] * ivf[n - k] % 1000000007;
}
long long C(long long n, long long k) {
  if (k < 0 || n < k) return 0;
  return fac[n] * ivf[n - k] % 1000000007 * ivf[k] % 1000000007;
}
long long H(long long n, long long k) { return C(n + k - 1, k); }
long long n, k;
long long ans[1010][1010];
void solve(long long d, long long l, long long r) {
  long long m = r - l + 1;
  if (m <= 1) return;
  vector<long long> cnt;
  for (int i = 0; i < k; i++) cnt.push_back(0);
  vector<long long> id;
  for (int i = 0; i < m; i++) id.push_back(0);
  long long kk = 1;
  while (m > kk) {
    kk *= k;
  }
  kk /= k;
  long long rem = m;
  for (int i = 0; i < k; i++) {
    cnt[i] = min(kk, rem);
    rem -= cnt[i];
  }
  long long j = 0;
  long long L = 0;
  for (int i = 0; i < m; i++) {
    id[i] = j;
    cnt[j]--;
    if (cnt[j] == 0) {
      solve(d + 1, L, i);
      L = i + 1;
      j++;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      if (id[i] != id[j]) ans[i + l][j + l] = d;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n >> k;
  solve(1, 0, n - 1);
  long long ma = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) ma = max(ma, ans[i][j]);
  cout << ma << endl;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (i == 0 && j == 1)
        ;
      else
        cout << " ";
      cout << ans[i][j];
    }
  cout << endl;
}
