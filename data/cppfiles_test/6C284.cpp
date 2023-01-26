#include <bits/stdc++.h>
const long long binf = 1000000000000000000;
const long long inf = 1e9 + 5;
using namespace std;
unsigned long long binpow(unsigned long long x, unsigned long long y) {
  if (y == 0) {
    return 1;
  }
  unsigned long long temp = binpow(x, y / 2);
  temp = temp * temp;
  if (y % 2 != 0) {
    temp = x * temp;
  }
  return temp;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  const long long N = 200050;
  long long a[N] = {0};
  long long int ans = 0;
  for (long long i = 0; i < m; i++) {
    long long int x, y;
    cin >> x >> y;
    long long int mi = min(x, y);
    long long int ma = max(x, y);
    a[mi] = a[mi] + 1;
    if (a[mi] == 1) {
      ans++;
    }
  }
  long long int q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    long long int c;
    cin >> c;
    if (c == 1) {
      long long int x, y;
      cin >> x >> y;
      long long int mi = min(x, y);
      a[mi] = a[mi] + 1;
      if (a[mi] == 1) {
        ans++;
      }
    } else if (c == 2) {
      long long int x, y;
      cin >> x >> y;
      long long int mi = min(x, y);
      a[mi] = a[mi] - 1;
      if (a[mi] == 0) {
        ans--;
      }
    } else if (c == 3) {
      cout << n - ans << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int tests = 1;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}
