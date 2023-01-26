#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n], ind;
    long long mx = -3000000;
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      if (a[i] > mx) mx = max(mx, a[i]);
      ind = i;
    }
    double m = (long long)mx;
    cout << mx << ' ' << sum << endl;
    double ez = (sum - m) / (n - 1);
    cout << ez << endl;
    double z = m + ez;
    printf("%.9lf", z);
  }
  return 0;
}
