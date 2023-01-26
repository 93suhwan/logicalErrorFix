#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int i, a, b, c;
    if ((n - 1) & 1) {
      cout << (n - 1) / 2 << " " << ((n - 1) / 2) + 1 << " " << 1 << endl;
    } else {
      c = 1;
      n--;
      long long int k = (n / 2);
      if (k % 2 == 0) {
        a = k - 1;
        b = k + 1;
      } else {
        a = k - 2;
        b = k + 2;
      }
      cout << a << " " << b << " " << c << endl;
    }
  }
}
