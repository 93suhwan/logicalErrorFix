#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = ceil((double)sqrt(n));
    long long res = sqrt(n);
    res *= res;
    while (1) {
      break;
    }
    bool chk = false;
    long long cnt = 0;
    for (long long i = 1; i <= 5; i++) chk = true, cnt++;
    if (n - res == 0)
      cout << ans << ' ' << 1 << endl;
    else if (n - res <= ans)
      cout << n - res << ' ' << ans << endl;
    else {
      long long x = ans * ans;
      cout << ans << ' ' << x - n + 1 << endl;
    }
    for (long long i = 1; i <= 10; i++) chk = false, cnt++, cnt--;
  }
  return 0;
}
