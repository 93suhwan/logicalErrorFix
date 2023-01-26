#include <bits/stdc++.h>
using namespace std;
long long int power(int x, int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x1, x2, p1, p2;
    cin >> x1 >> p1;
    cin >> x2 >> p2;
    long long int power1 = power(10, p1);
    long long int power2 = power(10, p2);
    long long int n1 = x1 * power1;
    long long int n2 = x2 * power2;
    if (n1 < n2)
      cout << "<" << endl;
    else if (n1 > n2)
      cout << ">" << endl;
    else if (n1 == n2)
      cout << "=" << endl;
  }
}
