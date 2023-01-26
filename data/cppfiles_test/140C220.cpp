#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, temp, ans = 0;
    cin >> n;
    ans += (long long int)sqrt(n);
    temp = (long long int)cbrt(n);
    ans += temp;
    ans -= (long long int)sqrt(temp);
    cout << ans << "\n";
  }
}
