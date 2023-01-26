#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 2) {
      n += 1;
    }
    n /= 2;
    long long ans = 0;
    if (n % 5 == 0) {
      ans = n / 5 * 25;
      n = 0;
    }
    if (n % 4 == 0) {
      ans = n / 4 * 20;
      n = 0;
    }
    if (n % 3 == 0) {
      ans = n / 3 * 15;
      n = 0;
    }
    ans += (n / 5) * 25;
    n = n % 5;
    ans += (n / 4) * 20;
    n = n % 4;
    ans += (n / 3) * 15;
    n = n % 3;
    if (n > 0) {
      ans += 15;
    }
    cout << ans << endl;
  }
}
