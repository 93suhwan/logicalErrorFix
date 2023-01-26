#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, n = 0;
    cin >> n;
    if (n % 2 == 0) {
      a = 2, b = n - 3;
      c = gcd(2, n - 3);
    } else {
      b = n - 1;
      for (int i = 3; i < b; i += 2) {
        b = n - 1 - i;
        c = gcd(i, b);
        if (c == 1) {
          a = i;
          break;
        }
      }
    }
    cout << a << " " << b << " " << c << endl;
  }
  return 0;
}
