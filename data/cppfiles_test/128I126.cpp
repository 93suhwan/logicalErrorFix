#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int inf = 1e9;
const long long mod = 1e9 + 7;
const int N = 1e6 + 8;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    int t1 = 1;
    int t2 = n - 1;
    if (t2 % 2 != 0) {
      int p1 = t2 / 2, p2 = t2 - p1;
      cout << p1 << " " << p2 << " " << 1 << '\n';
      continue;
    }
    bool f = 0;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        int v = n / i - 1, a1, a2;
        if (v % 2 == 0) {
          a1 = v / 2 + 1, a2 = v - a1;
        } else {
          a1 = v / 2, a2 = v - a1;
        }
        a1 *= i, a2 *= i;
        int a3 = i;
        if (a1 == a2 || a2 == a3 || a3 == a1) continue;
        if (gcd(a1, a2) != i) continue;
        cout << a1 << " " << a2 << " " << i << '\n';
        f = 1;
        break;
      }
    }
    if (f) continue;
    int a1 = 1;
    int a2 = (n - 1) / 2 - 1, a3 = (n - 1) / 2 + 1;
    cout << a2 << " " << a3 << " " << a1 << '\n';
  }
}
