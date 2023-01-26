#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int s, c, b;
    s = floor(sqrt(n));
    c = floor(cbrt(n));
    b = floor(cbrt(sqrt(n)));
    cout << (s + c - b) << endl;
  }
  return 0;
}
