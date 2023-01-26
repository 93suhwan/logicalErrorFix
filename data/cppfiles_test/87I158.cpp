#include <bits/stdc++.h>
using namespace std;
int64_t N = 1e9 + 7;
int64_t M = 9223372036854775807;
int GCD(int A, int B) {
  if (B == 0)
    return A;
  else
    return GCD(B, A % B);
}
bool isPrime(long long n) {
  if (n <= 1) {
    return false;
  }
  if (n <= 3) {
    return true;
  }
  if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long TTC;
  cin >> TTC;
  while (TTC--) {
    long long n;
    cin >> n;
    long long a[n], b[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    long long x;
    for (long long i = 0; i < n; i++) {
      if (a[i] == b[n - 1]) {
        x = i;
        break;
      }
    }
    cout << b[n - 1] - x - 1 << endl;
  }
  return 0;
}
