#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i = 2;
    for (int i = 0; i < n; i++) {
      cout << i << ' ';
      i++;
    }
    cout << endl;
  }
  return 0;
}
