#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, n1, n2, n3 = 1;
    cin >> n;
    if (n == 1) {
      n1 = 1;
      n2 = 0;
    } else if (n == 2) {
      n2 = 1;
      n1 = 0;
    } else if (n < 10) {
      n2 = n / 3;
      n1 = n % 3;
    } else {
      if (n % 3 == 0)
        n1 = n / 3;
      else
        n1 = n / 3 + 1;
      n2 = (n - n1) / 2;
    }
    cout << n1 << " " << n2 << endl;
  }
  return 0;
}
