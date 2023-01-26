#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, sum = 0;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    sum = (a * 1) + (b * 2) + (c * 3);
    cout << (sum % 2) << '\n';
  }
}
