#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long p, a, b;
    cin >> p;
    p--;
    int f = 0;
    for (long long i = 2; i <= p; i++) {
      if (p % i == 0) {
        if (f == 0) {
          a = i;
          break;
        }
      }
    }
    b = p / a;
    cout << a << " " << b << endl;
  }
}
