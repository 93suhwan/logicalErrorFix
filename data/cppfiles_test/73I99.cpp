#include <bits/stdc++.h>
const long long inf = 1e18;
using namespace std;
int dx[] = {+0, +0, -1, +1};
int dy[] = {+1, -1, +0, +0};
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
void f() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  f();
  int test = 1;
  cin >> test;
  while (test--) {
    long long n, ans = 0;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    while (1) {
      bool ok = false, ok1 = false;
      for (long long i = 0; i < n; i += 2) {
        if (a[i] > a[i + 1] && i + 1 < n) {
          ok = true;
          long long c = a[i];
          a[i] = a[i + 1];
          a[i + 1] = c;
        }
      }
      for (long long i = 1; i < n; i += 2) {
        if (a[i] > a[i + 1] && i + 1 < n) {
          ok1 = true;
          long long c = a[i];
          a[i] = a[i + 1];
          a[i + 1] = c;
        }
      }
      if (ok) ans++;
      if (ok1) ans++;
      if (!ok && !ok1) {
        for (long long i = 0; i < n - 1; i++) {
          if (a[i] > a[i + 1]) {
            ok = true;
            break;
          }
        }
      }
      if (!ok) break;
    }
    cout << ans << '\n';
  }
}
