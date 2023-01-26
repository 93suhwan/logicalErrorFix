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
  long long d00, d01, d11, d10;
  long long k = +1e+9;
  cout << "? " << 1 << " " << 1 << "\n";
  cout.flush();
  cin >> d00;
  cout << "? " << k << " " << 1 << "\n";
  cout.flush();
  cin >> d10;
  cout << "? " << k << " " << k << "\n";
  cout.flush();
  cin >> d11;
  cout << "? " << 1 << " " << k << "\n";
  cout.flush();
  cin >> d01;
  long long maxx = 1 + d00;
  long long minx = k - d10;
  long long optx = (maxx + minx) / 2;
  long long y0;
  cout << "? " << optx << " " << 1 << "\n";
  cout.flush();
  cin >> y0;
  y0 += 1;
  long long x0 = d00 - y0 + 2;
  long long dy = d01 - x0;
  long long dx = d10 - y0;
  long long y1 = k - dy - 1;
  long long x1 = k - dx - 1;
  cout << "! " << x0 << " " << y0 << " " << x1 << " " << y1 << "\n";
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
