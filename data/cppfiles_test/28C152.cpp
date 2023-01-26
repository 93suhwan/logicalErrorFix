#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long sum = a + (b * 2) + (c * 3);
    cout << (sum % 2) << " \n";
  }
}
