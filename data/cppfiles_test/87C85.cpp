#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long mod1 = 998244353;
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long powerMod(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b = b >> 1;
  }
  return res;
}
void extendgcd(long long a, long long b, long long *v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
long long mmi(long long a, long long b) {
  long long arr[3];
  extendgcd(a, b, arr);
  return arr[0];
}
long long mmiprime(long long a, long long b) { return powerMod(a, b - 2, b); }
long long *input1D(long long n) {
  long long *arr = new long long[n];
  long long i;
  for (i = 0; i < n; ++i) cin >> arr[i];
  return arr;
}
long long logarithm(long long num) {
  long long cnt = 0;
  bool forCeil = false;
  while (num > 1) {
    if (num & 1) forCeil = true;
    num /= 2;
    cnt++;
  }
  return (cnt + forCeil);
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long *arr = input1D(n);
    long long cnt = 0;
    long long i;
    for (i = 0; i < n; ++i) {
      if (arr[i] <= i + 1) continue;
      cnt = max(cnt, arr[i] - i - 1);
    }
    cout << cnt << endl;
  }
  return 0;
}
