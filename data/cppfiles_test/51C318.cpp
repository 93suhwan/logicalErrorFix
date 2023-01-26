#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    int i = 0;
    long long int o = 2;
    long long int A;
    while (i >= 0) {
      if (n % 2 == 1) {
        A = n;
        i = -1;
        break;
      } else {
        n = n / 2;
        o = o * 2;
      }
    }
    o = o - 1;
    cout << "" << (((A - o) / 2)) << " " << ((A + o) / 2) << endl;
  }
  return 0;
}
