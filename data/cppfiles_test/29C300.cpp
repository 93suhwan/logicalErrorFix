#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  for (long long int k = 1; k <= t; k++) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int one = 0, zero = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1)
        one++;
      else if (a[i] == 0)
        zero++;
    }
    long long int ans = one * (pow(2, zero));
    cout << ans << "\n";
  }
  return 0;
}
