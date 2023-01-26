#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    long long count = 0;
    long long dr = 1, dc = 1;
    if (rb == n) {
      dr = -1;
    }
    if (cb == m) {
      dc = -1;
    }
    if (rb == rd or cb == cd) {
      count = 0;
    } else {
      while ((rb != rd or cb != cd) and (rb > 0 and cb > 0)) {
        rb += dr;
        cb += dc;
        if (rb < n and cb < m) {
          count++;
        }
        if (rb == n) {
          count++;
          dr = -1;
        }
        if (cb == m) {
          count++;
          dc = -1;
        }
        if (cb == m and rb == n) {
          count--;
          dc = -1;
        }
        if (rb == rd or cb == cd) {
          break;
        }
      }
    }
    std::cout << count << std::endl;
  }
  return 0;
}
