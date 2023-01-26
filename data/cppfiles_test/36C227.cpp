#include <bits/stdc++.h>
using namespace std;
long long INF = 2000000007;
long long INFLL = (long long)INF * (long long)INF;
long double EPS = 10e-7;
long double pi = 2 * acos(0.0);
bool isprime(long long n) {
  for (long long i = 2; i < n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
void solve(long long tc) {
  long long n;
  cin >> n;
  long long a[n];
  long long sum = 0;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (isprime(sum)) {
    cout << n - 1 << endl;
    for (long long i = 0; i < n; ++i) {
      if (isprime(sum - a[i]) == 0) {
        for (long long j = 0; j < n; ++j) {
          if (j == i) continue;
          cout << j + 1 << " ";
        }
        cout << endl;
        return;
      }
    }
  } else {
    cout << n << endl;
    for (long long i = 0; i < n; ++i) {
      cout << i + 1 << " ";
    }
    cout << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  cin >> tc;
  for (long long i = 1; i <= tc; i++) {
    solve(i);
  }
  return 0;
}
