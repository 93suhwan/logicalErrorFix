#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[n], sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % n == 0)
      cout << '0' << '\n';
    else
      cout << '1' << '\n';
    sum = 0;
  }
  return 0;
}
