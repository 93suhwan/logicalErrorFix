#include <bits/stdc++.h>
using namespace std;
long long check(long long n, long long m, long long x, long long y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}
void pr() { cout << '\n'; }
template <class A, class... B>
void pr(const A &a, const B &...b) {
  cout << a << (sizeof...(b) ? " " : "");
  pr(b...);
}
template <class A>
void PR(A a, long long n) {
  for (long long i = (long long)(0); i < (long long)(n); i++)
    cout << (i ? " " : "") << a[i];
  cout << '\n';
}
const long long MAX = 1e9 + 7, MAXL = 1LL << 61,
                dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1},
                dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
void Main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n, m, x1, y1, x2, y2, h, w;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> h >> w;
    long long ans = MAXL;
    {
      long long d = max(0LL, h - x1);
      if (x2 + d <= n) ans = min(ans, d);
    }
    {
      long long d = max(0LL, h - (n - x2));
      if (x1 - d >= 0) ans = min(ans, d);
    }
    {
      long long d = max(0LL, w - y1);
      if (y2 + d <= m) ans = min(ans, d);
    }
    {
      long long d = max(0LL, w - (m - y2));
      if (y1 - d >= 0) ans = min(ans, d);
    }
    if (ans == MAXL) ans = -1;
    pr(ans);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Main();
  return 0;
}
