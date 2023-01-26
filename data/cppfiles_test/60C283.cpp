#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, y;
    cin >> n;
    vector<int> a(n);
    cin >> a[0];
    y = a[0];
    for (int i = 1; i < n; i++) {
      cin >> a[i];
      y = y & a[i];
    }
    cout << y << endl;
  }
  return 0;
}
