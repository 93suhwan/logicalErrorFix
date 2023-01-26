#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void extendedEuclid(long long a, long long b, long long *x, long long *y) {
  if (b == 0) {
    *x = 1;
    *y = 0;
    return;
  }
  extendedEuclid(b, a % b, x, y);
  long long cx = *y;
  *y = *x - (a / b) * (*y);
  *x = cx;
}
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
vector<bool> sieve(long long n) {
  vector<bool> arr(n + 1, true);
  for (long long i = 2; i * i <= n; i++) {
    if (arr[i] == true) {
      for (long long j = i * i; j <= n; j += i) {
        arr[j] = false;
      }
    }
  }
  return arr;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long modInverse(long long a, long long m) {
  long long x, y;
  extendedEuclid(a, m, &x, &y);
  return (x + m) % m;
}
void solve() {
  int n;
  cin >> n;
  int ar[n];
  for (int(i) = 0; (i) < n; i++) cin >> ar[i];
  long long sum = accumulate(ar, ar + n, 0LL);
  int k = sum / n;
  int sumOfTwo = 2 * sum / n;
  sort(ar, ar + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int ind = lower_bound(ar + i + 1, ar + n, sumOfTwo - ar[i]) - ar;
    if (ind != n) {
      int ind2 = upper_bound(ar + i + 1, ar + n, sumOfTwo - ar[i]) - ar;
      if (ar[ind2 - 1] == sumOfTwo - ar[i]) {
        ans += ind2 - ind;
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
