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
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long x1, p1;
    cin >> x1 >> p1;
    long long x2, p2;
    cin >> x2 >> p2;
    long long a = x1 * pow(10, p1);
    long long b = x2 * pow(10, p2);
    if (a > b)
      cout << ">" << endl;
    else if (a < b)
      cout << "<" << endl;
    else
      cout << "=" << endl;
  }
  return 0;
}
