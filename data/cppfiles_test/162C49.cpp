#include <bits/stdc++.h>
using namespace std;
long long z = 998244353;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % z, b--;
    a = (a * a) % z;
    b = b >> 1;
  }
  return res;
}
vector<long long> sv, pp, fact;
void seive(long long n) {
  pp.assign(n + 1, 0);
  for (long long i = 2; i <= sqrt(n); i++) {
    if (!pp[i]) {
      for (long long j = i * i; j <= n; j += i) {
        if (!pp[j]) pp[j] = 1;
      }
    }
  }
  for (long long i = 2; i <= n; i++)
    if (!pp[i]) sv.push_back(i);
}
void factorial(long long n) {
  fact.assign(n + 1, 0);
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) fact[i] = i * fact[i - 1], fact[i] %= z;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long h[n];
    for (long long i = 0; i < n; i++) cin >> h[i];
    long long l = 0, r = 1e9, ans = 0;
    vector<long long> v;
    while (l <= r) {
      long long mid = l + (r - l) / 2;
      v.assign(n, 0);
      long long pos = 1;
      for (long long i = n - 1; i >= 0; i--) {
        long long j = mid - v[i];
        if (j <= 0) {
          if (i - 2 >= 0) {
            long long k = h[i] / 3;
            v[i - 1] += k;
            v[i - 2] += 2 * k;
          }
        } else {
          if (h[i] - j >= 0) {
            if (i - 2 >= 0) {
              long long k = (h[i] - j) / 3;
              v[i - 1] += k;
              v[i - 2] += 2 * k;
            }
          } else {
            pos = 0;
            break;
          }
        }
      }
      if (pos) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    cout << ans << "\n";
  }
}
