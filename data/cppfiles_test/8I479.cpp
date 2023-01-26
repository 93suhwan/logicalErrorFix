#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int c1 = 0, c2 = 0;
    while (n > 0) {
      c1++;
      n = n - 1;
      if (n > 0) {
        c2++;
        n = n - 2;
      }
    }
    cout << c1 << " " << c2 << endl;
  }
  return 0;
}
