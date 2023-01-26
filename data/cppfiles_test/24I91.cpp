#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, ans;
    cin >> n;
    if (n < 9)
      ans = 0;
    else if (n == 9)
      ans = 1;
    else
      ans = floor(n / 10);
    cout << ans << endl;
  }
  return 0;
}
