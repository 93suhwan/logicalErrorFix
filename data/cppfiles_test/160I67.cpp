#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
void fil() {}
long long int ipow(long long int base, long long int k, long long int M) {
  base %= M;
  k = k % (M - 1);
  long long int total = 1;
  while (k) {
    if (k & 1) {
      total = (total * base) % M;
    }
    base = (base * base) % M;
    k >>= 1;
  }
  return total;
}
void solve();
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  fil();
  long long int t = 1;
  cin >> t;
  for (int i = 1; i < t + 1; i++) {
    solve();
  }
}
void solve() {
  int n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  int dr = 1, dc = 1;
  int cnt = 0;
  while (1) {
    if (rb == rd || cb == cd) {
      cout << cnt << "\n";
      return;
    }
    if (rb + dr <= n && rb + dr >= 1) {
      if (cb + dc <= m && cb + dc >= 1) {
        rb += dr;
        cb += dc;
        cnt++;
      } else {
        dc *= -1;
        rb += dr;
        cb += dc;
        cnt++;
      }
    } else {
      dr *= -1;
      rb += dr;
      cb += dc;
      cnt++;
    }
  }
}
