#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n % 3 == 1 || n % 3 == 0) {
      long long int rev = n / 3;
      long long int ans = rev + (n % 3);
      cout << ans << " " << rev << endl;
    } else if (n % 3 == 2) {
      long long int rev = n / 3;
      cout << rev << " " << rev + 1 << endl;
    }
  }
  return 0;
}
