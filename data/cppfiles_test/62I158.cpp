#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
long long mm(long long x, long long y) {
  x %= M, y %= M;
  return (x * y) % M;
}
long long po(long long x, long long y) {
  if (!y) return 1;
  long long a = po(x, y / 2) % M;
  if (y % 2) return mm(a, mm(a, x));
  return mm(a, a);
}
vector<long long> g[10010];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, x = -1;
    cin >> n;
    long long a[n + 1];
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = n; i >= 1; i--) {
      if (a[i] == 0) {
        x = i;
        break;
      }
    }
    if (x == -1)
      cout << "-1\n";
    else {
      for (long long i = 1; i <= x; i++) cout << i << " ";
      cout << n + 1 << " ";
      for (long long i = x + 1; i <= n; i++) cout << i << " ";
      cout << endl;
    }
  }
  return 0;
}
