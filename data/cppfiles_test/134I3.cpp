#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  for (auto &i : arr) cin >> i;
  long long int a = arr[1], b = arr[0];
  for (long long int i = 0; i < n; i++) {
    if (i % 2) {
      a = gcd(a, arr[i]);
    } else
      b = gcd(b, arr[i]);
  }
  if (a == b) {
    cout << 0 << '\n';
  } else if (a < b) {
    bool flag = true;
    for (long long int i = 1; i < n; i += 2) {
      if (arr[i] % b == 0) {
        flag = false;
        break;
      }
    }
    if (flag)
      cout << b << endl;
    else
      cout << 0 << endl;
  } else {
    bool flag = true;
    for (long long int i = 0; i < n; i += 2) {
      if (arr[i] % a == 0) {
        flag = false;
        break;
      }
    }
    if (flag)
      cout << a << endl;
    else
      cout << 0 << endl;
  }
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  long long int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
