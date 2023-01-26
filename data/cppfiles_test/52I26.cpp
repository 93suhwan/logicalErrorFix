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
    long long mx = -300000000;
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      if (a[i] > mx) mx = max(mx, a[i]);
      ind = i;
    }
    double m = (long long)mx;
    double ez = m + ((sum - m) / (n - 1));
    cout << ez << endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(9) << ez << '\n';
  }
  return 0;
}
