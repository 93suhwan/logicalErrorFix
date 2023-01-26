#include <bits/stdc++.h>
using namespace std;
int primes[100005];
void primesieve(int *p) {
  for (int i = 3; i <= 100005; i += 2) p[i] = 1;
  for (long long i = 3; i <= 100005; i += 2) {
    if (p[i] == 1) {
      for (long long j = i * i; j <= 100005; j += i) p[j] = 0;
    }
  }
  p[2] = 1;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInv(long long n, long long p) { return power(n, p - 2, p); }
void solve() {
  int n;
  cin >> n;
  int arr[n], aux[n];
  int odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    aux[i] = arr[i];
    if (arr[i] % 2 == 0)
      even++;
    else
      odd++;
  }
  if (abs(even - odd) > 1) {
    cout << -1 << endl;
    return;
  }
  int k1 = 0, k2 = 0;
  int cur = 1;
  int j = 0;
  for (int i = 0; i < n; i++) {
    j = i;
    while (j < n and arr[j] % 2 != cur) {
      j++;
    }
    k1 += (j - i);
    swap(arr[i], arr[j]);
    cur = 1 - cur;
  }
  cur = 0;
  j = 0;
  for (int i = 0; i < n; i++) {
    j = i;
    while (j < n and aux[j] % 2 != cur) {
      j++;
    }
    k2 += (j - i);
    swap(aux[i], aux[j]);
    cur = 1 - cur;
  }
  cout << min(k1, k2) << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  clock_t begin = clock();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
