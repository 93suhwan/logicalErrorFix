#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long x, n;
    cin >> x >> n;
    if (x % 2 == 0) {
      x -= n;
    } else {
      x += n;
    }
    cout << x << endl;
  }
  return 0;
}
