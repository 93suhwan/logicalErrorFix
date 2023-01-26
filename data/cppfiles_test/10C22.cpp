#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long expmod(long long a, long long b, int m) {
  int res = 1;
  a = a % m;
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % m;
    }
    b = b >> 1;
    a = (a * a) % m;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k, r, c;
  long long ax, ay, bx, by;
  cin >> n >> m >> k >> r >> c >> ax >> ay >> bx >> by;
  long long components = (ax == bx && ay == by) ? n * m : n * m - r * c;
  cout << expmod(k, components, MOD) << endl;
}
