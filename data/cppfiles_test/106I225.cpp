#include <bits/stdc++.h>
using namespace std;
int n, a[100001];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i + 1; j++) {
        cout << "1";
      }
      cout << " ";
    }
    cout << endl;
  }
  return 0;
}
