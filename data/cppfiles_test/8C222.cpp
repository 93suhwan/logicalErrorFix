#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int d = n % 3;
    int e = n / 3;
    if (d == 0) {
      cout << e << " " << e << endl;
    } else if (d == 1) {
      cout << e + 1 << " " << e << endl;
    } else {
      cout << e << " " << e + 1 << endl;
    }
  }
  return 0;
}
