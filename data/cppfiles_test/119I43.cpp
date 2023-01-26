#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x, s = (s + x) % 2;
    cout << s << endl;
  }
  return 0;
}
