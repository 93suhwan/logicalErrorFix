#include <bits/stdc++.h>
using namespace std;
int t, n;
int x;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> x;
    for (int i = 1; i < n; i++) {
      int cc;
      cin >> cc;
      x = x & cc;
    }
    cout << x << endl;
  }
}
