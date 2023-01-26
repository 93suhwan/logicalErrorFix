#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, diff, x;
  cin >> t;
  while (t--) {
    diff = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      if (x - i > diff) diff = x - i;
    }
    cout << diff << endl;
  }
}
