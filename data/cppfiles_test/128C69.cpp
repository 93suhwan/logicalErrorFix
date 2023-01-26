#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int TESTCASE;
  cin >> TESTCASE;
  while (TESTCASE--) {
    long long int n;
    cin >> n;
    n--;
    long long int a = 2, b = n - 2, c = 1;
    while (1) {
      if (gcd(a, b) == 1) {
        break;
      } else
        a++, b--;
    }
    cout << a << " " << b << " " << c << "\n";
  }
  return 0;
}
