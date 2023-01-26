#include <bits/stdc++.h>
using namespace std;
long long t;
long long n;
long long tmp;
long long gcd(long long a, long long b) {
  long long temp;
  if (a < b) {
    temp = a;
    a = b;
    b = temp;
  }
  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}
long long lcm(long long a, long long b) {
  long long temp_lcm;
  temp_lcm = a * b / gcd(a, b);
  return temp_lcm;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 2 == 0) {
      long long a, b;
      tmp = n / 2;
      while (tmp--) {
        cin >> a >> b;
        cout << b << ' ' << -a << ' ';
      }
      cout << endl;
    } else {
      long long a, b, c;
      tmp = (n - 2) / 2;
      while (tmp--) {
        cin >> a >> b;
        cout << b << ' ' << -a << ' ';
      }
      cin >> a >> b >> c;
      tmp = lcm(a, b);
      tmp = lcm(tmp, c);
      cout << tmp / a << ' ' << tmp / b << ' ' << -2 * tmp / c;
      cout << endl;
    }
  }
  return 0;
}
