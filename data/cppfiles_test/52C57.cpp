#include <bits/stdc++.h>
int has[1000000], cnt = 0;
using namespace std;
int main() {
  long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long double sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a, a + n);
    sum -= a[n - 1];
    sum /= n - 1;
    sum += a[n - 1];
    cout << fixed << setprecision(9) << sum << endl;
  }
}
