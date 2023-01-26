#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char arr[2][n];
    bool possible = true;
    for (int i = 0; i < n; i++) cin >> arr[0][i];
    for (int i = 0; i < n; i++) {
      cin >> arr[1][i];
      if (arr[0][i] == arr[1][i] && arr[0][i] == '1') {
        possible = false;
        break;
      }
    }
    if (possible)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
