#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << b / ((a / 2) + 1) << endl;
  }
  return 0;
}
