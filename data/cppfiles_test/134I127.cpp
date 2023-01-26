#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
const long long remi = 998244353;
using namespace std;
const long long N = 1e5 + 10;
void Sun_god() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  if (n == 1) {
    cout << v[0] << "\n";
    return;
  }
  if (v[0] == v[1]) {
    cout << "0"
         << "\n";
    return;
  }
  long long a = v[0];
  bool flag2 = 0;
  for (long long i = 1; i < n; i++) {
    if (i % 2 == 0 && v[i] % a != 0) {
      flag2 = 1;
      break;
    } else if (i % 2 != 0 && v[i] % a == 0) {
      flag2 = 1;
      break;
    }
  }
  long long b = v[1];
  bool flag22 = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0 && v[i] % b == 0) {
      flag22 = 1;
      break;
    } else if (i % 2 != 0 && v[i] % b != 0) {
      flag22 = 1;
      break;
    }
  }
  if (flag2 == 0) {
    cout << a << "\n";
  } else if (flag22 == 0) {
    cout << b << "\n";
  } else {
    cout << 0 << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    Sun_god();
  }
  return 0;
}
