#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long int n, f = 1, a;
    cin >> n;
    n = 2 * n;
    while (n > 0) {
      if (n == 2) n = n / 2;
      f = (n * f) % 1000000007;
      n = n - 1;
    }
    a = f;
    cout << a << endl;
  }
}
