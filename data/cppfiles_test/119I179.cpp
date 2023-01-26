#include <bits/stdc++.h>
using namespace std;
int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    int n;
    cin >> n;
    int a, sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a;
      sum += a;
    }
    cout << sum % 2 << "\n";
  }
  return 0;
}
