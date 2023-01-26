#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long u, unsigned long long v) {
  if (u == v) return u;
  if (u == 0) return v;
  if (v == 0) return u;
  if (~u & 1)
    if (v & 1)
      return gcd(u >> 1, v);
    else
      return gcd(u >> 1, v >> 1) << 1;
  if (~v & 1) return gcd(u, v >> 1);
  if (u > v) return gcd((u - v) >> 1, v);
  return gcd((v - u) >> 1, u);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long go = arr[0];
    long long ge = arr[1];
    for (long long i = 0; i < n; i += 2) {
      go = gcd(go, arr[i]);
    }
    for (long long i = 1; i < n; i += 2) {
      ge = gcd(ge, arr[i]);
    }
    long long f1 = 0;
    for (long long i = 0; i < n; i += 2) {
      if (arr[i] % ge == 0) {
        f1++;
      }
    }
    long long f2 = 0;
    for (long long i = 1; i < n; i += 2) {
      if (arr[i] % go == 0) {
        f2++;
      }
    }
    if (f1 == 0) {
      cout << ge << '\n';
    } else if (f2 == 0) {
      cout << go << '\n';
    } else {
      cout << 0 << '\n';
    }
  }
  return 0;
}
