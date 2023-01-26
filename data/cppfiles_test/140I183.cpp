#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x);
    x = (x * x), y >>= 1;
  }
  return res;
}
long long power(long long x, long long y, long long m) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % m;
    x = (x * x) % m, y >>= 1;
  }
  return res;
}
void inp_out() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void ans_nikalo() {}
int32_t main() {
  inp_out();
  long long t;
  cin >> t;
  while (t--) ans_nikalo();
  return 0;
}
