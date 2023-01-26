#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int t = 2;
    for (int i = 1; i < n; i++) {
      cout << t << " ";
      t += 1;
    }
    cout << t;
  }
  return 0;
}
