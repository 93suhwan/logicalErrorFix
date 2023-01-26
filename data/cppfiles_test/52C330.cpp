#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long double n, i, j, k, l, m, b, t, sum, sum1, flag, min1, tmp, max1;
  cin >> t;
  while (t--) {
    cin >> n;
    sum = 0.0;
    sum1 = 0.0;
    max1 = -1e12;
    min1 = 1e12;
    map<long long, long long> mp;
    set<long long> s;
    for (i = 1; i <= n; i++) {
      cin >> j;
      max1 = max(max1, j);
      sum += j;
    }
    sum -= max1;
    sum /= (n - 1);
    sum += max1;
    cout.precision(11);
    cout << sum << endl;
  }
}
