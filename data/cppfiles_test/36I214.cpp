#include <bits/stdc++.h>
using namespace std;
long long prime(long long p) {
  if (p <= 1) {
    return 0;
  } else if (p == 2) {
    return 1;
  } else if (p % 2 == 0) {
    return 0;
  } else {
    long long x = 0;
    for (long long i = 3; i < sqrt(p); i += 2) {
      if (p % i == 0) {
        x = 1;
        return 0;
      }
    }
    if (x == 0) {
      return 1;
    }
  }
}
void algo() {
  long long n = 0;
  cin >> n;
  vector<long long> v(n, 0);
  long long sum = 0;
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
    sum += v[i];
  }
  if (!prime(sum)) {
    cout << n << endl;
    for (long long j = 0; j < n; ++j) {
      cout << j + 1 << " ";
    }
  } else {
    for (long long j = 0; j < n; ++j) {
      if (v[j] % 2 != 0) {
        cout << n - 1 << endl;
        for (long long k = 0; k < n; ++k) {
          if (k != j) {
            cout << k + 1 << " ";
          }
        }
        break;
      }
    }
  }
  cout << endl;
}
signed main() {
  long long t = 0;
  cin >> t;
  while (t--) {
    algo();
  }
  return 0;
}
