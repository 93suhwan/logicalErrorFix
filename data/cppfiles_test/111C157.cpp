#include <bits/stdc++.h>
using namespace std;
long long pow(long long x, long long p) {
  long long ctr = 1;
  for (long long i = 0; i < p; i++) {
    ctr *= x;
  }
  return ctr;
}
void f() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= i; j++) cout << '(';
    for (long long j = 1; j <= i; j++) cout << ')';
    for (long long j = 1; j <= n - i; j++) cout << "()";
    cout << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    f();
  }
}
