#include <bits/stdc++.h>
const double PI = 3.141592653589793238460;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n], i, sum = 0, maxi = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    for (i = 0; i < n - 1; i++) {
      long long int pro = a[i] * a[i + 1];
      if (pro > sum) {
        sum = pro;
      }
    }
    cout << sum << '\n';
  }
  return 0;
}
