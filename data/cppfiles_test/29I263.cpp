#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  for (long long int k = 1; k <= t; k++) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int ans;
    long long int sum = a + 2 * b + 3 * c;
    if (sum % 2)
      ans = 1;
    else
      ans = 0;
    cout << ans << "\n";
  }
  return 0;
}
