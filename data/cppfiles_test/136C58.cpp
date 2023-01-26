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
vector<long long> sv, pp;
long long fact[200001];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  pp.assign(1000001, 0);
  for (long long i = 2; i < 1000; i++) {
    if (!pp[i]) {
      for (long long j = i * i; j <= 1000000; j += i) {
        if (!pp[j]) pp[j] = 1;
      }
    }
  }
  fact[0] = 1;
  for (long long i = 1; i <= 200000; i++)
    fact[i] = i * fact[i - 1], fact[i] %= z;
  for (long long i = 2; i <= 1000000; i++)
    if (!pp[i]) sv.push_back(i);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ar[n], p = 0;
    for (long long i = 0; i < n; i++) {
      cin >> ar[i];
      p += ar[i];
    }
    long long k = (n * (n + 1)) / 2;
    if (p % k)
      cout << "NO\n";
    else {
      p /= k;
      long long pos = 1;
      vector<long long> ans(n, 0);
      for (long long i = 0; i < n - 1; i++) {
        long long p1 = -ar[i + 1] + ar[i];
        p1 += p;
        if (p1 % n) {
          pos = 0;
          break;
        } else {
          p1 /= n;
          ans[i + 1] = p1;
        }
      }
      long long p1 = ar[n - 1] - ar[0];
      p1 += p;
      if (p1 % n) {
        pos = 0;
      } else {
        p1 /= n;
        ans[0] = p1;
      }
      for (long long i = 0; i < n; i++) {
        if (ans[i] <= 0 || ans[i] > 1e9) {
          pos = 0;
          break;
        }
      }
      if (pos) {
        cout << "YES\n";
        for (long long i = 0; i < n; i++) cout << ans[i] << " ";
        cout << "\n";
      } else
        cout << "NO\n";
    }
  }
}
