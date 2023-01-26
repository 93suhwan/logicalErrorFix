#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
long long a[N], s[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, h;
    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2, j = 1; i <= n; i++, j++) {
      s[j] = a[i] - a[i - 1];
    }
    long long minn;
    while (1) {
      int bo = 1;
      if (h % n == 0)
        minn = h / n;
      else
        minn = h / n + 1;
      for (int i = 1; i < n; i++) {
        if (s[i] < minn && s[i] != 0) {
          h -= s[i];
          s[i] = 0;
          n--;
          bo = 0;
        }
      }
      cout << h << ' ' << n << endl;
      if (bo == 1) {
        cout << minn << endl;
        break;
      }
    }
  }
  return 0;
}
