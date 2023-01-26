#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long c = 0, ans = 0;
  long long f = 0;
  while (1) {
    for (long long i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        swap(a[i], a[i + 1]);
        c++;
        i++;
      }
    }
    if (c == 0) {
      break;
    }
    ans++;
    c = 0;
    f = 0;
  }
  if (ans == 0) {
    cout << ans << endl;
  } else {
    cout << ans << endl;
  }
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
