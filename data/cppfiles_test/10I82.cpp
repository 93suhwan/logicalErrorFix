#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5, mum = 1e9 + 7;
long long Pow(long long A, long long B) {
  long long num = 1;
  while (B) {
    if (B % 2) num = 1LL * num * A % mum;
    A = 1LL * A * A % mum;
    B >>= 1;
  }
  return num;
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, m, k, r, c, ax, ay, bx, by;
  cin >> n >> m >> k >> r >> c >> ax >> ay >> bx >> by;
  cout << (ax == bx && bx == by ? Pow(k, 1LL * n * m)
                                : Pow(k, 1LL * n * m - 1LL * r * c))
       << '\n';
  return 0;
}
