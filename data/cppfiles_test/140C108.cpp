#include <bits/stdc++.h>
using namespace std;
long long n;
bool check6(long long no) { return pow(no, 6) <= n; }
int main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    long long s = 1;
    long long e = 1e18;
    while (s != e - 1) {
      long long m = (s + e) / 2;
      if (check6(m))
        s = m;
      else
        e = m;
    }
    cout << floor(sqrt(n)) + floor(cbrt(n)) - s << endl;
  }
  return 0;
}
