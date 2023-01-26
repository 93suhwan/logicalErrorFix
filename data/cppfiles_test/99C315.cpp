#include <bits/stdc++.h>
using namespace std;
void actionFun() {
  long long k, n, ans;
  cin >> k >> n;
  if (n == 0)
    ans = k;
  else {
    long long on = n;
    if (k % 2)
      ans = k + 1;
    else
      ans = k - 1;
    k = ans;
    n--;
    if (n == 0) {
      cout << ans << endl;
      return;
    }
    if (ans % 2 == 0) {
      if (n > 1) {
        ans -= 5;
        n -= 2;
      } else {
        ans -= 2;
        n--;
      }
    }
    if (n == 0) {
      cout << ans << endl;
      return;
    }
    if (ans % 2) {
      ans -= 4 * ((n / 2) / 2);
      if ((n / 2) % 2) {
        if (n % 2) {
          ans += (on - 1 + on - 2);
          ans -= on;
        } else {
          ans += (on + on - 1);
        }
      } else {
        if (n % 2) ans += on;
      }
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    actionFun();
  }
}
