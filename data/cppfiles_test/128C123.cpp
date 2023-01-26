#include <bits/stdc++.h>
using namespace std;
long long M = 1000000007;
long long gcd(long long a, long long b);
long long fact(long long n);
long long nck(long long n, long long k);
long long binS(vector<long long> arr, long long l, long long r, long long x);
long long mult(long long a, long long b);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long kl;
  cin >> kl;
  while (kl--) {
    long long n;
    cin >> n;
    long long a, b, c;
    if (n % 2 == 0) {
      c = 1;
      n--;
      a = n / 2;
      b = n / 2 + 1;
    } else {
      if (((n - 3) / 2) % 2 != 0) {
        c = 1;
        b = (n - 3) / 2;
        a = b + 2;
      } else {
        c = 1;
        b = (n - 3) / 2 - 1;
        a = b + 4;
      }
    }
    if (gcd(a, b) == c) {
      cout << a << " " << b << " " << c << endl;
    }
  }
  return 0;
}
long long binS(vector<long long> arr, long long l, long long r, long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binS(arr, l, mid - 1, x);
    return binS(arr, mid + 1, r, x);
  }
  return -1;
}
long long nck(long long n, long long k) {
  long long ans = 1;
  for (long long i = n; i > max(k, n - k); i--) {
    ans *= i;
  }
  for (long long i = 2; i <= min(k, n - k); i++) ans /= i;
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long fact(long long n) {
  long long ans = 1;
  for (long long i = 2; i <= n; i++) ans *= i;
  return ans;
}
long long mult(long long a, long long b) {
  long long ans = 1;
  while (b--) ans *= a;
  return ans;
}
