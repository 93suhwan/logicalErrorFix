#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
long long int M = 998244353;
const long long int N = 2e5 + 7;
long long int mod(long long int m, long long int mod = M) {
  m %= mod;
  return (m + mod) % mod;
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = mod(x);
  while (y > 0) {
    if (y & 1) res = mod(res * x);
    y = y / 2;
    x = mod(x * x);
  }
  return mod(res);
}
long long int f[N], invf[N];
void fact() {
  f[0] = f[1] = 1;
  for (long long int i = 2; i < N; i++) f[i] = mod(f[i - 1] * i);
  invf[N - 1] = power(f[N - 1], M - 2);
  for (long long int i = N - 1; i > 0; i--) invf[i - 1] = mod(invf[i] * i);
}
long long int nCr(long long int n, long long int r) {
  if (r > n) return 0;
  long long int ans = f[n];
  ans = mod(ans * invf[n - r]);
  ans = mod(ans * invf[r]);
  return ans;
}
long long int nPr(long long int n, long long int r) {
  if (r > n) return 0;
  long long int ans = f[n];
  ans = mod(ans * invf[n - r]);
  return ans;
}
int main() {
  fastio();
  fact();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    map<long long int, long long int> m;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
    }
    sort(a, a + n);
    long long int flag = 1;
    long long int konsa = 0;
    long long int prev = -1;
    for (auto i : m) {
      if (prev == -1) {
        prev = i.first;
      } else {
        if (!(i.second > 1 || i.first == prev + 1)) {
          flag = 0;
        }
        if (i.second > 1)
          konsa = 0;
        else
          konsa = 1;
        prev = i.first;
      }
    }
    if (flag) {
      long long int ans = 0;
      if (konsa) {
        long long int x = m[a[n - 2]];
        for (long long int i = 0; i < n - 1; i++) {
          if (i < x) {
            ans = (ans + nPr(n - 1, n - 1)) % M;
          } else {
            ans = (ans + nPr(n - 1, n - 1)) % M;
            ans = (ans - (nPr(i, x) * nPr(n - (x + 1), n - (x + 1)))) % M;
          }
        }
      } else {
        ans = nPr(n, n);
      }
      cout << ans;
    } else {
      cout << 0;
    }
    cout << "\n";
    ;
  }
  return 0;
}
