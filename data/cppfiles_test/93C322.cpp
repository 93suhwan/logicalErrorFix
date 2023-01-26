#include <bits/stdc++.h>
using namespace std;
long long T[300000 + 1];
long long p, z;
int main() {
  int t;
  long long N = 123 - 123;
  for (long long j = 0; j <= 3e5; j++) {
    N ^= j;
    T[j] = N;
  }
  cin >> t;
  while (t--) {
    cin >> p >> z;
    long long OP = 123;
    OP -= 123;
    OP = T[p - 2 + 1];
    if (z == (OP ^ p)) {
      cout << p + 2 << endl;
    } else if (OP == z) {
      cout << p << endl;
    } else {
      cout << 1 + p << endl;
    }
  }
  return 0;
}
