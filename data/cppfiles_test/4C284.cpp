#include <bits/stdc++.h>
using namespace std;
long long BE(int a, int b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a);
    }
    a = a * a;
    b = b >> 1;
  }
  return res;
}
long long get(long long n) {
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) return i;
  return n;
}
void pro() {
  bool ok = 0, gf = 1, flag = 0;
  long long n, h = 0, p = 0, k = 0, x = 0, m;
  vector<long long> v;
  cin >> n;
  cout << 2 << " " << n - 1 << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) pro();
}
