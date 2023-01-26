#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  long long tc;
  cin >> tc;
  while (tc-- > 0) {
    long long n, sum, m;
    cin >> n;
    sum = 0;
    vector<long long> a(n);
    for (long long &i : a) {
      cin >> i;
      sum += i;
    }
    m = a[0];
    for (long long i = 1; i < n; i++) {
      m = max(m, a[i]);
    }
    double s;
    s = m + (double)(sum - m) / (n - 1);
    printf("%.9lf\n", s);
  }
  return 0;
}
