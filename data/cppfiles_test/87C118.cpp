#include <bits/stdc++.h>
using namespace std;
long long t, n, a[400];
int main() {
  std::ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    long long pos = 0, cnt = 0;
    for (long long i = 1; i <= n; i++) {
      pos++;
      if (a[i] <= pos)
        continue;
      else {
        cnt += a[i] - pos;
        pos += a[i] - pos;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
