#include <bits/stdc++.h>
using namespace std;
const int M = 1000000000 + 7;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int f = 1;
    if (n == 1) {
      cout << 1 << endl;
    } else {
      for (int i = 3; i <= 2 * n; i++) {
        f = (f * i) % M;
      }
      cout << f << endl;
    }
  }
}
