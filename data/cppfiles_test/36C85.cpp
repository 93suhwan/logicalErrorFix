#include <bits/stdc++.h>
using namespace std;
long long a[110];
long long n;
bool che(long long x) {
  for (long long i = 2; i < x; i++) {
    if (x % i == 0) return true;
  }
  return false;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    bool flag = false;
    for (long long i = 2; i < sum; i++) {
      if (sum % i == 0) flag = true;
    }
    if (flag) {
      cout << n << '\n';
      for (long long i = 1; i <= n; i++) cout << i << " ";
      cout << '\n';
      continue;
    }
    long long pos = 0;
    a[0] = INT_MAX;
    for (long long i = 1; i <= n; i++) {
      if (che(sum - a[i])) {
        if (a[pos] > a[i]) pos = i;
      }
    }
    cout << n - 1 << '\n';
    for (long long i = 1; i <= n; i++) {
      if (i == pos) continue;
      cout << i << " ";
    }
    cout << '\n';
  }
}
