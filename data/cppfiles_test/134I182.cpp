#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long MOD = (long long)1e9 + 7LL;
const int MAXN = (int)1e2 + 5;
int a[MAXN];
long long GCD(long long a, long long b) {
  while (a != 0 && b != 0) {
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
  long long ans = 0;
  if (gcd1 > gcd2) {
    ans = gcd1;
    for (int i = 1; i < n; i += 2) {
      if (a[i] % ans == 0) {
        cout << 0 << endl;
        return;
      }
    }
  } else if (gcd1 < gcd2) {
    ans = gcd2;
    for (int i = 0; i < n; i += 2) {
      if (a[i] % ans == 0) {
        cout << 0 << endl;
        return;
      }
    }
  } else {
    cout << 0 << endl;
    return;
  }
  cout << ans << endl;
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
