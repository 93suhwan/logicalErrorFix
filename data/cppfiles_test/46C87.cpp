#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18;
const int N = 1e6;
long long n, m, x, y;
long long a[N], b[N], c[N], d[N], kq;
pair<long long, long long> t[N];
long long check(long long m) { return max((long long)0, m); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++)
    if (i % 2 == 1) {
      m = a[i];
      for (int j = i + 1; j <= n; j++) {
        if (j % 2 == 0)
          m = m - a[j];
        else
          m = m + a[j];
        if (j % 2 == 0)
          if (a[i] > m) {
            kq += a[i] - check(m);
            a[i] = m + 1;
          }
        if (m < 0) break;
      }
    }
  cout << kq;
  return 0;
}
