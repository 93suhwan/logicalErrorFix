#include <bits/stdc++.h>
using namespace std;
const long long N = 1005;
long long aa[N][N];
long long n, m;
long long compute() {
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      long long r = m - j;
      long long d = n - i;
      if (r == d) {
        ans += 4 * r;
      } else if (r > d) {
        ans += 2 * d + 1;
        ans += 2 * d;
      } else {
        ans += 2 * r + 1;
        ans += 2 * r;
      }
    }
  }
  ans += n * m;
  return ans;
}
void solve(long long nn) {
  long long d1, d2, d3, d4;
  long long k = +1e+9;
  cout << "? " << 1 << " " << (k) << "\n";
  cout.flush();
  cin >> d1;
  cout << "? " << k << " " << k << "\n";
  cout.flush();
  cin >> d2;
  long long ym = (d2 - d1) + k - 1;
  ym /= 2;
  ym++;
  cout << "? " << k << " " << ym << "\n";
  cout.flush();
  cin >> d3;
  cout << "? " << 1 << " " << ym << "\n";
  cout.flush();
  cin >> d4;
  long long x, y, p, q;
  x = 1 + d4;
  p = k - d3;
  y = 1 + abs(d1 - d3);
  q = k - abs(d3 - d2);
  cout << "! " << x << " " << y << " " << p << " " << q;
  return;
}
int main() {
  std::cout << std::fixed;
  std::cout << std::setprecision(15);
  ;
  long long t;
  t = 1;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
