#include <bits/stdc++.h>
using namespace std;
int gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long n, k;
  string s;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long g1 = a[0], g2 = a[1];
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0) {
      g1 = gcd(a[i], g1);
    } else {
      g2 = gcd(a[i], g2);
    }
  }
  if (g1 == g2 && g1 == 1) {
    cout << 0 << endl;
    return;
  }
  long long p = 0, q = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (a[i] % g2 == 0) {
        p = 1;
      }
    } else {
      if (a[i] % g1 == 0) {
        q = 1;
      }
    }
  }
  if (p == 0) {
    cout << g2 << endl;
    return;
  }
  if (q == 0) {
    cout << g1 << endl;
    return;
  }
  cout << 0 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  cin >> TESTS;
  while (TESTS--) {
    solve();
  }
  return 0;
}
