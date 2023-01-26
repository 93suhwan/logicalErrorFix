#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    long long int x, n, sum;
    cin >> x >> n;
    long long int ab = n % 4;
    sum = x;
    for (long long int j = (n - ab) + 1; j <= n; j++) {
      if (sum % 2 == 0)
        sum = sum - j;
      else
        sum = sum + j;
    }
    cout << sum << endl;
  }
  return 0;
}
