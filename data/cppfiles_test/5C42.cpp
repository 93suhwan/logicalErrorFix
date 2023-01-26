#include <bits/stdc++.h>
using namespace std;
bool prime[1000005];
long long int fac[1000005];
long long int phi(long long int n) {
  long long int res = n;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      res /= i;
      res *= (i - 1);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) {
    res /= n;
    res *= (n - 1);
  }
  return res;
}
long long int power(long long int a, long long int n, long long int p) {
  long long int res = 1;
  a = a % p;
  while (n) {
    if (n % 2) {
      res = (res * a) % p;
      n--;
    } else {
      a = (a * a) % p;
      n /= 2;
    }
  }
  return res % p;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int ncr(long long int n, long long int k, long long int p) {
  if (k > n) return 0;
  if (k == 0 || k == n) return 1;
  if (k == 1 || k == n - 1) return n;
  long long int res = fac[n];
  res = (res * power(fac[k], p - 2, p)) % p;
  res = (res * power(fac[n - k], p - 2, p)) % p;
  return res % p;
}
long long int binarySearch(long long int arr[], long long int l,
                           long long int r, long long int x) {
  if (r >= l) {
    long long int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
long long int search(long long int a[], long long int l, long long int h,
                     long long int x) {
  while (l < h) {
    long long int m = (l + h + 1) / 2;
    if (a[m] > x)
      h = m - 1;
    else
      l = m;
  }
  return l;
}
int main() {
  for (long long int i = 0; i < 1000005; i++) prime[i] = true;
  prime[0] = prime[1] = false;
  for (long long int p = 2; p * p < 1000005; p++) {
    if (prime[p]) {
      for (long long int i = p * p; i < 1000005; i += p) prime[i] = false;
    }
  }
  fac[0] = fac[1] = 1;
  for (long long int i = 2; i < 1000005; i++)
    fac[i] = (fac[i - 1] * i) % 1000000007;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long int cnt = 0;
    for (long long int i = 0; i < n; i++) {
      bool vis = false;
      if (b[i] == '1') {
        if (a[i] == '0') {
          cnt++;
          a[i] = '2';
          vis = true;
        }
        if (i - 1 >= 0 && !vis) {
          if (a[i - 1] == '1') {
            cnt++;
            a[i - 1] = '2';
            vis = true;
          }
        }
        if (i + 1 < n && !vis) {
          if (a[i + 1] == '1') {
            cnt++;
            a[i + 1] = '2';
            vis = true;
          }
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
