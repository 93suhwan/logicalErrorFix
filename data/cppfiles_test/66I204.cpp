#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    n = n + n / 1000 * 666;
    cout << n;
  }
  return 0;
}
