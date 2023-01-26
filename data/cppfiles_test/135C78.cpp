#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long bexp(long long x, long long a) {
  long long ans = 1;
  while (a > 0) {
    if (a & 1) ans *= x;
    x *= x;
    a /= 2;
  }
  return ans;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    long long id = n - 2 * k - 1;
    long long sum = 0;
    long long l = id + 1, r = n - k;
    while (r < n) {
      sum += arr[l] / arr[r];
      l++;
      r++;
    }
    for (long long i = 0; i <= id; i++) {
      sum += arr[i];
    }
    cout << sum << endl;
  }
}
