#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n, a[100005];
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    for (long long i = 1; i < n; i++) {
      long long t = a[i] * a[i + 1];
      ans = max(ans, t);
    }
    cout << ans << endl;
  }
  return 0;
}
