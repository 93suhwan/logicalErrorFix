#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const long long N = 2e5 + 5;
long long n, q, a[N], sz = 150, l[N], r[N], R[N];
void up(long long x) {
  long long pre = x, sx = r[x];
  for (long long i = 1; i < sz; i++) pre = l[x];
  for (long long i = 1; i <= sz; i++) {
    R[pre] = sx;
    sx = r[sx];
    pre = r[pre];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> r[i];
    l[r[i]] = i;
  }
  for (long long i = 1; i <= n; i++) {
    long long sx = i;
    for (long long j = 1; j <= sz; j++) sx = r[sx];
    R[i] = sx;
  }
  while (q--) {
    long long op;
    cin >> op;
    if (op == 1) {
      long long x, y;
      cin >> x >> y;
      swap(r[x], r[y]);
      l[r[x]] = x;
      l[r[y]] = y;
      up(x);
      up(y);
    } else {
      long long x, k;
      cin >> x >> k;
      while (k >= sz) k -= sz, x = R[x];
      while (k) k--, x = r[x];
      cout << x << endl;
    }
  }
}
