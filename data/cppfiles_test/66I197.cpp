#include <bits/stdc++.h>
using namespace std;
int main() {
  double t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    n = n + n / 100 * 66;
    cout << n;
  }
  return 0;
}
