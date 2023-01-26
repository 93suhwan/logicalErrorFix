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
  long long g1 = a[0], g2 = a[1];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2) {
      g1 = gcd(a[i], g1);
    } else {
      g2 = gcd(a[i], g2);
    }
  }
  if (n == 2) {
    if (a[0] == a[1])
      cout << 0 << endl;
    else
      cout << max(a[0], a[1]) << endl;
    return;
  }
  long long t1 = 0, t2 = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 2) {
      if (a[i] % g2 == 0) {
        t1 = 1;
      }
    } else {
      if (a[i] % g1 == 0) {
        t2 = 1;
      }
    }
  }
  if (t1 == 0) {
    cout << g2 << endl;
  } else if (t2 == 0) {
    cout << g1 << endl;
  } else if (g1 == 1 && g2 == 1) {
    cout << 0 << endl;
  } else {
    cout << 0 << endl;
  }
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
