#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int len = 2 * (abs(b - a));
    int ans = 0;
    if (a > len || b > len || c > len)
      ans = -1;
    else {
      ans = c + (len / 2);
      if (ans > len) ans = c - len / 2;
    }
    cout << ans << endl;
  }
  return 0;
}
