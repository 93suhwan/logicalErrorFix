#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long x = a[0];
    for (long long i = 0; i < n; i++) {
      x = x & a[i];
    }
    cout << x << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  solve();
  cout << fixed;
  return 0;
}
