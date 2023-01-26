#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    n = n + n * 666 / 1000;
    cout << n << endl;
  }
  return 0;
}
