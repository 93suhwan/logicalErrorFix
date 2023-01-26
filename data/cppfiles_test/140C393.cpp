#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long int n;
    cin >> n;
    int ans = 0;
    ans += sqrt(n);
    ans += cbrt(n);
    ans -= (int)sqrt(cbrt(n));
    cout << ans << endl;
  }
  return 0;
}
