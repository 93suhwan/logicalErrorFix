#include <bits/stdc++.h>
long long mypow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long mypow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
using namespace std;
int power(int x, int y) {
  int result = 1;
  while (y > 0) {
    if (y % 2 == 0) {
      x = x * x;
      y = y / 2;
    } else {
      result = result * x;
      y = y - 1;
    }
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long x1, p1;
    cin >> x1 >> p1;
    long long x2, p2;
    cin >> x2 >> p2;
    int s1 = log10(x1);
    int s2 = log10(x2);
    if (s1 + p1 > s2 + p2)
      cout << ">\n";
    else if (s1 + p1 < s2 + p2)
      cout << "<\n";
    else {
      if (x1 > x2)
        x2 = x2 * pow(10, s1 - s2);
      else
        x1 *= pow(10, s2 - s1);
      if (x1 > x2)
        cout << ">\n";
      else if (x2 > x1)
        cout << "<\n";
      else
        cout << "=\n";
    }
  }
  return 0;
}
