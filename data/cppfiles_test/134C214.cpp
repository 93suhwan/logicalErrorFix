#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long MOD = (long long)1e9 + 7LL;
const int MAXN = (int)1e2 + 5;
long long a[MAXN];
long long GCD(long long a, long long b) {
  while (b != 0) {
    long long tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}
void Solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long gcd1 = a[0], gcd2 = a[1];
  for (int i = 2; i < n; i += 2) {
    gcd1 = GCD(gcd1, a[i]);
  }
  for (int i = 3; i < n; i += 2) {
    gcd2 = GCD(gcd2, a[i]);
  }
  bool tag = true;
  for (int i = 0; i < n; i += 2) {
    if (a[i] % gcd2 == 0) {
      tag = false;
      break;
    }
  }
  if (tag) {
    cout << gcd2 << endl;
    return;
  }
  tag = true;
  for (int i = 1; i < n; i += 2) {
    if (a[i] % gcd1 == 0) {
      cout << 0 << endl;
      return;
    }
  }
  cout << gcd1 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}
