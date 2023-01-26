#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const double eps = 1e-6;
const int mod = 1e9 + 7;
int a[N];
int digits(int n) {
  bool f[10] = {0};
  while (n) {
    f[n % 10] = 1;
    n /= 10;
  }
  int cnt = 0;
  for (int i = 0; i < 10; i++) cnt += f[i];
  return cnt;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    while (digits(n) > k) {
      int r = 1;
      int c = n;
      while (digits(c) > k) {
        c /= 10;
        r *= 10;
      }
      r /= 10;
      n = ((n / r) + 1) * r;
    }
    cout << n << endl;
  }
  return 0;
}
