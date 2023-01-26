#include <bits/stdc++.h>
using namespace std;
void fio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  if (a == 0) return b;
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
int main() {
  fio();
  int t;
  cin >> t;
  while (t--) {
    long long int x, y;
    cin >> x >> y;
    if (x > y) {
      cout << x + y << "\n";
    } else if (x == y) {
      cout << x << "\n";
    } else {
      if (y % x == 0) {
        cout << x << "\n";
        continue;
      }
      long long int d = y % x;
      long long int u = y - d;
      u = u + d / 2;
      cout << u << "\n";
    }
  }
  return 0;
}
