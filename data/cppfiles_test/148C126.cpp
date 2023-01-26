#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (!y) return x;
  return gcd(y, x % y);
}
long long power(long long a, long long b) {
  if (a == 0) return 0;
  long long res = 1;
  while (b > 0) {
    if (b % 2) res = (res * a);
    a = (a * a);
    b = b / 2;
  }
  return res;
}
const int maxn = 5 * 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    long long n, m;
    cin >> n >> m;
    long long A = 0;
    for (long long i = 0; i < 2; i++) {
      long long k;
      cin >> k;
      long long x;
      cin >> x;
      for (long long j = 1; j < k; j++) {
        long long y;
        cin >> y;
        A = max(A, (y - x) * m);
      }
    }
    for (long long i = 0; i < 2; i++) {
      long long k;
      cin >> k;
      long long x;
      cin >> x;
      for (long long j = 1; j < k; j++) {
        long long y;
        cin >> y;
        A = max(A, (y - x) * n);
      }
    }
    cout << A << "\n";
  }
  return 0;
}
