#include <bits/stdc++.h>
using namespace std;
unsigned long long inv(long long n) {
  unsigned long long res = 1;
  long long m = 1000000007 - 2;
  n = n % m;
  while (m > 0) {
    if (m & 1) res = (res * n) % 1000000007;
    m = m >> 1;
    n = (n * n) % 1000000007;
  }
  return res;
}
int solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (!(n & 1) && !(m & 1)) {
    if (k & 1)
      return 0;
    else
      return 1;
  } else if ((n & 1) && !(m & 1)) {
    if (k < m / 2) {
      return 0;
    } else {
      k -= m / 2;
      return k & 1 ? 0 : 1;
    }
  } else {
    if (k <= n * m / 2 - n / 2 && !(k & 1))
      return 1;
    else
      return 0;
  }
  return -1;
}
int main() {
  int t;
  cin >> t;
  int yes, no;
  no = yes = 0;
  while (t--) {
    if (solve())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
