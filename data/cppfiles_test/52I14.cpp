#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n;
  cin >> t;
  while (t--) {
    double m = -10000000000;
    cin >> n;
    double ara[n], ara1[n];
    for (long long int i = 0; i < n; i++) {
      cin >> ara[i];
    }
    sort(ara, ara + n);
    ara1[0] = ara[0];
    for (long long int i = 1; i < n; i++) {
      ara1[i] = ara[i] + ara1[i - 1];
    }
    for (long long int i = n - 1; i > 0; i--) {
      double x =
          (ara1[i - 1] / (double)i + (ara1[i] - ara1[i - 1]) / (double)(n - i));
      m = max(x, m);
    }
    cout << m << endl;
  }
}
