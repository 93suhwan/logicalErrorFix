#include <bits/stdc++.h>
using namespace std;
const int N = 10000010;
long long a[N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    long long t = 0;
    long long res = a[1];
    for (int i = 1; i <= n; i++) {
      a[i] -= t;
      res = max(res, a[i]);
      t += a[i];
    }
    cout << res << endl;
  }
  return 0;
}
