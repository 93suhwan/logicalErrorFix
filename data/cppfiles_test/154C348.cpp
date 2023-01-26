#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long int p[3];
    for (int j = 0; j < 3; j++) {
      cin >> p[j];
    }
    sort(p, p + 3);
    if ((p[0] + p[1] == p[2]) || ((p[0] == p[1]) && (p[2] % 2 == 0)) ||
        ((p[1] == p[2] && (p[0] % 2 == 0))) ||
        ((p[2] == p[0]) && (p[1] % 2 == 0))) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
