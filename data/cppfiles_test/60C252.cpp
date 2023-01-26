#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x, y;
    cin >> x;
    int ans;
    n--;
    while (n--) {
      cin >> y;
      x = x & y;
    }
    cout << x << '\n';
  }
  return 0;
}
