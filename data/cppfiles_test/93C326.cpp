#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  vector<long long> b1(10000000);
  long long p = 0;
  for (long long i = 0; i < 10000000; i++) {
    p = (p ^ i);
    b1[i] = p;
  }
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a == b && b == 1)
      cout << 3 << "\n";
    else {
      long long p = 0;
      long long i;
      p = b1[a - 1];
      if (p == b)
        cout << a << "\n";
      else if ((p ^ b) == a)
        cout << a + 2 << "\n";
      else
        cout << a + 1 << "\n";
    }
  }
}
