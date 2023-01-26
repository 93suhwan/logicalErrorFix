#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    bool flag = 1;
    if (n & 1) {
      int qaq = m / 2;
      k -= qaq;
    } else if (m & 1) {
      int qaq = n / 2;
      k = n * m / 2 - k;
      k -= qaq;
    }
    if (k < 0 or k % 2 == 1) flag = 0;
    puts(flag ? "YES" : "NO");
  }
  return 0;
}
