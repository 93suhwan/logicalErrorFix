#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i;
  cin >> t;
  for (i = 0; i < t; i++) {
    long long int n;
    cin >> n;
    if (n == 1) {
      cout << 0 << 1;
    } else {
      long long int a = -(n - 1);
      cout << a << n;
    }
  }
  return 0;
}
