#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, sum;
  int n;
  cin >> t;
  for (long long p = 0; p < t; p++) {
    sum = 1;
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    for (int i = 3; i <= 2 * n; i++) {
      sum *= i;
      sum = sum % 1000000007;
    }
    cout << sum << endl;
    ;
  }
  return 0;
}
