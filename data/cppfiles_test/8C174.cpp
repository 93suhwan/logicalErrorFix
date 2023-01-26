#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x;
    cin >> x;
    long long int r = x / 3;
    long long int r2 = r;
    if (x % 3 == 1) r++;
    if (x % 3 == 2) r2++;
    cout << r << " " << r2 << endl;
  }
  return 0;
}
