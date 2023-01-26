#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << (int)sqrt(n) + (int)cbrt(n) - (int)cbrt(sqrt(n)) << endl;
  }
  return 0;
}
