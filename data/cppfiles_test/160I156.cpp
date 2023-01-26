#include <bits/stdc++.h>
using namespace std;
int robot() {
  int n, m, r_b, c_b, r_d, c_d;
  cin >> m >> n >> r_b >> c_b >> r_d >> c_d;
  int count = 0;
  int d_r = 1, d_c = 1;
  while (true) {
    if (c_b + d_c > m || c_b + d_c < 1) d_c *= -1;
    if (r_b == r_d || c_b == c_d) break;
    if (r_b + d_r > n || r_b + d_r < 1) d_r *= -1;
    c_b += d_c;
    count++;
    r_b += d_r;
  }
  return count;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << robot() << endl;
  }
  return 0;
}
