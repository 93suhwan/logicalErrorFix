#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    long long n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a.rbegin(), a.rend());
    long long baki = sum - k;
    if (baki <= 0)
      cout << 0 << endl;
    else {
      long long baad = 0, res = baki;
      for (int i = 0; i < n - 1; i++) {
        baad += (a[i] - a[n - 1]);
        if (baad >= baki) {
          res = min(res, (long long)(i + 1));
          break;
        }
        long long x = ((baki - baad) / (i + 2));
        if ((baki - baad) % (i + 2)) x++;
        res = min(res, x + i + 1);
      }
      cout << res << endl;
    }
  }
  return 0;
}
