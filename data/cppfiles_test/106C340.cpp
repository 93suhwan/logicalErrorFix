#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    for (int ii = 3; ii <= n + 2; ii++) {
      cout << ii << ' ';
    }
    cout << endl;
  }
  return 0;
}
