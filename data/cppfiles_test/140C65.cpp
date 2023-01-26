#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 1) {
      cout << n << endl;
      continue;
    }
    long long ans = 0;
    ans += (long long)sqrt(n);
    ans += (long long)(cbrt(n));
    ans -= (long long)(sqrt((cbrt(n))));
    cout << ans << endl;
  }
  return 0;
}
