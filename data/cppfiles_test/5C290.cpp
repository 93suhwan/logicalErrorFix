#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10, M = 1e5 + 10, mod = 100000000;
const long long INF = 0x3f3f3f3f;
const double eps = 1e-8;
const double PI = 3.1415926535;
using namespace std;
char a[N], b[N];
long long n;
signed main(void) {
  std::ios::sync_with_stdio(false);
  ;
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> b + 1 >> a + 1;
    long long cnt = 0;
    for (long long i = 1; i <= n; i++) {
      if (a[i] == '0') continue;
      if (b[i - 1] == '1') {
        cnt++;
        b[i - 1] = '0';
      } else if (b[i] == '0')
        cnt++;
      else if (i < n && b[i + 1] == '1') {
        cnt++;
        b[i + 1] = '0';
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
