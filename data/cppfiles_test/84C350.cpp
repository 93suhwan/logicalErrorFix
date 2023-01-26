#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    if (n == 1 && s == 1) {
      cout << "1" << endl;
    } else if (n == 1 && s > 1) {
      cout << s << endl;
    } else if (n > 1 && s == 1) {
      cout << "0" << endl;
    } else {
      long long ans = 0;
      long long m = n / 2 + 1;
      ans = s / m;
      cout << ans << endl;
    }
  }
  return 0;
}
