#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) cout << "(";
      for (int j = 1; j <= i; j++) cout << ")";
      for (int j = i + 1; j <= n; j++) cout << "(";
      for (int j = i + 1; j <= n; j++) cout << ")";
      cout << endl;
    }
  }
  return 0;
}
