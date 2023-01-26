#include <bits/stdc++.h>
using namespace std;
int main() {
  int w = 0;
  cin >> w;
  for (int i = 0; i < w; i++) {
    long long int n, m;
    cin >> n >> m;
    long long int sum = n + m;
    if (n == m && n == 0) {
      cout << 0 << endl;
    } else if (n == m) {
      cout << 1 << endl;
    } else if (sum % 2 == 0) {
      cout << 2 << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
