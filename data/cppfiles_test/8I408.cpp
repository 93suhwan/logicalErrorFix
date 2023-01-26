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
    if (d % 2 == 0) {
      d = d / 2;
    }
    cout << d + e << " " << e << endl;
  }
  return 0;
}
