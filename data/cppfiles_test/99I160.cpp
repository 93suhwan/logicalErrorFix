#include <bits/stdc++.h>
using namespace std;
int main() {
  int cases = 1;
  cin >> cases;
  while (cases--) {
    long long int x, n;
    cin >> x >> n;
    if (n == 0) {
      cout << x << endl;
      continue;
    }
    long long int ans = 0;
    long long int f = n % 4;
    if (f == 0) {
      cout << x << endl;
    } else if (f == 1) {
      if (x % 2 == 0) {
        ans -= n;
      } else {
        ans += n;
      }
    } else if (f == 2) {
      if (x % 2 == 0) {
        ans++;
      } else {
        ans--;
      }
    } else {
      if (x % 2 == 0) {
        ans += (n + 1);
      } else {
        ans -= (n + 1);
      }
    }
    cout << ans + x << endl;
  }
  return 0;
}
