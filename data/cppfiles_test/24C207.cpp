#include <bits/stdc++.h>
using namespace std;
long long n, ans, tst;
int main() {
  cin >> tst;
  while (tst--) {
    cin >> n;
    ans = n / 10;
    if (n % 10 == 9) ans++;
    cout << ans << endl;
  }
  return 0;
}
